#include "servos.h"
#include "serial.h"

#define FRAME_TIME 10


void setup() {
    battery_setup();
    serial_setup();
    servo_setup();
}


void loop() {
    static unsigned long last_tick = 0;
    unsigned long now = millis();

    do_serial_command();
    if (now > last_tick + FRAME_TIME || now < last_tick) {
        battery_check();
        last_tick = now;
    }
}
