// 8 x Dreh-Potentiometer, 1 Schiebeschalter und 9 Neopixel RGB-LED mit MCU.
// https://docs.m5stack.com/en/unit/8Angle
// https://github.com/RobTillaart/M5ANGLE8

#include "m5angle8.h"

//-------------------------------------------------------------------
M5ANGLE8 angle8;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  Wire.begin();
  angle8.begin();

  angle8.setReverse(false);

  angle8.writeRGB(0, 255, 0, 0, 5);
  angle8.writeRGB(1, 255, 255, 0, 5);
  angle8.writeRGB(2, 0, 255, 0, 5);
  angle8.writeRGB(3, 0, 255, 255, 5);
  angle8.writeRGB(4, 0, 0, 255, 5);
  angle8.writeRGB(5, 255, 0, 255, 5);
  angle8.writeRGB(6, 255, 0, 0, 5);
  angle8.writeRGB(7, 255, 255, 0, 5);
  
  angle8.writeRGB(8, 255, 255, 255, 5);
}

//-------------------------------------------------------------------
void loop(void)
{
  for (int ch = 0; ch <= 7; ch++) {
    
    //Serial.print( angle8.analogRead(ch, 8) );

    Serial.print( angle8.selectorRead(ch, 10) );
    
    Serial.print("\t");
    delay(10);
  }

  Serial.println(angle8.inputSwitch());

  delay(100);
}
