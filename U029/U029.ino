// A pulse oximetry and heart-rate sensor system using the MAX30100 chipset.
// - https://docs.m5stack.com/en/unit/heart
// - https://github.com/oxullo/Arduino-MAX30100

//-------------------------------------------------------------------
#include "MAX30100_PulseOximeter.h"

//-------------------------------------------------------------------
PulseOximeter pox;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (pox.begin() == false) {
    Serial.print(".");
    delay(1000);
  }

  //  0 =  0mA   = MAX30100_LED_CURR_0MA,
  //  1 =  4.4mA = MAX30100_LED_CURR_4_4MA,
  //  2 =  7.6mA = MAX30100_LED_CURR_7_6MA,
  //  3 = 11mA   = MAX30100_LED_CURR_11MA,
  //  4 = 14.2mA = MAX30100_LED_CURR_14_2MA,
  //  5 = 17.4mA = MAX30100_LED_CURR_17_4MA,
  //  6 = 20.8mA = MAX30100_LED_CURR_20_8MA,
  //  7 = 24mA   = MAX30100_LED_CURR_24MA,
  //  8 = 27.1mA = MAX30100_LED_CURR_27_1MA,
  //  9 = 30.6mA = MAX30100_LED_CURR_30_6MA,
  // 10 = 33.8mA = MAX30100_LED_CURR_33_8MA,
  // 11 = 37mA   = MAX30100_LED_CURR_37MA,
  // 12 = 40.2mA = MAX30100_LED_CURR_40_2MA,
  // 13 = 43.6mA = MAX30100_LED_CURR_43_6MA,
  // 14 = 46.8mA = MAX30100_LED_CURR_46_8MA,
  // 15 = 50mA   = MAX30100_LED_CURR_50MA(default)
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}

//-------------------------------------------------------------------
void loop(void)
{
  static unsigned int timestamp = 0;

  pox.update();

  // T=1000ms (f=1 Hz)
  if ((millis() - timestamp) >= 1000) {
    timestamp = millis();

    Serial.print("Heartrate(bpm):");
    Serial.print(pox.getHeartRate());
    Serial.print(", ");

    Serial.print("SpO2(%):");
    Serial.println(pox.getSpO2());
  }
}
