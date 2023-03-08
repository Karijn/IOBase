#pragma once

struct IOBase;

typedef void (*PFIOBaseV)(IOBase*);

struct IOBase {
private:
  static IOBase* root;
  IOBase* Next;

protected:
  bool running = true;
  bool wasRunning = true;

protected:
  IOBase() {
    Next = root;
    root = this;
  }

  static unsigned long currentMillis;

  virtual void loop(unsigned long milliseconds) = 0;
  virtual void ChangeRunning(){};

public:

  static void loopAll();
  bool isRunning();
  bool setRunning(bool set);

};


#include "IOBButton.h"
#include "IOBFlasher.h"
#include "IOBTimer.h"