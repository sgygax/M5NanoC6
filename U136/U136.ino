// Umgebungslicht-Sensor mit BH1750FVI Chip
// https://docs.m5stack.com/en/unit/DLight%20Unit
// https://github.com/m5stack/M5-DLight/tree/master

//-------------------------------------------------------------------
#include <M5_DLight.h>

//-------------------------------------------------------------------
M5_DLight sensor;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  sensor.begin();

  // CONTINUOUSLY_H_RESOLUTION_MODE
  // CONTINUOUSLY_H_RESOLUTION_MODE2
  // CONTINUOUSLY_L_RESOLUTION_MODE
  // ONE_TIME_H_RESOLUTION_MODE
  // ONE_TIME_H_RESOLUTION_MODE2
  // ONE_TIME_L_RESOLUTION_MODE
  sensor.setMode(CONTINUOUSLY_H_RESOLUTION_MODE);
}

//-------------------------------------------------------------------
void loop(void)
{
  int lux = sensor.getLUX();

  Serial.print("lux: ");
  Serial.print(lux);
  Serial.println(" lx");
  
  delay(100);
}
