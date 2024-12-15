// A fingerprint sensor based on the FPC1020A chipset.
// - https://docs.m5stack.com/en/unit/finger
// - http://www.shenzhen2u.com/doc/Module/Fingerprint/710-FPC1020_PB3_Product-Specification.pdf
// - https://github.com/m5stack/M5-FPC1020A
//   IMPORTANT:
//   Download as ZIP file and install it manually !!!

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "M5_FPC1020A.h"

//-------------------------------------------------------------------
const int PIN_UART1_RX = 1;
const int PIN_UART1_TX = 2;

M5_FPC1020A finger;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (finger.begin(&Serial1, PIN_UART1_RX, PIN_UART1_TX, 19200) == false) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("Delete all fingers... ");
  finger.delAllFinger();
  Serial.println("done");
  Serial.println("");

  // id(0..255), permission(0..255)
  addNewFinger(1, 1);

  Serial.print("Number of fingers stored in the system: ");
  Serial.println(finger.getUserCount());
  Serial.println("");
}

//-------------------------------------------------------------------
void loop(void)
{
  if (finger.available(1000) == ACK_SUCCESS) {
    Serial.print("Finger ID: ");
    Serial.println(finger.getFingerID());
    Serial.print("Permission: ");
    Serial.println(finger.getFingerPermission());
  }
  else {
    Serial.println("No User");
  }
}

//-------------------------------------------------------------------
void addNewFinger(uint8_t aID, uint8_t aPermission)
{
  Serial.println("*********************************************");
  Serial.printf("Finger ID:  %d \n", aID);
  Serial.printf("Permission: %d \n", aPermission);
  Serial.println("Please, put your finger on the sensor...");

  for (uint8_t i = 0; i < 6; i++) {
    Serial.printf("Scan %d of 6 ...", i + 1);
    while (finger.addFinger(aID, aPermission, i) == false) {
      Serial.print(".");
      delay(500);
    }
    Serial.println(" done");
  }

  Serial.println("*********************************************");
}
