#include "servos.h"
#include "beep.h"
#include "battery.h"


#define FRAME_TIME 10


void setup() {
    beep_setup();
    battery_setup();
    servo_setup();
}


void loop() {
    static unsigned long last_tick = 0;
    unsigned long now = millis();

    if (now > last_tick + FRAME_TIME || now < last_tick) {
        battery_check();
        last_tick = now;
    }
}
