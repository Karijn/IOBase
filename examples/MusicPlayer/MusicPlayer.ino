#include "IOBase.h"
#include "IOBPitches.h"
#include "IOBplayer.h"
#include "tunes.h"
#include "IOBProgmem.h"

const int buzzer_pin = 5;
const int button_pin = 6;

IOBButton b1(6);
IOBPlayer player(buzzer_pin);

IOBSequence melody_music1(IOBMUSIC(music1));
IOBSequence melody_music2(IOBMUSIC(music2));
IOBSequence melody_underworld(IOBMUSIC(underworld_melody));
IOBSequence melody_shaveAndAHairCut(IOBMUSIC(melody_SHAVEANDHAIRCUT));
IOBSequence melody_ready(IOBMUSIC(melody_READY));
IOBSequence melody_processing(IOBMUSIC(melody_PROCESSING));
IOBSequence melody_complete(IOBMUSIC(melody_COMPLETE));
IOBSequence melody_idle(IOBMUSIC(melody_IDLE));

void setup() {
  Serial.begin(115200);
}

int mcnt = 0;

void loop() {

  if (b1.isFalling() && !player.isPlaying()) {
    // Serial.println("restart");
    mcnt = ++mcnt % 8;
    Serial.print("Start playing: ");
    switch (mcnt) {
      case 0:
        Serial.println("melody idle");
        player.setMusic(&melody_idle);
        break;
      case 1:
        Serial.println("melody ready");
        player.setMusic(&melody_ready);
        break;
      case 2:
        Serial.println("melody processing");
        player.setMusic(&melody_processing);
        break;
      case 3:
        Serial.println("melody music1");
        player.setMusic(&melody_music1);
        break;
      case 4:
        Serial.println("melody music2");
        player.setMusic(&melody_music2);
        break;
      case 5:
        Serial.println("melody complete");
        player.setMusic(&melody_complete);
        break;
      case 6:
        Serial.println("melody underworld");
        player.setMusic(&melody_underworld);
        break;
      case 7:
        Serial.println("melody shaveAndAHairCut");
        player.setMusic(&melody_shaveAndAHairCut);
        break;
    }
    player.restart();
  }

  unsigned long currentMillis = millis();
  IOBase::loopAll();
  //  player.loop(currentMillis);
}