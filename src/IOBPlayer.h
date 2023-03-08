#pragma once
#include "Arduino.h"
#include "IOBase.h"
#include "IOBProgmem.h"

struct IOBTimedTone {
  byte note;
  byte time : 7;
  byte stat : 1;
};

#define IOBMUSIC(music) (music), (sizeof(music) / sizeof(music[0]))

struct IOBSequence {
private:
  IOBTimedTone* tones;
  int tone_count;
  int current_index;
public:
  IOBSequence(IOBTimedTone* t, int cnt) {
    tones = t;
    tone_count = cnt;
    current_index = -1;
  };

  bool current(IOBTimedTone& tone) {
    if (current_index == -1) {
      current_index++;
    }
    if (current_index >= tone_count) {
      return false;
    }
#ifdef MPROGMEM
    tone = PROGMEM_getAnything(&tones[current_index]);
#else
    tone = tones[current_index];
#endif
    return true;
  };

  bool next(IOBTimedTone& tone) {
    current_index++;

    if (current_index >= tone_count) {
      return false;
    }
#ifdef MPROGMEM
    tone = PROGMEM_getAnything(&tones[current_index]);
#else
    tone = tones[current_index];
#endif
    return true;
  };

  void reset() {
    current_index = -1;
  }
};

struct IOBPlayer : IOBase {
private:
  unsigned long previousMillis = 0;
  unsigned long interval;

  IOBSequence* sequence;
  int buzzer_pin;
  IOBTimedTone current_tone;

public:
  int stat_time = 50;
  IOBPlayer(int pin) : IOBase() {
    buzzer_pin = pin;
    pinMode(buzzer_pin, OUTPUT);
  }

  bool isPlaying() {
    return running;
  }

  void setMusic(IOBSequence* seq, bool start = true) {
    stop();
    sequence = seq;
    sequence->reset();
    if (start) {
      running = true;
      playNote(millis());
    }
  }

  void loop(unsigned long currentMillis) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (!sequence->next(current_tone)) {
        running = false;
      } else {
        playNote(currentMillis);
      }
    }
  }

  void restart() {
    sequence->reset();
    running = true;
    playNote(millis());
  }

  void stop() {
    running = false;
    noTone(buzzer_pin);
  }

private:
  void playNote(unsigned long currentMillis) {
    previousMillis = currentMillis;
    if (sequence->next(current_tone)) {
      interval = 1000 / current_tone.time;
      if (current_tone.note != MIDI_R) {
        tone(buzzer_pin, getFreq(current_tone.note), interval - (current_tone.stat * stat_time));
      }
    }
  }

  inline unsigned int getFreq(int index) {
    switch(index) {
      case   0 : return 8;
      case   1 : return 9;
      case   2 : return 9;
      case   3 : return 10;
      case   4 : return 10;
      case   5 : return 11;
      case   6 : return 12;
      case   7 : return 12;
      case   8 : return 13;
      case   9 : return 14;
      case   10 : return 15;
      case   11 : return 15;
      case   12 : return 16;
      case   13 : return 17;
      case   14 : return 18;
      case   15 : return 19;
      case   16 : return 21;
      case   17 : return 22;
      case   18 : return 23;
      case   19 : return 25;
      case   20 : return 26;
      case   21 : return 28;
      case   22 : return 29;
      case   23 : return 31;
      case   24 : return 33;
      case   25 : return 35;
      case   26 : return 37;
      case   27 : return 39;
      case   28 : return 41;
      case   29 : return 44;
      case   30 : return 46;
      case   31 : return 49;
      case   32 : return 52;
      case   33 : return 55;
      case   34 : return 58;
      case   35 : return 62;
      case   36 : return 65;
      case   37 : return 69;
      case   38 : return 73;
      case   39 : return 78;
      case   40 : return 82;
      case   41 : return 87;
      case   42 : return 93;
      case   43 : return 98;
      case   44 : return 104;
      case   45 : return 110;
      case   46 : return 117;
      case   47 : return 123;
      case   48 : return 131;
      case   49 : return 139;
      case   50 : return 147;
      case   51 : return 156;
      case   52 : return 165;
      case   53 : return 175;
      case   54 : return 185;
      case   55 : return 196;
      case   56 : return 208;
      case   57 : return 220;
      case   58 : return 233;
      case   59 : return 247;
      case   60 : return 262;
      case   61 : return 277;
      case   62 : return 294;
      case   63 : return 311;
      case   64 : return 330;
      case   65 : return 349;
      case   66 : return 370;
      case   67 : return 392;
      case   68 : return 415;
      case   69 : return 440;
      case   70 : return 466;
      case   71 : return 494;
      case   72 : return 523;
      case   73 : return 554;
      case   74 : return 587;
      case   75 : return 622;
      case   76 : return 659;
      case   77 : return 698;
      case   78 : return 740;
      case   79 : return 784;
      case   80 : return 831;
      case   81 : return 880;
      case   82 : return 932;
      case   83 : return 988;
      case   84 : return 1047;
      case   85 : return 1109;
      case   86 : return 1175;
      case   87 : return 1245;
      case   88 : return 1319;
      case   89 : return 1397;
      case   90 : return 1480;
      case   91 : return 1568;
      case   92 : return 1661;
      case   93 : return 1760;
      case   94 : return 1865;
      case   95 : return 1976;
      case   96 : return 2093;
      case   97 : return 2217;
      case   98 : return 2349;
      case   99 : return 2489;
      case  100 : return 2637;
      case  101 : return 2794;
      case  102 : return 2960;
      case  103 : return 3136;
      case  104 : return 3322;
      case  105 : return 3520;
      case  106 : return 3729;
      case  107 : return 3951;
      case  108 : return 4186;
      case  109 : return 4435;
      case  110 : return 4699;
      case  111 : return 4978;
      case  112 : return 5274;
      case  113 : return 5588;
      case  114 : return 5920;
      case  115 : return 6272;
      case  116 : return 6645;
      case  117 : return 7040;
      case  118 : return 7459;
      case  119 : return 7902;
      case  120 : return 8372;
      case  121 : return 8870;
      case  122 : return 9397;
      case  123 : return 9956;
      case  124 : return 10548;
      case  125 : return 11175;
      case  126 : return 11840;
      case  127 : return 12544;
      case  128 : return 13290;
    }
	  return 0;
  }
};
