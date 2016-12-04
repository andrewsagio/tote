#include "serialRemote.h"

extern int robot_mode;

void serial_setup(){
    if (!serialRemoteOn)
        return;
    
    Serial.begin(baudRate);
    
}

void serial_loop(){
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
  }
  
  switch(sdata[0]){
      case '0':
        robot_mode = 0;
        break;
      case '1':
        robot_mode = 1;
        break;
      case '2':
        robot_mode = 2;
        break;
      case '3':
        robot_mode = 3;
        break;
  }
  return;


    
}

