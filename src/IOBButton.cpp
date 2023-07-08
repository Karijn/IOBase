#include <Arduino.h>
#include "IOB.h"

uint16_t IOBButton::onPressDelaySlow = 250;
uint16_t IOBButton::debounceDelay = 50;
uint16_t IOBButton::onpressDelayFast = 100;
uint16_t IOBButton::onpressSlowCount = 5;

IOBButton::IOBButton(int pin, bool invert, int mode)
    : IOBase()
{
    buttonPin = pin;
    invertMode = invert;
    pinMode(buttonPin, mode);
}

void IOBButton::loop(uint32_t currentMillis)
{
    raising = false;
    falling = false;
    int reading = digitalRead(buttonPin) ^ invertMode;

    if (reading != lastButtonState)
    {
        lastDebounceTime = currentMillis;
    }

    if ((currentMillis - lastDebounceTime) > debounceDelay)
    {
        if (reading != buttonState)
        {
            buttonState = reading;
            if (buttonState)
            {
                raising = true;
            }
            else
            {
                falling = true;
            }
        }
    }
    lastButtonState = reading;
    if (raising)
        raise(currentMillis);
    if (falling)
        fall(currentMillis);
    if (buttonState)
        pressed(currentMillis);
}

// Check if a button is currently pressed
bool IOBButton::isPressed() {
    return buttonState;
}

  bool IOBButton::isRaising() {
    return raising;
}
  bool IOBButton::isFalling() {
    return falling;
}

void IOBButton::onChangedCall(PFVIuL func)
{
    onChanged = func;
}

void IOBButton::pressed(uint32_t currentMillis)
{
    if ((currentMillis - lastPressedTime) > (ticks < onpressSlowCount ? onPressDelaySlow : onpressDelayFast))
    {
        ticks++;
        lastPressedTime = currentMillis;
        if (onChanged)
            onChanged(*this, DB_Pressed, ticks, currentMillis);
    }
}

void IOBButton::raise(uint32_t currentMillis)
{
    lastPressedTime = currentMillis;
    ticks = 0;
    if (onChanged) {
        onChanged(*this, DB_Raising, 0, 0);
        onChanged(*this, DB_Pressed, ticks, currentMillis);
    }
}

void IOBButton::fall(uint32_t currentMillis)
{
    if (onChanged)
        onChanged(*this, DB_Falling, ticks, currentMillis);
}

