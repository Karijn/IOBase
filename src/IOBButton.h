#pragma once

#include "IOBase.h"
enum ButtonState {
  DB_Released,
  DB_Raising,
  DB_Pressed,
  DB_Falling
};

struct IOBButton;
typedef void (*PFVIuL)(IOBButton&, ButtonState, int, uint32_t);

struct IOBButton : public IOBase {
private:
  uint32_t lastDebounceTime = 0;
  byte buttonPin;
  bool invertMode : 1;
  bool lastButtonState : 1;
  bool raising : 1;
  bool falling : 1;
  bool buttonState : 1;
protected:
  uint32_t lastPressedTime;
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
  virtual void loop(uint32_t currentMillis);
  virtual void pressed(uint32_t currentMillis);
  virtual void raise(uint32_t currentMillis);
  virtual void fall(uint32_t currentMillis);
};
