#pragma once
#include "Arduino.h"
#include "IOBProgmem.h"
#include "IOBPlayer.h"

//#pragma pack(push, 1)

const IOBTimedTone music1[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C4, 4, true },
      { MIDI_G3, 8, true },
      { MIDI_G3, 8, true },
      { MIDI_A3, 4, true },
      { MIDI_G3, 4, false },
      { MIDI_R, 4, false },
      { MIDI_B3, 4, true },
      { MIDI_C4, 4, true },
    };

//Mario main theme melody
const IOBTimedTone music2[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_E7, 6, true },
      { MIDI_E7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_E7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_C7, 6, true },
      { MIDI_E7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_G7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_G6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_C7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_G6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_E6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_A6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_B6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_AS6, 6, true },
      { MIDI_A6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_G6, 4.5, true },
      { MIDI_E7, 4.5, true },
      { MIDI_G7, 4.5, true },
      { MIDI_A7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_F7, 6, true },
      { MIDI_G7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_E7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_C7, 6, true },
      { MIDI_D7, 6, true },
      { MIDI_B6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_C7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_G6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_E6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, true },
      { MIDI_A6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_B6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_AS6, 6, true },
      { MIDI_A6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_G6, 4.5, true },
      { MIDI_E7, 4.5, true },
      { MIDI_G7, 4.5, true },
      { MIDI_A7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_F7, 6, true },
      { MIDI_G7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_E7, 6, true },
      { MIDI_R, 6, true },
      { MIDI_C7, 6, true },
      { MIDI_D7, 6, true },
      { MIDI_B6, 6, true },
      { MIDI_R, 6, true },
      { MIDI_R, 6, 5 },
    };

//Underworld melody
const IOBTimedTone underworld_melody[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C4, 6, true },
      { MIDI_C5, 6, true },
      { MIDI_A3, 6, true },
      { MIDI_A4, 6, true },
      { MIDI_AS3, 6, true },
      { MIDI_AS4, 6, true },
      { MIDI_R, 2, true },
      { MIDI_R, 1.5, true },
      { MIDI_C4, 6, true },
      { MIDI_C5, 6, true },
      { MIDI_A3, 6, true },
      { MIDI_A4, 6, true },
      { MIDI_AS3, 6, true },
      { MIDI_AS4, 6, true },
      { MIDI_R, 2, true },
      { MIDI_R, 1.5, true },
      { MIDI_F3, 6, true },
      { MIDI_F4, 6, true },
      { MIDI_D3, 6, true },
      { MIDI_D4, 6, true },
      { MIDI_DS3, 6, true },
      { MIDI_DS4, 6, true },
      { MIDI_R, 2, true },
      { MIDI_R, 1.5, true },
      { MIDI_F3, 6, true },
      { MIDI_F4, 6, true },
      { MIDI_D3, 6, true },
      { MIDI_D4, 6, true },
      { MIDI_DS3, 6, true },
      { MIDI_DS4, 6, true },
      { MIDI_R, 2, true },
      { MIDI_R, 2, true },
      { MIDI_DS4, 9, true },
      { MIDI_CS4, 9, true },
      { MIDI_D4, 9, true },
      { MIDI_CS4, 2, true },
      { MIDI_DS4, 2, true },
      { MIDI_DS4, 2, true },
      { MIDI_GS3, 2, true },
      { MIDI_G3, 2, true },
      { MIDI_CS4, 2, true },
      { MIDI_C4, 9, true },
      { MIDI_FS4, 9, true },
      { MIDI_F4, 9, true },
      { MIDI_E3, 9, true },
      { MIDI_AS4, 9, true },
      { MIDI_A4, 9, true },
      { MIDI_GS4, 5, true },
      { MIDI_DS4, 5, true },
      { MIDI_B3, 5, true },
      { MIDI_AS3, 5, true },
      { MIDI_A3, 5, true },
      { MIDI_GS3, 5, true },
      { MIDI_R, 1.5, true },
      { MIDI_R, 1.5, true },
      { MIDI_R, 1.5, true },
    };

// * Shave and a haircut
const IOBTimedTone melody_SHAVEANDHAIRCUT[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C4, 4, true },
      { MIDI_G3, 8, true },
      { MIDI_G3, 8, true },
      { MIDI_A3, 4, true },
      { MIDI_G3, 4, true },
      { MIDI_R, 4, true },
      { MIDI_B3, 4, true },
      { MIDI_C4, 4, true },
      { MIDI_R, 4, true },
    };

const IOBTimedTone melody_READY[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C3, 8, true },
      { MIDI_C3, 8, true },
      { MIDI_R, 4, true },
      { MIDI_C4, 8, true },
      { MIDI_C4, 8, true },
      { MIDI_R, 4, true },
      { MIDI_C3, 8, true },
      { MIDI_C3, 8, true },
    };

const IOBTimedTone melody_PROCESSING[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C3, 8, true },
      { MIDI_D3, 8, true },
      { MIDI_E3, 8, true },
      { MIDI_D3, 8, true },
      { MIDI_C3, 8, true },
      { MIDI_D3, 8, true },
      { MIDI_E3, 8, true },
      { MIDI_D3, 8, true },
    };

const IOBTimedTone melody_COMPLETE[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C4, 8, true },
      { MIDI_C4, 8, true },
      { MIDI_C4, 8, true },
      { MIDI_C4, 2, true },
    };

const IOBTimedTone melody_IDLE[]
#ifdef MPROGMEM
  PROGMEM
#endif
  = {
      { MIDI_C3, 8, true },
      { MIDI_C3, 4, true },
      { MIDI_C3, 8, true },
      { MIDI_E3, 8, true },
      { MIDI_C3, 8, true },
      { MIDI_F3, 8, true },
      { MIDI_G3, 4, true },
      { MIDI_R, 2, true },
      { MIDI_G3, 8, true },
      { MIDI_G3, 4, true },
      { MIDI_F3, 8, true },
      { MIDI_D3, 8, true },
      { MIDI_E3, 8, true },
      { MIDI_C3, 8, true },
    };
//#pragma pack(pop)
