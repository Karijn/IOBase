#pragma once

#include "IOBase.h"
enum ButtonState {
  DB_Released,
  DB_Raising,
  DB_Pressed,
  DB_Falling
};

struct IOBButton;
typedef void (*PFVIuL)(IOBButton&, ButtonState, int, unsigned long);

struct IOBButton : public IOBase {
private:
  unsigned long lastDebounceTime = 0;
  byte buttonPin;
  bool invertMode : 1;
  bool lastButtonState : 1;
  bool raising : 1;
  bool falling : 1;
  bool buttonState : 1;
protected:
  unsigned long lastPressedTime;
  int ticks = 0;
  PFVIuL onChanged;

public:
  static uint16_t onPressDelaySlow;
  static uint16_t onpressDelayFast;
  static uint16_t debounceDelay;
  static uint16_t onpressSlowCount;

  IOBButton(int pin, bool invert = false, int mode = INPUT);
  bool isPressed();
  bool isRaising();
  bool isFalling();
  void onChangedCall(PFVIuL);

protected:
  virtual void loop(unsigned long currentMillis);
  virtual void pressed(unsigned long currentMillis);
  virtual void raise(unsigned long currentMillis);
  virtual void fall(unsigned long currentMillis);
};
