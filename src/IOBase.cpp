#include <Arduino.h>
#include "IOB.h"

IOBase* IOBase::root = NULL;
uint32_t IOBase::currentMillis = 0l;

void IOBase::loopAll() {
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


