
#include <Arduino.h>
#include "IOBFlasher.h"

void IOBFlasher::flash( int ms_period,       // Time for one full flash in 1000th of a second
                        uint8_t dutyCyclePct,  // Percentage on. 50 is equal on/off parts
                        bool startOn          // Cycle starts with lamp on (default) or off
                      ) {
  start();                            // We are now flashing
  firstState = startOn;                       // Remember first part period state
  cycleStart = millis();                      // Record start of this cycle
  period = ms_period;                         // Remember the full cycle time
  firstPart = period * (dutyCyclePct / 100);  // and the first part time
}

void IOBFlasher::loop(uint32_t currentMillis) {                // Do "timed" things (like running)
  uint32_t elapsed = currentMillis - cycleStart;          // Compute ms since last update
  if (elapsed > period) {                       // If elapsed > than our cycle start time:
    cycleStart += period * (elapsed / period);  //    compute the new cycle start time
    elapsed = elapsed % period;                 //    and adjust elapsed
  }
  if (elapsed <= firstPart)  // Now set lamp as we need it
    digitalWrite(lampDriverPin, inverted ^ firstState );
  else
    digitalWrite(lampDriverPin, inverted ^ !firstState );
}
