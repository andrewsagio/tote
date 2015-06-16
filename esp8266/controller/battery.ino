#define BATTERY_PIN A4
#define MIN_BATTERY 557 // About 3.59V

void battery_setup() {
    pinMode(BATTERY_PIN, INPUT);
}

int get_battery() {
    return analogRead(BATTERY_PIN);
}

void battery_check() {
    static int battery_fail = 0;
    int reading = get_battery();

    if (reading < MIN_BATTERY) {
        battery_fail += 1;
    } else {
        battery_fail = 0;
    }
    if (battery_fail > 40) {
        /* If it stays bad for 4s, shut down. */
        servo_shutdown();
    }
}
