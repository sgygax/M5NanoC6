// An audio module designed specifically for MIDI sound systems using the SAM2695 audio synthesizer.
// - https://docs.m5stack.com/en/unit/Unit-Synth
// - https://github.com/m5stack/M5Unit-Synth
// - https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/docs/products/unit/Unit-Synth/SAM2695.pdf

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "M5UnitSynth.h"

//-------------------------------------------------------------------
const int PIN_UART1_RX = 1;
const int PIN_UART1_TX = 2;

M5UnitSynth synth;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  synth.begin(&Serial1, UNIT_SYNTH_BAUD, PIN_UART1_RX, PIN_UART1_TX);
}

//-------------------------------------------------------------------
void loop(void)
{
  synth.setInstrument(0, 9, SynthDrum);

  synth.setNoteOn(9, 36, 127);
  synth.setNoteOn(9, 42, 127);
  delay(300);
  synth.setNoteOn(9, 42, 127);
  delay(300);
  synth.setNoteOn(9, 38, 127);
  synth.setNoteOn(9, 42, 127);
  delay(300);
  synth.setNoteOn(9, 42, 127);
  delay(300);

  synth.setNoteOn(9, 36, 127);
  synth.setNoteOn(9, 42, 127);
  delay(300);
  synth.setNoteOn(9, 36, 127);
  synth.setNoteOn(9, 42, 127);
  delay(300);
  synth.setNoteOn(9, 38, 127);
  synth.setNoteOn(9, 42, 127);
  delay(300);
  synth.setNoteOn(9, 42, 127);
  delay(300);

  delay(3000);
}
