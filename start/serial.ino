#include "creep.h"
#include "leg.h"
#include "servos.h"
#include "misc.h"

void serial_setup() {
    int16_t prev = 0x00;
    int16_t next = 0x00;

    Serial.begin(115200);

    while (prev != 'x' || next != 'x') {
        if (Serial.available()) {
            prev = next;
            next = Serial.read();
        }
        delay(100);
    }
}

void serial_loop() {
    while (Serial.available()) {
        unsigned char command = Serial.read();
        switch (command) {
            case 'w':    // Up arrow.
                creep_dy = min(1.5, creep_dy + 0.25);
                break;
            case 's':    // Down arrow.
                creep_dy = max(-1.5, creep_dy - 0.25);
                break;
            case 'a':    // Left arrow.
                creep_rotation = min(PI/90, creep_rotation + PI/360);
                break;
            case 'd':    // Right arrow.
                creep_rotation = max(-PI/90, creep_rotation - PI/360);
                break;
            case '[':    // Rewind.
                creep_spread = max(-10.0, creep_spread - 1);
                break;
            case '\'':    // Play/pause.
                creep_spread = 0.0;
                break;
            case ']':    // Fast forward.
                creep_spread = min(10.0, creep_spread + 1);
                break;
            case ',':    // Channel minus.
                creep_height = max(TIBIA * 0.25, creep_height - 1);
                break;
            case '.':    // Channel plus.
                creep_height = min(TIBIA * 1.25, creep_height + 1);
                break;
            case '/':
                creep_height = TIBIA * 0.75;
                break;
            case 'z':    // Volume down.
                creep_dx = max(-1.0, creep_dx - 0.25);
                break;
            case 'c':    // Volume up.
                creep_dx = min(1.0, creep_dx + 0.25);
                break;
            case 'h':    // Home.
                for (unsigned char leg=0; leg < 4; ++leg) {
                    move_leg(
                        leg,
                        ((COXA + FEMUR) / SQRT2),
                        ((COXA + FEMUR) / SQRT2),
                        TIBIA
                    );
                }
                break;
            case 'x':    // OK.
                creep_dx = 0.0;
                creep_dy = 0.0;
                creep_rotation = 0.0;
                break;
        }
    }
}
