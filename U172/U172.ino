// Distanz-Sensor (4..4000mm) mit VL53L1x Chip
// - https://docs.m5stack.com/en/unit/Unit-ToF4M
// - https://github.com/m5stack/M5Unit-ToF4M

//-------------------------------------------------------------------
#include <M5_ToF4M.h>

//-------------------------------------------------------------------
VL53L1X sensor;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  Wire.begin();

  sensor.setBus(&Wire);
  sensor.setTimeout(500);
  if (sensor.init() == false) {
    while (true) {
      Serial.println("Failed to detect and initialize sensor!");
    }
  }

  // Use long distance mode and allow up to 50000 us (50 ms) for a
  // measurement. You can change these settings to adjust the performance of
  // the sensor, but the minimum timing budget is 20 ms for short distance
  // mode and 33 ms for medium and long distance modes. See the VL53L1X
  // datasheet for more information on range and timing limits.
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  sensor.startContinuous(50);
}

//-------------------------------------------------------------------
void loop(void)
{
  if (sensor.dataReady()) {
    Serial.print("Distanz: ");
    Serial.print( sensor.read() );
    Serial.println(" mm");
  }

  if (sensor.timeoutOccurred()) {
    Serial.println(" TIMEOUT");
  }

  //delay(100);
}
