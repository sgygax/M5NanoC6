// Dreh-Encoder mit Tastenfunktion.
// - https://docs.m5stack.com/en/unit/encoder

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include <Unit_Encoder.h>

//-------------------------------------------------------------------
Unit_Encoder sensor;

int last_value = 0;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  sensor.begin();
}

//-------------------------------------------------------------------
void loop()
{
  // einlesen
  bool btn_status = sensor.getButtonStatus();
  int encoder_value = sensor.getEncoderValue();

  // serial ausgabe
  Serial.print(btn_status);
  Serial.print(", ");
  Serial.println(encoder_value);

  // leds setzen
  if (last_value != encoder_value) {
    if (last_value < encoder_value) {
      sensor.setLEDColor(1, 0x0000FF); // RRGGBB
    }
    else {
      sensor.setLEDColor(2, 0x0000FF); // RRGGBB
    }
    last_value = encoder_value;
  }
  else {
    sensor.setLEDColor(0, 0x001100); // RRGGBB
  }

  if (btn_status == false) {
    sensor.setLEDColor(0, 0xFF0000); // RRGGBB
  }

  delay(50);
}
