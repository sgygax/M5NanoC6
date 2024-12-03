// A high-sensitivity infrared sensor system for presence and motion detection using the STHS34PF80 chipset.
// - https://docs.m5stack.com/en/unit/UNIT-TMOS%20PIR
// - https://github.com/m5stack/M5-STHS34PF80
// - https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/docs/products/unit/UNIT-TMOS%20PIR/STHS34PF80_Datasheet.pdf

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "M5_STHS34PF80.h"

//-------------------------------------------------------------------
const int I2C_ADR = 0x5A;

M5_STHS34PF80 sensor;

sths34pf80_tmos_drdy_status_t dataReady;
sths34pf80_tmos_func_status_t status;

int16_t presenceValue = 0;
int16_t motionValue = 0;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (sensor.begin(&Wire, I2C_ADR, SDA, SCL) == false) {
    Serial.print(".");
    delay(1000);
  }

  sensor.setTmosODR(STHS34PF80_TMOS_ODR_AT_2Hz);

  sensor.setPresenceThreshold(0xC8);  
  sensor.setPresenceHysteresis(0x32);

  sensor.setMotionThreshold(0xC8);
  sensor.setMotionHysteresis(0x32);

  sensor.setGainMode(STHS34PF80_GAIN_WIDE_MODE);
  sensor.setTmosSensitivity(0xFF);
  
  sensor.resetAlgo();  
}

//-------------------------------------------------------------------
void loop(void)
{
  sensor.getDataReady(&dataReady);

  if (dataReady.drdy == 1) {
    sensor.getStatus(&status);
    sensor.getPresenceValue(&presenceVal);
    sensor.getMotionValue(&motionVal);
    
    Serial.printf("Presence: %d\t", presenceValue);
    Serial.printf("PresenceFlag: %d\t", status.pres_flag);    
    Serial.printf("Motion: %d\t", motionValue);
    Serial.printf("MotionFlag: %d\r\n", status.mot_flag);
  }
}
