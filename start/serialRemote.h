#ifndef SERIALREMOTE_H
#define SERIALREMOTE_H

const long baudRate = 9600;

const bool serialRemoteOn = true;



void serial_setup();

int serial_loop();

#endif
