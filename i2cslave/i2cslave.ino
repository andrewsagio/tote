#include "servos.h"

#include <Wire.h>


const int SLAVE_ADDRESS = 0x04;


void setup() {
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveEvent);
    servo_setup();
}


void loop() {
    delay(100);
}


void receiveEvent(int bytes) {
    union {
        byte bytes[4];
        float value;
    } float2bytes;
    unsigned int servo = Wire.read() | Wire.read() << 8;
    for (int j = 0; j < 4; ++j) {
        if (!Wire.available()) { return; }
        float2bytes.bytes[j] = Wire.read();
    }
    servo_move(servo, float2bytes.value);
}
