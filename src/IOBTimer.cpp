#include "pins_arduino.h"
#include <Arduino.h>
#include "IOBTimer.h"

IOBTimer::IOBTimer(long interval = 0, int initTicks = 0)
  : IOBase() {
  this->interval = interval;
  this->maxTicks = initTicks;
  running = false;
}

void IOBTimer::loop(unsigned long currentMillis) {
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (maxTicks > 0) {
      ticks--;
    }

    OnTick(ticks);
    if (onTick != nullptr) {
      onTick(*this, ticks);
    }

    if (maxTicks > 0 && ticks <= 0) {
      running = false;
    }
  }
}

void IOBTimer::start() {
  previousMillis = currentMillis;
  ticks = maxTicks;
  running = true;
}

void IOBTimer::onTickCall(PFTimer func){
  onTick = func;
}
