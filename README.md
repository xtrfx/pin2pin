# pin2pin
---

This project is a learning project building a simplified implementation of a one-way/half-duplex UART protocol to facilitate
communicaiton between two arduino microcontrollers. It is a bit-banging implementation
and as such does not rely on the available UART TX/RX pins on the Arduino Uno R3. 

This is absolutely a "re-inventing the wheel" project and is not meant to solve any unsolved
problems but rather a to build/understand, among other things:

- C low-level data handling (addressing, bitmasking and bit level logic)
- debugging hardware projects 
- serial communicaiton protocol basics

This is an ongoing project and is by no means in a finished state.

---
## Asssembly and use

Current version is simple to wire, using two arduinos one serving as a Transmit(Tx) unit
and  the other as a Receive(Rx) unit. The units share a common ground and transmit between pins 12 and 11 of the two
units (see schematici.)
