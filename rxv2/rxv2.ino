/*
RX Routine of pin2pin
Dec. 21st 2025
*/
#include "p2p_func.h"

receive rx;
void setup(){
  pinMode(rxPin,INPUT_PULLUP);
  Serial.begin(115200); 
}

void loop(){
  rx.waitSignal();
  rx.clearBuffer();
  rx.fillBuffer();
  rx.printBuffer();
}
