#pragma once

#include "IOBase.h"

struct IOBTimer;
typedef void (*PFTimer)(IOBTimer&, int ticks);

struct IOBTimer : public IOBase {
private:

  // Generally, you should use "unsigned long" for variables that hold time
  // The value will quickly become too large for an int to store
  unsigned long previousMillis = 0;  // will store last time LED was updated
  PFTimer onTick = nullptr;

public:
  // constants won't change:
  long interval = 1000;  // interval at which to blink (milliseconds)

  IOBTimer(long interval = 0l, int initTicks = 0);

  virtual void OnTick(int ticks){};

  int maxTicks = 0;
  int ticks;

  void start();
  void onTickCall(PFTimer);

protected:
  void loop(unsigned long currentMillis);
};
