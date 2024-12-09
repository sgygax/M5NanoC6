// An integrated one-dimensional/two-dimensional code scanning unit.
// This example uses the uart communication interface.
// - https://docs.m5stack.com/en/unit/Unit-QRCode
// - https://github.com/m5stack/M5Unit-QRCode

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "M5UnitQRCode.h"

//-------------------------------------------------------------------
M5UnitQRCodeUART qrcode;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (qrcode.begin(&Serial1, UNIT_QRCODE_UART_BAUD, 1, 2) == false) {
    Serial.print(".");
    delay(1000);
  }

  qrcode.setTriggerMode(AUTO_SCAN_MODE);
}

//-------------------------------------------------------------------
void loop(void)
{
  if (qrcode.available()) {
    String data = qrcode.getDecodeData();
    int length = data.length();

    Serial.print("length: ");
    Serial.println(length);

    Serial.print("data: ");
    Serial.println(data);

    Serial.println();
  }
}
