#pragma once

#include "IOBase.h"

struct IOBTimer;

typedef void (*PFTimer)(IOBTimer&, int ticks, uint32_t millis);

struct IOBTimer : public IOBase {
private:

  // Generally, you should use "uint32_t" for variables that hold time
  // The value will quickly become too large for an int to store
  uint32_t previousMillis = 0;  // will store last time LED was updated
  PFTimer onTick = nullptr;

public:
  // constants won't change:
  uint32_t interval = 1000;  // interval at which to blink (milliseconds)

  IOBTimer(uint32_t interval, int maxTicks = 0) : IOBTimer(interval, NULL, maxTicks) {}


  IOBTimer(uint32_t interval, PFTimer func, int maxTicks = 0);

  virtual void OnTick(int ticks, uint32_t millis){};

  int maxTicks = 0;
  int ticks;

  virtual void start() override;
  void onTickCall(PFTimer);

protected:
  void loop(uint32_t currentMillis);
};

class IOBLedFader : public IOBTimer {
  int ledPin;
public:
  IOBLedFader(uint32_t interval, int pin) : IOBTimer(interval, 360) {
    ledPin = pin;
  }

  void OnTick(int ticks, uint32_t millis) {
    float angle = radians(ticks % 360);                             // Converts degrees to radians.
    int brightness = (255 / 2) + (255 / 2) * -cos(angle);

    analogWrite(ledPin, brightness);
  }

};