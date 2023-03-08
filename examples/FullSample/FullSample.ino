#include "IOBase.h"

IOBFlasher l1(4, false);
IOBFlasher l2(13, false);
IOBButton b1(6);
IOBTimer t1(5000);
IOBTimer t2(100, 3);

void setup() {
  // set the digital pin as output:
  Serial.begin(115200);

  b1.onChangedCall(buttonChanged);

  l1.flash(300, 10);
  l2.flash(500, 10, true);
  t1.onTickCall(onTick1);
  t2.onTickCall(onTick2);
  t1.start();
  Serial.println("Startup...");
}

void loop() {
  IOBase::loopAll();
}

void buttonChanged(IOBButton& b, ButtonState state, int ticks, unsigned long us) {
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
    l1.setRunning(!l1.isRunning());
    t2.start();
  }
}

void onTick1(IOBTimer& timer, int ticks) {
  Serial.print("On Tick1: ");
  Serial.println(ticks);
}

void onTick2(IOBTimer& timer, int ticks) {
  Serial.print("On Tick2: ");
  Serial.println(ticks);
}
