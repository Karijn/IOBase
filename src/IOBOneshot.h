#pragma once

#include "IOB.h"

class IOBOneshot : public IOBTimer {
private:
  uint8_t lampDriverPin;  // Holds pin-number of the lamp
  uint32_t cycleStart;        // ms clock at start of current cycle
  bool inverted;          // inverted flag for leds to VCC
public:

  IOBOneshot(
    uint32_t period,              // Cycle period in ms
    int pin,                      // Specifies the pin we use to drive the lamp
    bool isInverted = false       // inverted flag for led to VCC
    ) : IOBTimer(period, 1) {
    lampDriverPin = pin;                       // Store the pin we are working on
    pinMode(pin, OUTPUT);                      // Make it an output (to drive the MOSFET)
    inverted = isInverted;
    digitalWrite(lampDriverPin, inverted );    // Set the initial condition
  }

  virtual void OnTick(int ticks, uint32_t millis) override {
    digitalWrite(lampDriverPin, inverted);  // Switch lamp off
    Serial.println("OnTick");
  }

  void stop() {
    IOBTimer::stop();
    digitalWrite(lampDriverPin, inverted);  // Switch lamp off
    Serial.println("stop");
  }

  void start() {
    IOBTimer::start();
    digitalWrite(lampDriverPin, !inverted);  // Switch lamp on
    Serial.println("start");
  }
};

