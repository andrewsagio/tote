#include "misc.h"
#include "servos.h"
#include "creep.h"
#include "leg.h"


// 0 -- Power off
// 1 -- Walk
// 2 -- Nothing
int robot_mode = 1;


void setup() {
    servo_setup();
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}

void loop() {
    switch (robot_mode) {
        case 0: // Power off
            servo_shutdown();
            while (1) {
                delay(100);
            }
            break;
        case 1:
            walk();
            break;
        case 2: // Nothing
            delay(100);
            break;
    }
    digitalWrite(13, LOW);
}
