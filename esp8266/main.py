import math
import struct
import sys
import time


SQRT2 = math.sqrt(2)


def _solve_triangle(a, b, c):
    """Calculate an angle of a triangle using the law of cosines."""
    a, b, c = abs(a), abs(b), abs(c)
    if a + b < c or a + c < b or b + c < a:
        raise ValueError("Impossible triangle: %r, %r, %r" % (a, b, c))
    cos = float(a ** 2 + b ** 2 - c ** 2) / (2 * a * b)
    return math.acos(cos)


def _norm(a, b):
    """Calculate the length of a vector."""
    return math.sqrt(a ** 2 + b ** 2)


class ServoController(object):
    """Send data to the servo controller."""

    def __init__(self, serial):
        self.positions = [0] * 12
        self.serial = serial

    def start(self):
        self.serial.write(b"\xf0\xf0")
        self.serial.flush()

    def update(self):
        format = '>B' + 'h' * 12
        command = 0xff
        positions = [int(pos * 1000) for pos in self.positions]
        packet = struct.pack(format, command, *positions)
        self.serial.write(packet)
        self.serial.flush()

    def move_servo(self, servo, radians=None, degrees=None):
        if degrees is not None:
            radians = math.radians(degrees)
        if radians is not None:
            self.positions[servo] = radians


class Leg(object):
    def __init__(self, robot, index):
        self.robot = robot
        self.index = index
        self.x_dir, self.y_dir = robot.leg_order[index]
        self.home = (
            (robot.coxa + robot.femur) / SQRT2,
            -(robot.coxa + robot.femur) / SQRT2 * self.y_dir,
           -robot.tibia,
        )

    def move_to(self, position):
        self.robot.move_leg_to(self.index, position)

    def move_by(self, offset):
        self.robot.move_leg_by(self.index, offset)

    def rotate_by(self, degrees):
        self.robot.rotate_leg_by(self.index, degrees)


class Robot(object):
    base = 17.5
    coxa = 8.0
    femur = 20.5
    tibia = 24.5
    leg_order = [(1, 1), (1, -1), (-1, -1), (-1, 1)]

    def __init__(self, servos):
        self.servos = servos
        self.legs = [Leg(self, index) for index in range(4)]
        self.leg_positions = [leg.home for leg in self.legs]
        self.shift = [0, 0, 0]
        self.servos.start()

    def _inverse_kinematics(self, pos, d):
        """Calculate the 3 angles of the leg, in degrees."""
        # Micropython doesn't support tuple unpacking?
        x = pos[0]
        y = pos[1]
        z = pos[2]
        dy = d[1]
        f = _norm(x, y) - self.coxa
        d = min(self.femur + self.tibia, _norm(f, z))
        hip = math.atan2(y, x)
        knee = _solve_triangle(self.femur, d, self.tibia) - math.atan2(-z, f)
        ankle = _solve_triangle(self.femur, self.tibia, d)
        knee = -math.degrees(knee)
        ankle = math.degrees(ankle) - 90 - 45
        hip = -math.degrees(hip) - 45 * dy
        return ankle, knee, hip

    def update(self):
        for leg, position in enumerate(self.leg_positions):
            pos = [
                position[0] + self.shift[0] * self.leg_order[leg][0],
                position[1] + self.shift[1],
                position[2] + self.shift[2],
            ]
            angles = self._inverse_kinematics(pos, self.leg_order[leg])
            for joint, angle in enumerate(angles):
                self.servos.move_servo(leg * 3 + joint, degrees=angle)
        self.servos.update()

    def move_leg_to(self, leg, position):
        self.leg_positions[leg] = [
            new if new is not None else old
            for (new, old) in zip(position, self.leg_positions[leg])
        ]

    def move_leg_by(self, leg, offset):
        self.leg_positions[leg] = [
            old + d
            for (d, old) in zip(offset, self.leg_positions[leg])
        ]

    def rotate_leg_by(self, leg, degrees):
        y_dir = self.leg_order[leg][1]
        radians = math.radians(degrees)
        x, y, z = self.leg_positions[leg]
        bx, by = self.base + x, self.base - y * y_dir
        r = _norm(bx, by)
        a = math.atan2(bx, by)
        rx = r * math.sin(a + radians) - self.base
        ry = r * math.cos(a + radians) - self.base
        self.move_leg_to(leg, (rx, -ry * y_dir, None))

    @classmethod
    def make_robot(cls):
        uart = sys.stdout
        servos = ServoController(uart)
        robot = cls(servos)
        return robot


class Creep(Robot):
    step_height = -2.0  # How high to raise the legs.
    stride = 13.0  # How long steps to take.
    swing = 6, 6  # How much to shift the body x and y.
    swing_speed = 3  # How fast to shift the body.
    posture = 8, 4  # How much to change posture depending on direction.
    gaits = {
        'forward': {None: 1, 1: 0, 0: 2, 2: 3, 3: 1},
        'backward': {None: 1, 1: 3, 3: 2, 2: 0, 0: 1},
        'left': {None: 0, 0: 1, 1: 2, 2: 3, 3: 0},
        'right': {None: 0, 0: 3, 3: 2, 2: 1, 1: 0},
    }

    def __init__(self, serial):
        super(Creep, self).__init__(serial)
        self.robot = self
        self.on_ground = set([0, 1, 2, 3])
        self.speed = [0.0, 1.0]
        self.rotation = 0.0
        self.gait = 'forward'
        self.shift[2] = 5

    def _raise_leg(self, leg):
        """Raises the leg off the ground."""
        self.on_ground.remove(leg.index)
        leg.move_to((None, None, self.step_height))
        for frame in range(2):
            yield

    def _lower_leg(self, leg):
        """Puts the leg on the ground."""
        leg.move_to((None, None, leg.home[2] + 1))
        for frame in range(2):
            yield
        leg.move_to((None, None, leg.home[2]))
        self.on_ground.add(leg.index)

    def _advance_leg(self, leg):
        """Moves the leg forward."""
        leg.move_to((
            (
                leg.home[0] - self.stride * self.speed[0] * leg.x_dir -
                self.posture[0] * abs(self.speed[0])
            ),
            (
                leg.home[1] + self.stride * self.speed[1] +
                leg.y_dir * self.posture[1] * abs(self.speed[1])
            ),
            None,
        ))
        leg.rotate_by(self.rotation * leg.x_dir * leg.y_dir * 10)
        for frame in range(4):
            yield

    def _shift_body(self, shift):
        """Shifts the body to the specified position."""
        shift = list(shift)
        while self.robot.shift[:2] != shift:
            for i in range(2):
                if self.robot.shift[i] > shift[i]:
                    self.robot.shift[i] -= self.swing_speed
                elif self.robot.shift[i] < shift[i]:
                    self.robot.shift[i] += self.swing_speed
            yield

    def stomp_anim(self):
        """This animation is for making steps and shifting the body."""
        leg_index = None
        while True:
            while not self.gait:
                # Don't raise the legs if not moving.
                try:
                    yield self._shift_body((0, 0)).next()
                except StopIteration:
                    yield
            leg_index = self.gaits[self.gait][leg_index]
            leg = self.robot.legs[leg_index]
            for frame in self._shift_body((leg.x_dir * self.swing[0],
                                           -leg.y_dir * self.swing[1])):
                yield
            for frame in self._raise_leg(leg):
                yield
            for frame in self._advance_leg(leg):
                yield
            for frame in self._lower_leg(leg):
                yield

    def retract_anim(self):
        """This animation is for moving the legs on the ground.

        They should all move in the opposite direction than the speed.
        """
        while True:
            for leg_index in self.on_ground:
                leg = self.legs[leg_index]
                leg.move_by((self.speed[0] * 0.5 * leg.x_dir,
                             -self.speed[1], 0))
                if self.rotation:
                    leg.rotate_by(-self.rotation * leg.x_dir * leg.y_dir)
            yield

    def run(self):
        stomp_anim = self.stomp_anim()
        retract_anim = self.retract_anim()
        while True:
            next(stomp_anim)
            next(retract_anim)
            self.update()
            time.sleep(0.03)


if __name__ == '__main__':
    Creep.make_robot().run()
