#pragma once

#include "IOBase.h"

class IOBFlasher : public IOBase {
private:
  uint8_t lampDriverPin;  // Holds pin-number of the lamp
  bool firstState;        // True when lamp should be on during first part of flash cycle
  bool cycleStart;        // ms clock at start of current cycle
  bool inverted;          // inverted flag for led to VCC
  uint16_t period;        // Cycle period in ms
  uint16_t firstPart;     // Time for first part of cycle in ms

public:
  // Creates a new Flasher
  // parameters:
  // pin, the pin 
  IOBFlasher( int pin,                      // Specifies the pin we use to drive the lamp
              bool startSwitchedOn = false, // Specifies if the lamp starts on or off (default)
              bool isInverted = false       // inverted flag for led to VCC
            ) : IOBase(false) {
    lampDriverPin = pin;                                        // Store the pin we are working on
    pinMode(pin, OUTPUT);                                       // Make it an output (to drive the MOSFET)
    digitalWrite(lampDriverPin, inverted ^ startSwitchedOn);  // Set the initial condition
  }

  void stop() {
    digitalWrite(lampDriverPin, inverted);  // Switch lamp off
    IOBase::stop();                        // We are not running now
  }

  void start() {
    digitalWrite(lampDriverPin, !inverted);  // Switch lamp on
    IOBase::start();                        // We are not running now
  }

  void flash(
    int ms_period = 1000,       // Time for one full flash in 1000th of a second
    uint8_t dutyCyclePct = 50,  // Percentage on. 50 is equal on/off parts
    bool startOn = true         // Cycle starts with lamp on (default) or off
  );

  void loop(uint32_t currentMillis);
};
