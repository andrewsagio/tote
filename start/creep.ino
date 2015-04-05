#include "creep.h"
#include "misc.h"
#include "leg.h"
#include "clock.h"
#include "beep.h"


const unsigned int tones[4] = {880, 988, 1318, 1175};

/* Creep gait parameters. */
#ifdef TOTE2
#define SPEED 1.0
/* How far forward to move them when making a step? */
#define STRIDE 16.0
/* How much to shift the body? */
#define SHIFT 12.0
/* In how many steps should the body be shifted? */
#define STEPS 4
#else
#define SPEED 0.5
/* How far forward to move them when making a step? */
#define STRIDE 12.0
/* How much to shift the body? */
#define SHIFT 8.0
/* In how many steps should the body be shifted? */
#define STEPS 4
#endif

/* What is the home position of the legs? */
#define HOME ((COXA + FEMUR) / SQRT2)

/* Given current leg, which leg to move next? */
const unsigned char _NEXT_LEG[4] = {2, 0, 3, 1};

/* Body position. */
static double _shift_x = 0.0;
static double _shift_y = 0.0;

/* Which legs are touching the ground? */
static bool _on_ground[4] = {true, true, true, true};

/* Walking speed. */
double creep_dx = 0.0;          // Sideways.
double creep_dy = 1.0;          // Forward.
double creep_rotation = 0.0;    // Rotation.
double creep_height = TIBIA * 0.75; // Body height.
double creep_spread = 0.0;      // Leg spread.

/*
Move all legs that are on the ground backwards, pushing the robot forward with
the current walking speed. This is called every tick, to make the robot move
continuously.
*/
void _creep_move() {
    for (unsigned char leg=0; leg < 4; ++leg) {
        if (_on_ground[leg]) {
            move_leg(
                leg,
                leg_position[leg][0] - creep_dx * LEG_X[leg] * SPEED,
                leg_position[leg][1] - creep_dy * LEG_Y[leg] * SPEED,
                -creep_height
            );
            rotate_leg_by(leg, -creep_rotation * LEG_X[leg] * LEG_Y[leg] / 2);
        }
    }
}

/* Called every frame. */
void _creep_tick() {
    _creep_move();
    tick(TICK);
}

/* Shifts the whole body by defined amount. */
void _shift_body_by(double dx, double dy) {
    for (unsigned char leg=0; leg < 4; ++leg) {
        move_leg_by(leg, dx * LEG_X[leg], dy * LEG_Y[leg], 0);
    }
    _shift_x += dx;
    _shift_y += dy;
}

/* Shifts the body away from the given leg, for balance. */
void _shift_body(unsigned char leg) {
    double dx = (LEG_X[leg] * SHIFT - _shift_x) / STEPS;
    double dy = (LEG_Y[leg] * SHIFT - _shift_y) / STEPS;
    for (unsigned char i = 0; i < STEPS; ++i) {
        _shift_body_by(dx, dy);
        _creep_tick();
    }
}

/* Perform a full step with a single leg. */
void _creep_step(unsigned char leg) {
    _shift_body(leg);
    _on_ground[leg] = false;
    beep(440, 5);
    for (unsigned char i = 0; i < 3; ++i) {
        move_leg_by(leg, 0, 0, 10);
        _creep_tick();
    }
    beep(tones[leg], 25);
    move_leg(
        leg,
        HOME + (_shift_x + creep_dx * STRIDE) * LEG_X[leg] + creep_spread,
        HOME + (_shift_y + creep_dy * STRIDE) * LEG_Y[leg] + creep_spread,
        leg_position[leg][2]
    );
    _creep_tick();
    _creep_tick();
    _creep_tick();
    _on_ground[leg] = true;
    beep(1865, 5);
    for (unsigned char i = 0; i < 3; ++i) {
        move_leg_by(leg, 0, 0, -10);
        _creep_tick();
    }
}

/* Perform one step of the creep gait with the current speed. */
void creep() {
    static unsigned char leg = 0;

    if (
        (creep_dx < -0.01 || creep_dx > 0.01) ||
        (creep_dy < -0.01 || creep_dy > 0.01) ||
        (creep_rotation < -0.01 || creep_rotation > 0.01)
    ) {
        _creep_step(leg);
        leg = _NEXT_LEG[leg];
    } else {
        _creep_tick();
    }
}
