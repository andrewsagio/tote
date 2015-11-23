#include "misc.h"
#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"

#include <avr/sleep.h>

// 0 -- Power off
// 1 -- Walk
// 2 -- Nothing
int robot_mode = 2;


const int steps = 33;
const int drawing_x[steps] = {
    0, 0, 2, 0, 0, 6, 6, 3, 3, 7, 7, 7, 10, 10, 7, 10, 11, 11, 13, 13, 14, 14,
    11, 15, 15, 18, 18, 15, 20, 20, 19, 21
};
const int drawing_y[steps] = {
    0, 2, 2, 2, 4, 4, 0, 0, 4, 4, 0, 4, 4, 2, 2, 0, 0, 4, 4, 2, 2, 0, 0, 0, 4, 4, 0, 0, 0, 4, 4, 4, 4
};

void draw() {
    int x = 0;
    int y = 0;
    for (int leg = 0; leg < 4; ++leg) {
        move_leg(leg, HOME, LEG_Y[0] * HOME, -TIBIA);
    }
    for (int step = 0; step < steps; ++step) {
        int dx = (drawing_x[step] - 10) - x;
        int dy = (drawing_y[step] - 2) - y;
        x += dx;
        y += dy;
        for (int i = 0; i < 4; ++i) {
            for (int leg = 0; leg < 4; ++leg) {
                move_leg_by(leg, dx * LEG_X[leg] * 0.5, dy * LEG_Y[leg] * 0.5, 0);
            }
            delay(100);
        }
        delay(100);
    }
}


void setup() {
    battery_setup();
    servo_setup();
    beep_setup();
}

void loop() {
    switch (robot_mode) {
        case 0: // Power off
            servo_shutdown();
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            while (1) {
                delay(100);
            }
            break;
        case 1:
            walk();
            break;
        case 2: // Nothing
            draw();
            break;
    }
    battery_loop();
}
