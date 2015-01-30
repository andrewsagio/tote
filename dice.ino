#include "servos.h"
#include "beep.h"
#include "battery.h"
#include "creep.h"


void setup() {
    beep_setup();
    battery_setup();
    servo_setup();
}


void loop() {
    creep(0.0, 1.0);
}
