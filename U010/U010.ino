// Distanz-Sensor (25..1000mm) mit VL53L0x Chip
// - https://docs.m5stack.com/en/unit/TOF
// - https://github.com/adafruit/Adafruit_VL53L0X

//-------------------------------------------------------------------
#include <Adafruit_VL53L0X.h>

//-------------------------------------------------------------------
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  if (lox.begin() == false) {
    while (1) {
      Serial.println("Kein Distanz-Sensor gefunden...");
    }
  }

  lox.startRangeContinuous();
}

//-------------------------------------------------------------------
void loop(void)
{
  if (lox.isRangeComplete()) {
    Serial.print("Distanz: ");
    Serial.print( lox.readRange() );
    Serial.println(" mm");
  }

  //delay(100);
}
