#include "misc.h"
#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"

#include <avr/sleep.h>

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
            servo_shutdown();
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            while (1) {
                delay(100);
            }
            break;
        case 1: // Creep
            creep();
            break;
        case 2: // Nothing
            delay(100);
            break;
    }
    ir_loop();
    battery_loop();
}
