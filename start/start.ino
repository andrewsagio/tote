#include "misc.h"
#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"
#include "serialRemote.h"

#include <avr/sleep.h>

// 0 -- Power off
// 1 -- Walk
// 2 -- Nothing
int robot_mode = 2;


void setup() {
    battery_setup();
    servo_setup();
    //beep_setup();
    //ir_setup();
    serial_setup();
    //Serial.begin(9600);
}

void loop() {
    
    switch (robot_mode) {
        case 0: // Power off
            servo_shutdown();
//            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
//            sleep_enable();
//            sleep_mode();
//            while (1) {
//                delay(100);
//            }
            break;
        case 1:
            walk();
            break;
        case 3:  // start up
            servo_setup();
            break;
    }
    //ir_loop();
    //battery_loop();
    serial_loop();
    //Serial.println("test");
}
