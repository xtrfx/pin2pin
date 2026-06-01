/*
TX Routine of Pin2Pin 
Dec. 21st 2025
*/
#include "p2p_func.h"

transmit tx;
char message[] = "abcdefghij";

void setup(){
  pinMode(txPin, OUTPUT); 
  Serial.begin(115200);
}

void loop() {
  delay(prepause);
  for (int j = 0; j < sizeof(message)-1; j++){
    tx.sendByte(message[j]);
    Serial.println(message[j]);
  }
  //sendByte(val);
  delay(postpause);
}
