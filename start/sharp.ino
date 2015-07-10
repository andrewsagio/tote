#include "creep.h"


void sharp_setup() {
    pinMode(A4, INPUT);
}


void sharp_loop() {
    // Stop if there is an object closer than 15cm ahead.
    if (analogRead(A4) > 465) {
        creep_dx = 0;
        creep_dy = 0;
    }
}
