#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"
#include "misc.h"

// 0 -- Power off
// 1 -- Creep
// 2 -- Trot
int robot_mode = 1;


void setup() {
    battery_setup();
    servo_setup();
    beep_setup();
    ir_setup();
}

void loop() {
    switch (robot_mode) {
        case 0: // Power off
            delay(100);
            break;
        case 1: // Creep
            creep();
            break;
        case 2: // Trot
            // trot();
            break;
    }
    ir_loop();
}
