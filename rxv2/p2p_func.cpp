#include "p2p_func.h"
//#include <Arduino.h>
//#include <stdint.h>

const int txPin = 11;
const int rxPin = 12;
const int bitWidth = 10;

const int prepause = 2000;	// TX pause before message
const int postpause = 4000;	// TX pause after message

const int idleWidth = 1;	// RX pause for signal line monitoring frequency
const int bufSize = 10;		// message size param for RX/TX
char buffer[bufSize]; 

/*----- Transmit (TX) Funcitons------ */
//uint8_t byteChunk;
void transmit::sendByte(uint8_t byteChunk){
  // send start sig by pulling line LOW
  digitalWrite(txPin,LOW);
  delay(bitWidth);

  //data bits
  for(int i = 7; i >=0; i-- ){
    uint8_t bit = (byteChunk & (1 << i) ? 1:0);
    if(bit){
      // a One is represented by LOW, pull line down
      Serial.print(bit);
      digitalWrite(txPin,LOW);
      delay(bitWidth);
      //digitalWrite(txPin,HIGH);
    }
    else{
      // a Zero is represented by HIGH, take the line back to high
      Serial.print(bit);
      digitalWrite(txPin,HIGH);
      delay(bitWidth);
    }  
  }
  Serial.println("");
}

/* ------ Receive (RX) Funcitons------ */

void receive::waitSignal(){
  Serial.println("Waiting");
  uint8_t lineState = 1;
  do{
    // while High no data is inbound
    lineState = digitalRead(rxPin);
    delay(idleWidth);
  } while(lineState);
  
  delay(bitWidth); // wait for preamble bit period
  Serial.println("Line Low, Data Inbound");
  return;
}

unsigned char receive::readByte(){
  unsigned char mesg = 0B00000000; 	// message to be received
  unsigned char mask = 0;

  for (int i = 7; i >=0; i--){
    uint8_t bit = digitalRead(rxPin);
    if(bit){
      mask = (0 << i);
    }
    else{
      mask = (1 << i);
    }
    //mask = (bit << i);		// bitmaks with either 0 or 1 at position i
    mesg |= mask;		// apply bitmask to message
    delay(bitWidth);
  }
  Serial.println(mesg);
  return mesg;
}

void receive::clearBuffer(){
  for (int i = 0; i<= (bufSize - 1); i++){
    buffer[i]=0;
  }
  Serial.println("");
}

void receive::fillBuffer(){
  for (int i = 0; i < bufSize; i++){
    buffer[i] = (char)readByte(); 	//Read byte and append  to buffer
    delay(bitWidth);                  //after 8bytes, preamble spaceer
  }   		                            // execute unil buffer is full
  // could be a good place to add packetcheck and change sampling/alingment
}
void receive::printBuffer(){
  for (int i = 0; i<= (bufSize - 1); i++){
    Serial.print(buffer[i]);
  }
  Serial.println("");
}
