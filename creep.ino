#include "creep.h"
#include "misc.h"
#include "leg.h"
#include "clock.h"

#define STEP_HEIGHT 15.0
#define STRIDE 18.0
#define SHIFT 6.0
#define STEPS 4
#define HOME ((COXA + FEMUR) / SQRT2) * 0.75
#define BODY_HEIGHT TIBIA

const unsigned char _NEXT_LEG[4] = {1, 3, 0, 2};


static double _shift_x = 0.0;
static double _shift_y = 0.0;
static bool _on_ground[4] = {true, true, true, true};

double creep_dx = 0;
double creep_dy = 1.0;


void _creep_move() {
    for (unsigned char leg=0; leg < 4; ++leg) {
        if (_on_ground[leg]) {
            move_leg_by(leg, -creep_dx * LEG_X[leg], -creep_dy * LEG_Y[leg], 0);
        }
    }
}

void _creep_tick() {
    _creep_move();
    tick(TICK);
}

void _raise_leg(unsigned char leg) {
    move_leg_by(leg, 0, 0, STEP_HEIGHT);
    _creep_tick();
    _on_ground[leg] = false;
    _creep_tick();
    _creep_tick();
    _creep_tick();
}

void _lower_leg(unsigned char leg) {
    move_leg_by(leg, 0, 0, -STEP_HEIGHT);
    _creep_tick();
    _creep_tick();
    _creep_tick();
    _on_ground[leg] = true;
    _creep_tick();
}

void _advance_leg(unsigned char leg) {
    move_leg(
        leg,
        HOME + (_shift_x + creep_dx * STRIDE) * LEG_X[leg],
        HOME + (_shift_y + creep_dy * STRIDE) * LEG_Y[leg],
        -BODY_HEIGHT
    );
    _creep_tick();
    _creep_tick();
    _creep_tick();
    _creep_tick();
}

void _shift_body_by(double dx, double dy) {
    for (unsigned char leg=0; leg < 4; ++leg) {
        move_leg_by(leg, dx * LEG_X[leg], dy * LEG_Y[leg], 0);
    }
    _shift_x += dx;
    _shift_y += dy;
}

void _shift_body(unsigned char leg) {
    double dx = (LEG_X[leg] * SHIFT - _shift_x) / STEPS;
    double dy = (LEG_Y[leg] * SHIFT - _shift_y) / STEPS;
    for (unsigned char i = 0; i < STEPS; ++i) {
        _shift_body_by(dx, dy);
        _creep_tick();
    }
}

void _creep_step(unsigned char leg) {
    _shift_body(leg);
    _raise_leg(leg);
    _advance_leg(leg);
    _lower_leg(leg);
}

void creep() {
    static unsigned char leg = 0;

    if ((creep_dx < -0.01 || creep_dx > 0.01) ||
        (creep_dy < -0.01 || creep_dy > 0.01)) {
        _creep_step(leg);
        leg = _NEXT_LEG[leg];
    } else {
        _creep_tick();
    }
}
