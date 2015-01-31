#include "creep.h"
#include "misc.h"
#include "leg.h"
#include "clock.h"

#define STEP_HEIGHT 10

const unsigned char _NEXT_LEG[4] = {1, 0, 2, 3};

// static double _shift_x = 0.0;
// static double _shift_y = 0.0;
static bool _on_ground[4] = {true, true, true, true};

//double dx = 0;
//double dy = 1.0;


void _creep_move(double dx, double dy) {
    for (unsigned char leg=0; leg < 4; ++leg) {
        if (_on_ground[leg]) {
            move_leg_by(leg, -dx, -dy * LEG_Y[leg], 0);
        }
    }
}

void _creep_tick(double dx, double dy) {
    _creep_move(dx, dy);
    tick(TICK);
}

void _raise_leg(unsigned char leg, double dx, double dy) {
    _on_ground[leg] = false;
    move_leg_by(leg, 0, 0, STEP_HEIGHT);
    _creep_tick(dx, dy);
    _creep_tick(dx, dy);
}

void _lower_leg(unsigned char leg, double dx, double dy) {
    move_leg_by(leg, 0, 0, -STEP_HEIGHT + 1);
    _creep_tick(dx, dy);
    _creep_tick(dx, dy);
    move_leg_by(leg, 0, 0, 1);
    _on_ground[leg] = true;
}

void _advance_leg(unsigned char leg, double dx, double dy) {
    move_leg(leg,
             (COXA + FEMUR) / SQRT2,
             (COXA + FEMUR) / SQRT2,
             leg_position[leg][2]);
    _creep_tick(dx, dy);
    _creep_tick(dx, dy);
    _creep_tick(dx, dy);
    _creep_tick(dx, dy);
}

void _creep_step(unsigned char leg, double dx, double dy) {
    _raise_leg(leg, dx, dy);
    _advance_leg(leg, dx, dy);
    _lower_leg(leg, dx, dy);
}

void creep(double dx, double dy) {
    static unsigned char leg = 0;

    if ((dx < -0.01 || dx > 0.01) || (dy < -0.01 || dy > 0.01)) {
        _creep_step(leg, dx, dy);
        leg = _NEXT_LEG[leg];
    } else {
        _creep_tick(dx, dy);
    }
}
