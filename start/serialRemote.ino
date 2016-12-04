#include "serialRemote.h"

extern int robot_mode;

void serial_setup(){
    if (!serialRemoteOn)
        return;
    
    Serial.begin(baudRate);
    
}

int serial_loop(){
    if (!serialRemoteOn)
        return;  // function off
   char sdata[256];
   int nl = 10; // end of line character
   
  if (Serial.available() > 0) {
    int bytes = Serial.readBytesUntil(nl, sdata, 80); // read until end line
    int speed; // Local variable

    //Serial.println(bytes);
    //    for (int i = 0; i < bytes; i++) {
    //      Serial.print(sdata[i]);
    //    }

    sdata[bytes] = '\0';   // make it a proper string
    Serial.print("Received: ");
    Serial.println(sdata);
    robot_mode = atoi(sdata);
    return robot_mode;
  }
  
  
  return -1;


    
}

