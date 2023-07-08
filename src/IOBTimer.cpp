//#include "pins_arduino.h"
#include <Arduino.h>
#include "IOB.h"


IOBTimer::IOBTimer(uint32_t interval, PFTimer func, int maxTicks)
  : IOBase(false) {
  this->interval = interval;
  this->maxTicks = maxTicks;
  onTick = func;
}

void IOBTimer::loop(uint32_t currentMillis) {
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (maxTicks > 0) {
      ticks--;
    }
    else {
      ticks++;
    }

    OnTick(ticks, currentMillis);
    if (onTick != nullptr) {
      onTick(*this, ticks, currentMillis);
    }

    if (maxTicks > 0 && ticks <= 0) {
      stop();
    }
  }
}

void IOBTimer::start() {
  previousMillis = currentMillis;
  if (maxTicks > 0) {
    ticks = maxTicks;
  }
  else {
    ticks = 0;
  }
  IOBase::start();
}

void IOBTimer::onTickCall(PFTimer func){
  onTick = func;
}
