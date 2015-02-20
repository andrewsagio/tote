#define BEEP_PIN A7

void beep_setup() {
    pinMode(BEEP_PIN, OUTPUT);
    delay(50);
    tone(BEEP_PIN, 440, 200);
    delay(200);
    tone(BEEP_PIN, 523, 100);
    delay(150);
    tone(BEEP_PIN, 880, 100);
}

void beep(int frequency, int duration) {
    tone(BEEP_PIN, frequency, duration);
}
