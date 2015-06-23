#include "creep.h"

#define TRIG_PIN 3
#define ECHO_PIN 13

void ping_setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

long get_distance() {
    unsigned long int start;
    unsigned long int duration;

    digitalWrite(TRIG_PIN, LOW);
    digitalWrite(ECHO_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);
    return duration / 58.2;
}

void ping_loop() {
    long distance = 0;

    while (!distance) {
        distance = get_distance();
    }
    if (distance > 1 && distance < 10) {
        creep_dx = 0;
        creep_dy = 0;
    }
}
