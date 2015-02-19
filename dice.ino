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
}


void loop() {
    creep();
    return;
    static double a = 0;
    static double da = 0.5;


    move_leg_by(0, 0, da, 0);
    move_leg_by(0, 0, da, 0);
    move_leg_by(0, 0, da, 0);
    move_leg_by(0, 0, da, 0);

    a += da;
    if (a > 20 || a < -20) {
        da = -da;
    }

    delay(100);
}
