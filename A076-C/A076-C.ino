// Servo Kit 360°
// - https://docs.m5stack.com/en/accessory/servo_kit_360

//-------------------------------------------------------------------
#include <ESP32Servo.h>

//-------------------------------------------------------------------
#define PIN_PWM  2

//-------------------------------------------------------------------
Servo servo1;

//-------------------------------------------------------------------
void setup(void)
{
  servo1.attach(PIN_PWM);
}

//-------------------------------------------------------------------
void loop(void)
{
  // w:    0 .. 90 ..  180
  // v: -max ..  0 .. +max

  servo1.write(90);
  delay(2000);

  servo1.write(135);
  delay(2000);

  servo1.write(180);
  delay(2000);

  servo1.write(90);
  delay(2000);

  servo1.write(45);
  delay(2000);

  servo1.write(0);
  delay(2000);
}
