// A digital multi-pixel gas sensor using the SGP30 chipset.
// It detects the concentration of TVOCs (Total Volatile Organic Compounds) and eCO2 (equivalent carbon dioxide).
// - https://docs.m5stack.com/en/unit/tvoc
// - https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/docs/datasheet/unit/Sensirion_Gas_Sensors_SGP30_Datasheet.pdf
// - https://github.com/adafruit/Adafruit_SGP30

//-------------------------------------------------------------------
#include "Adafruit_SGP30.h"

//-------------------------------------------------------------------
Adafruit_SGP30 sgp;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (sgp.begin() == false) {
    Serial.print(".");
    delay(1000);
  }
}

//-------------------------------------------------------------------
void loop(void)
{
  if (sgp.IAQmeasure() == true) {
    // TVOC = Total Volatile Organic Compounds (Gesamtkonzentration flüchtiger organischer Verbindungen)
    // Es handelt sich um eine Sammelbezeichnung für gasförmige, organische Chemikalien, die leicht verdampfen
    // und in der Luft vorkommen. Diese Verbindungen stammen aus Quellen wie Farben,
    // Lacken, Reinigungsmitteln, Möbeln oder Bauprodukten.
    // ppm = parts per million (=Million=1'000'000)
    // - 0..300 ppm    = sehr gut
    // - 300..500 ppm  = akzeptabel
    // - 500..1000 ppm = mässig
    // - 1000..??? ppm = schlecht
    Serial.printf("TVOC(ppb):%d \t", sgp.TVOC);

    // eCO2 = equivalent CO₂
    // Es ist keine direkte Messung des tatsächlichen CO₂-Gehalts, sondern eine Näherung basierend auf TVOC-Werten.
    // ppb = parts per billion (=Milliarde=1'000'000'000)
    // - 350..600 ppb    = sehr gut
    // - 600..1000 ppb   = akzeptabel
    // - 1000...2000 ppb = mässig
    // - 2000...???  ppb = schlecht
    Serial.printf("eCO2(ppm):%d \n", sgp.eCO2);
  }

  delay(1000);
}
