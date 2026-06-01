/*
Pin2Pin functions header
*/

#ifndef P2P_FUNC_H
#define P2P_FUNC_H

#include<Arduino.h>
/* Shared Variables*/

extern const int txPin,rxPin;

extern const int bitWidth;

extern const int prepause;	// TX pause before message
extern const int postpause;	// TX pause after message

extern const int idleWidth;	// RX pause for signal line monitoring frequency
extern const int bufSize;		// message size param for RX/TX  

/*----- Transmit (TX)  Functions----- */
class transmit{
  public:
    void sendByte(uint8_t);
};

/*-----   Receive (RX) Functions -----*/
class receive{
  private:
    unsigned char readByte();

  public:
    void waitSignal(); 
    void clearBuffer();
    void fillBuffer();
    void printBuffer();
};

#endif
