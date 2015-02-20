#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"
#include "misc.h"

#define HOME ((COXA + FEMUR) / SQRT2)

void setup() {
    beep_setup();
    battery_setup();
    servo_setup();
    ir_setup();
}

void ir_loop();

void loop() {
    creep();
    ir_loop();
    // delay(100);
}
