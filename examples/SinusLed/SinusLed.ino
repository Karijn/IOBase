#include "IOB.h"

int ledPin = 6;
int buttonPin = 4;

IOBButton b1(4);
IOBLedFader fader(5, ledPin);

void setup() {
  Serial.begin(115200);

  // put your setup code here, to run once:
  b1.onChangedCall(buttonChanged);
}

void loop() {
  IOBase::loopAll();
}

void buttonChanged(IOBButton& b, ButtonState state, int ticks, uint32_t us) {
  Serial.print("Button Changed -> isPressed: ");
  Serial.print(b.isPressed() ? "Pressed" : "Released");
  Serial.print(", state: ");
  switch (state) {
    case DB_Released: Serial.print("Released "); break;
    case DB_Raising: Serial.print("Raising "); break;
    case DB_Pressed: Serial.print("Pressed "); break;
    case DB_Falling: Serial.print("Falling "); break;
  }
  Serial.print(", ticks: ");
  Serial.println(ticks);
  if (state == DB_Falling) {
    Serial.println("Start blink");
    fader.start();
  }
}
