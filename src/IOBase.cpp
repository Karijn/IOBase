#include <Arduino.h>
#include "IOBase.h"

IOBase* IOBase::root = NULL;
static unsigned long IOBase::currentMillis = 0l;

static void IOBase::loopAll() {
  currentMillis = millis();

  IOBase* current = root;
  while (current != NULL) {
    if (current->wasRunning != current->running) {
      current->ChangeRunning();
    }
    if (current->running) {
      current->loop(currentMillis);
    }
    current->wasRunning = current->running;
    current = current->Next;
  }
}

bool IOBase::isRunning() {
  return running ;
}

bool IOBase::setRunning(bool set) {
  bool tmp = running;
  running = set;
  return tmp;
}

