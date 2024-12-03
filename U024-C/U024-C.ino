// Joystick mit Tastenfunktion
// - https://docs.m5stack.com/en/unit/joystick_1.1

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include <Wire.h>

//-------------------------------------------------------------------
const int ADR_I2C_JOYSTICK = 0x52;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  Wire.begin(SDA, SCL, 400000);
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
