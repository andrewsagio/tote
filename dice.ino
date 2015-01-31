#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"
#include "leg.h"


void setup() {
    beep_setup();
    battery_setup();
    servo_setup();
}


void loop() {
    // creep(0.0, 1.0);
    static int x = 0;
    static int dx = 1;
    move_leg_by(0, dx, 0, 0);
    move_leg_by(1, dx, 0, 0);
    move_leg_by(2, dx, 0, 0);
    move_leg_by(3, dx, 0, 0);
    x += dx;
    if (x > 20 || x < -20) { dx = -dx; }
}
