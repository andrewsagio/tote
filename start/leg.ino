#include "misc.h"
#include "leg.h"

const unsigned char LEG_JOINT[4][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {9, 10, 11},
};

float leg_position[4][3] = {
    {HOME, LEG_Y[0] * HOME, -TIBIA},
    {HOME, LEG_Y[0] * HOME, -TIBIA},
    {HOME, LEG_Y[0] * HOME, -TIBIA},
    {HOME, LEG_Y[0] * HOME, -TIBIA},
};


float _solve_triangle(float a, float b, float c) {
    // Calculate the angle between a and b, opposite to c.
    a = max(a, -a);
    b = max(b, -b);
    c = max(c, -c);
    if (a + b < c || a + c < b || b + c < a) { return NAN; }
    return acosf((a * a + b * b - c * c) / (2 * a * b));
}

float _norm(float a, float b) {
    // Calculate the norm of a vector.
    Serial.println("_norm()");
    Serial.print("a = ");
    Serial.println(a);
    Serial.print("b = ");
    Serial.println(b);
    float result = sqrtf(a * a + b * b);
    Serial.print("result = ");
    Serial.println(result);
    return result;
}

bool _inverse_kinematics(float x, float y, float z,
                         float *ankle, float *knee, float *hip) {
    // Calculate angles for knee and ankle, and put them in those variables.
    // Return true on success, and false if x and y are out of range.

    Serial.println("_inverse_kinematics()");
    Serial.print("COXA = ");
    Serial.println(COXA);
    Serial.print("FEMUR = ");
    Serial.println(FEMUR);
    Serial.print("TIBIA = ");
    Serial.println(TIBIA);

    float f = _norm(x, y) - COXA;
    float d = _norm(f, z);

    Serial.print("f = ");
    Serial.println(f);
    Serial.print("d = ");
    Serial.println(d);

    if (d > FEMUR + TIBIA) { return false; }
    *hip = atan2f(y, x) - PI4;
    if (isnan(*hip)) { return false; }
    *knee = _solve_triangle(FEMUR, d, TIBIA) - atan2f(-z, f);
    if (isnan(*knee)) { return false; }
    *ankle = _solve_triangle(FEMUR, TIBIA, d) - PI2;
    if (isnan(*ankle)) { return false; }
    return true;
}

bool move_leg(unsigned char leg, float x, float y, float z) {
    // Move the tip of the leg to x, y. Return false when out of range.
    float ankle;
    float knee;
    float hip;

    Serial.println("move_leg()");
    Serial.print("leg = ");
    Serial.println(leg);
    Serial.print("x = ");
    Serial.println(x);
    Serial.print("y = ");
    Serial.println(y);
    Serial.print("z = ");
    Serial.println(z);

    if (!_inverse_kinematics(x, y, z, &ankle, &knee, &hip)) { return false; }

    Serial.print("ankle = ");
    Serial.println(ankle);
    Serial.print("knee = ");
    Serial.println(knee);
    Serial.print("hip = ");
    Serial.println(hip);

    servo_move(LEG_JOINT[leg][0], ankle);
    servo_move(LEG_JOINT[leg][1], knee);
    servo_move(LEG_JOINT[leg][2], hip);
    leg_position[leg][0] = x;
    leg_position[leg][1] = y;
    leg_position[leg][2] = z;
    return true;
}

bool move_leg_by(unsigned char leg, float dx, float dy, float dz) {
    // Move the tip of the leg by dx, dy. Return false when out of range.
    Serial.println("move_leg_by()");
    Serial.print("dx = ");
    Serial.println(dx);
    Serial.print("dy = ");
    Serial.println(dy);
    Serial.print("dz = ");
    Serial.println(dz);
    Serial.print("leg_position[leg][0] = ");
    Serial.println(leg_position[leg][0]);
    Serial.print("leg_position[leg][1] = ");
    Serial.println(leg_position[leg][1]);
    Serial.print("leg_position[leg][2] = ");
    Serial.println(leg_position[leg][2]);
    return move_leg(leg,
                    leg_position[leg][0] + dx,
                    leg_position[leg][1] + dy,
                    leg_position[leg][2] + dz);
}

bool rotate_leg_by(unsigned char leg, float angle) {
    // Rotate the tip of the leg around the center of robot's body.
    Serial.println("rotate_leg_by()");
    Serial.print("leg = ");
    Serial.println(leg);
    Serial.print("angle = ");
    Serial.println(angle);
    Serial.print("BASE = ");
    Serial.println(BASE);
    if (angle == 0.0) { return true; }
    float x = leg_position[leg][0] + BASE;
    float y = leg_position[leg][1] + BASE;
    Serial.print("x = ");
    Serial.println(x);
    Serial.print("y = ");
    Serial.println(y);
    float nx = x * cosf(angle) - y * sinf(angle) - BASE;
    float ny = x * sinf(angle) + y * cosf(angle) - BASE;
    Serial.print("nx = ");
    Serial.println(nx);
    Serial.print("ny = ");
    Serial.println(ny);
    return move_leg(leg, nx, ny, leg_position[leg][2]);
}
