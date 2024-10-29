// RFID Lese-/Schreibeinheit (13.56MHz).
// https://docs.m5stack.com/en/unit/rfid2
// https://github.com/OSSLibraries/Arduino_MFRC522v2/tree/master

//-------------------------------------------------------------------
#include <MFRC522v2.h>
#include <MFRC522DriverI2C.h>
#include <MFRC522Debug.h>

//-------------------------------------------------------------------
const int ADR_I2C_RFID2 = 0x28;

const int PIN_I2C_SDA = 2;
const int PIN_I2C_SCL = 1;

MFRC522DriverI2C driver{ADR_I2C_RFID2, Wire};
MFRC522 mfrc522(driver);

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL, 100000);

  mfrc522.PCD_Init();
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
