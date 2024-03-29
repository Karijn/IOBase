#include "IOB.h"

IOBFlasher l1(6);
IOBButton b1(4);
IOBTimer t1(5000);
IOBTimer t2(100, 3);
IOBOneshot o(13, 1000);

void setup() {
  // set the digital pin as output:
  Serial.begin(115200);
  
  b1.onChangedCall(buttonChanged);

  l1.flash(1000, 50);
  t1.onTickCall(onTick1);
  t2.onTickCall(onTick2);
  t1.start();
  Serial.println("Startup...");

}

void loop() {
  IOBase::loopAll();

  if(Serial.available()){
    Serial.println("Oneshow stared");
    Serial.read();
    o.start();
  }
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
    l1.isRunning() ? l1.stop() : l1.start();
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
