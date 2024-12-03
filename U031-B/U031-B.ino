// RFID Lese-/Schreibeinheit (13.56MHz).
// - https://docs.m5stack.com/en/unit/rfid2
// - https://github.com/OSSLibraries/Arduino_MFRC522v2/tree/master

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include <MFRC522v2.h>
#include <MFRC522DriverI2C.h>
#include <MFRC522Debug.h>

//-------------------------------------------------------------------
MFRC522DriverI2C driver;
MFRC522 mfrc522(driver);

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  while (mfrc522.PCD_Init() == false) {
    Serial.print(".");
    delay(1000);
  }
}

//-------------------------------------------------------------------
void loop()
{
  if (mfrc522.PICC_IsNewCardPresent() &&  mfrc522.PICC_ReadCardSerial()) {

    Serial.println("*** A ***");
    Serial.print("Card UID: ");
    for (int i = 0; i < mfrc522.uid.size; i++) {
      int b = mfrc522.uid.uidByte[i];
      Serial.printf("%02X ", b);
    }
    Serial.println("");
    Serial.println("");

    Serial.println("*** B ***");
    Serial.print("Card UID:");
    MFRC522Debug::PrintSelectedUID(mfrc522, Serial);
    Serial.println("");
    Serial.println("");
    
    Serial.println("*** C ***");
    MFRC522Debug::PICC_DumpDetailsToSerial(mfrc522, Serial, &mfrc522.uid);
    Serial.println("");

    Serial.println("*** D ***");
    MFRC522Debug::PICC_DumpToSerial(mfrc522, Serial, &mfrc522.uid);
    Serial.println("");
  }
}
