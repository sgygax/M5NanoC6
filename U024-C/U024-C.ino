// Joystick mit Tastenfunktion
// https://docs.m5stack.com/en/unit/joystick_1.1

//-------------------------------------------------------------------
#include <Wire.h>

//-------------------------------------------------------------------
const int ADR_I2C_JOYSTICK = 0x52;

const int PIN_I2C_SDA = 2;
const int PIN_I2C_SCL = 1;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL, 400000);
}

//-------------------------------------------------------------------
void loop()
{
  int x_achse;
  int y_achse;
  int z_achse;

  Wire.requestFrom(ADR_I2C_JOYSTICK, 3);

  if (Wire.available()) {
    x_achse = Wire.read();
    y_achse = Wire.read();
    z_achse = Wire.read();

    Serial.print("X = ");
    Serial.print(x_achse);
    Serial.print(", Y = ");
    Serial.print(y_achse);
    Serial.print(", Z = ");
    Serial.println(z_achse);
  }

  delay(100);
}
