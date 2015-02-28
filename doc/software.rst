Software
********

All the required code is included in the repository. You will need an Arduino
IDE and a TTL2USB programmer for the Pro Mini to compile and upload the
software into the robot. Connect the programmer, open ``dice.ino`` in the
Arduino IDE, and click "Upload". That's all.

For the infra-red communication, I'm using the excellent IRLRemote library,
written by NicoHood. You may want to adjust the ``ir.ino`` file to modify the
button commands, so that they match your TV remote.

For controlling the servos, I'm using the Servo library bundled with Arduino.
