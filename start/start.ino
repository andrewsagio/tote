#include "misc.h"
#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"
#include "serialRemote.h"

#include <avr/sleep.h>

const int maxNumModes = 10;

const char* modeComment[maxNumModes];






int robot_mode = 2;


void setup() {
    modeComment[0] = "0: fold up";
    modeComment[1] = "1: Walk";
    modeComment[2] = "2: Stop";
    modeComment[3] = "3: Stand";
    
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
            servo_fold();
//            servo_shutdown();
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
        case 2:  // stop
            servo_setup();
            break;
        case 3:
            servo_stand();
            break;
            
    }
    //ir_loop();
    //battery_loop();
    int modeIn = serial_loop();
    if (modeIn >=0 && modeIn < maxNumModes ){
        Serial.println(modeComment[modeIn]);
    }
    
    //Serial.println("test");
}
