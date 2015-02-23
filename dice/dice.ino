#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"
#include "misc.h"

#define HOME ((COXA + FEMUR) / SQRT2)

bool power = true;


void setup() {
    battery_setup();
    servo_setup();
    beep_setup();
    ir_setup();
}

void ir_loop();

void loop() {
    if (power) {
        creep();
        ir_loop();
    } else {
        servo_shutdown();
        while (true) delay(100);
    }
}
