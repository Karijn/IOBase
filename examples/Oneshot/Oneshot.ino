#include "IOB.h"

IOBOneshot o1( 1000, 6);

bool didStart = false;

void setup() {
  // set the digital pin as output:
  Serial.begin(115200);
  
  Serial.println("Startup...");
}

void loop() {
  IOBase::loopAll();

  if(Serial.available()){
    Serial.println("Oneshow stared");
    Serial.read();

    o1.start();
  }
}

