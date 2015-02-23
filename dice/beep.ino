#define BEEP_PIN 3

bool beep_mute = false;


void beep_setup() {
    pinMode(BEEP_PIN, OUTPUT);
    beep(440, 200);
    delay(100);
    beep(523, 100);
    delay(50);
    beep(880, 100);
}

void beep(int frequency, int duration) {
    if (beep_mute) {
        return;
    }
    tone(BEEP_PIN, frequency, duration);
}
