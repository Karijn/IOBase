#pragma once

struct IOBase;

typedef void (*PFIOBaseV)(IOBase*);

struct IOBase {
private:
  static IOBase* root;
  IOBase* Next;
  bool running;

protected:
  bool wasRunning = true;

protected:
  IOBase(bool run = true) {
    Next = root;
    root = this;
    this->running = run;
  }

  static uint32_t currentMillis;

  virtual void loop(uint32_t milliseconds) = 0;
  virtual void ChangeRunning(){};

public:

  // loop all IOBase-derived objects
  static void loopAll();

  // gets the running state of an IOBase object
  bool isRunning() {
    return running ;
  }

  virtual void stop() {
    running = false;                  // We are not running now
  }

  virtual void start() {
    running = true;                    // We are running now
  }
};
