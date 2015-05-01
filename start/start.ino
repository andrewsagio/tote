#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"
#include "misc.h"


bool power = true;


void setup() {
    battery_setup();
    servo_setup();
    beep_setup();
    ir_setup();
}

void loop() {
    if (power) {
        creep();
        ir_loop();
    } else {
        servo_shutdown();
        while (!power) {
            delay(100);
            ir_loop();
        }
    }
}
