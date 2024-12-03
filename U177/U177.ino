// An mini weighing system with a 5kg weighing sensor, 1 button and 1 Neopixel RGB-LED.
// - https://docs.m5stack.com/en/unit/Unit-Mini%20Scales
// - https://github.com/m5stack/M5Unit-Miniscale (--> Download as ZIP file and install it manually)

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "UNIT_SCALES.h"

//-------------------------------------------------------------------
UNIT_SCALES scales;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (scales.begin(&Wire, SDA, SCL) == false) {
    Serial.print(".");
    delay(1000);
  }

  scales.setLEDColor(0xFF0000); // red
  delay(1000);

  scales.setOffset();

  scales.setLEDColor(0x00FF00); // green
}

//-------------------------------------------------------------------
void loop(void)
{
  float weight = scales.getWeight();
  float gap    = scales.getGapValue();
  int adc      = scales.getRawADC();
  bool button  = scales.getBtnStatus();

  Serial.printf("ADC: %d\t WEIGHT: %.2fg\t GAP: %.2f\t BTN: %d\r\n", adc, weight, gap, button);

  delay(1000);
}
