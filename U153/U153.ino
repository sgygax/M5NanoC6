// 8 rotary encoder knobs with button function, 1 toggle switch and 9 Neopixel RGB-LED.
// - https://docs.m5stack.com/en/unit/8Encoder
// - https://github.com/m5stack/M5Unit-8Encoder

//-------------------------------------------------------------------
#include "UNIT_8ENCODER.h"

//-------------------------------------------------------------------
UNIT_8ENCODER encoder8;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  Wire.begin();

  while (encoder8.begin(&Wire, 0x41, SDA, SCL) == false) {
    Serial.print(".");
    delay(1000);
  }

  encoder8.setLEDColor(0, 0xFF0000);
  encoder8.setLEDColor(1, 0xFFFF00);
  encoder8.setLEDColor(2, 0x00FF00);
  encoder8.setLEDColor(3, 0x00FFFF);
  encoder8.setLEDColor(4, 0x0000FF);
  encoder8.setLEDColor(5, 0xFF00FF);
  encoder8.setLEDColor(6, 0xFF0000);
  encoder8.setLEDColor(7, 0xFFFF00);

  encoder8.setLEDColor(8, 0x00FF00);
}

//-------------------------------------------------------------------
void loop(void)
{
  for (int ch = 0; ch <= 7; ch++) {

    Serial.print( (int)encoder8.getEncoderValue(ch) );

    Serial.print(" (");
    Serial.print( encoder8.getButtonStatus(ch) );
    Serial.print(")");

    Serial.print("\t");
    delay(10);
  }

  Serial.println(encoder8.getSwitchStatus());

  delay(100);
}
