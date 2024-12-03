// 7-Segmentanzeige mit 4  Stellen und Punkten (0.0.:0.0.)
// - https://docs.m5stack.com/en/unit/digi_clock

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include <Wire.h>
#include <M5UNIT_DIGI_CLOCK.h>

//-------------------------------------------------------------------
const int ADR_I2C_DIGICLOCK = 0x30;

M5UNIT_DIGI_CLOCK Digiclock;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  while (Digiclock.begin(&Wire, SDA, SCL, ADR_I2C_DIGICLOCK) == false) {
    Serial.print(".");
    delay(1000);
  }

  // anzeige löschen
  char buff[] = "    ";
  Digiclock.setString(buff);
  delay(2000);
}

//-------------------------------------------------------------------
void loop()
{
  // zeichen
  char buff[] = "0.1.:2.3.";
  Digiclock.setString(buff);
  delay(1000);

  // on / off
  for (int i = 0; i < 5; i++) {
    Digiclock.setBrightness(9);
    delay(250);
    Digiclock.setBrightness(0);
    delay(250);
  }
  delay(1000);

  // dimmen
  for (int i = 0; i < 4; i++) {
    for (int8_t i = 0; i < 9; i++) {
      Digiclock.setBrightness(i);
      delay(250);
    }
    for (int8_t i = 8; i >= 0; i--) {
      Digiclock.setBrightness(i);
      delay(250);
    }
  }
  delay(1000);

  // zahlen
  Digiclock.setBrightness(9);
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 10; i++) {
      sprintf(buff, "%d.%d.:%d.%d.", i, i, i, i);
      Digiclock.setString(buff);
      Serial.println(buff);
      delay(500);
    }
  }
  delay(1000);

  // zeit mit sekundentakt
  Digiclock.setBrightness(9);
  for (int x = 0; x < 10; x++) {
    char buff2[] =  "12:00";
    Digiclock.setString(buff2);
    Serial.printf(buff2);
    delay(500);
    char buff3[] =  "1200";
    Digiclock.setString(buff3);
    Serial.printf(buff3);
    delay(500);
  }
  delay(1000);
}
