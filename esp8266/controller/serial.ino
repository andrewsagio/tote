void serial_setup() {
    int16_t prev = 0x00;
    int16_t next = 0x00;

    Serial.begin(115200);
    /* Wait for two 0xf0 in a row. */
    while (prev != 0xf0 || next != 0xf0) {
        if (Serial.available()) {
            prev = next;
            next = Serial.read();
        }
        delay(100);
    }
}


int16_t _serial_read_word() {
    /* Read two bytes from the serial port and make an int from them. */
    int16_t high = Serial.read();
    int16_t low = Serial.read();
    int16_t value = high << 8 | low;
    return value;
}


void _serial_write_word(int16_t value) {
    /* Take an int and send it through the serial port as two bytes. */
    int16_t high = (value & 0xff00) >> 8;
    int16_t low = value & 0xff;
    Serial.write(high);
    Serial.write(low);
}


void do_serial_command() {
    static unsigned char serial_command = 0;
    /* Read and execute a command from the serial port's buffer. */
    switch (serial_command) {
        case 0x00:
            /* No command, read one. */
            if (Serial.available() < 1) { return; }
            serial_command = Serial.read();
            return;
        case 0xff:
            /* Move all servos by 1/1000 of radians. */
            if (Serial.available() < SERVOS * 2) { return; }
            for (unsigned char servo = 0; servo < SERVOS; ++servo) {
                double pos = _serial_read_word();
                servo_move(servo, pos / 1000.0);
            }
            break;
        case 0xf2:
            Serial.write(0xff);
            Serial.write(map(get_battery(), 0, 1023, 0, 255));
            break;
        case 0xf3:
            servo_shutdown();
            break;
       case 0xf0:
            /* No op. */
            break;

    }
    serial_command = 0;
}
