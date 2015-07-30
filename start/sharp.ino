#include "creep.h"
#include "beep.h"

void sharp_setup() {
    pinMode(A4, INPUT);
    Serial.begin(115200);
}


void sharp_loop() {
    int distance = 0;
    for (unsigned char i=0; i<10; ++i) {
        distance += analogRead(A4);
    }
    distance /= 10;
    Serial.println(distance);
    if (distance > 700) {
        creep_dx = 0;
        creep_dy = -1;
        creep_rotation = 0;
        beep(352, 100);
    } else if (distance > 520) {
        creep_dx = 0;
        creep_dy = 0;
        creep_rotation = 0;
    } else if (distance > 260) {
        creep_dx = 0;
        creep_dy = 1;
        creep_rotation = 0;
        beep(704, 100);
    } else {
        creep_dx = 0;
        creep_dy = 0;
        creep_rotation = PI/45;
        beep(1408, 100);
    }
}
