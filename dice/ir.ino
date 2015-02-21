#include "creep.h"
#include <IRLremote.h>

void ir_setup() {
    IRLbegin<IR_ALL>(0); // Sensor on PIN 2
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
}

void ir_loop() {
    digitalWrite(13, LOW);
}

void IREvent(uint8_t protocol, uint16_t address, uint32_t command) {
    static uint32_t last=0;
    bool led = false;

    if (address != 0xFF00) {
        return; // React only to my remote.
    }

    if (command == 0xFFFFFF) {
        command = last;
    }
    switch (command) {
        case 0xBF40:
            creep_dy = min(1.0, creep_dy + 0.25);
            led = true;
            break;
        case 0xE619:
            creep_dy = max(-1.0, creep_dy - 0.25);
            led = true;
            break;
        case 0xF807:
            creep_dx = min(1.0, creep_dx + 0.25);
            led = true;
            break;
        case 0xF609:
            creep_dx = max(-1.0, creep_dx - 0.25);
            led = true;
            break;
        case 0xEA15:
            led = true;
            creep_dx = 0.0;
            creep_dy = 0.0;
            break;
    }
    if (led) {
        digitalWrite(13, HIGH);
    }
}