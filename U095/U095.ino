// A 6-axis attitude sensor system using the MPU6886 chipset with 3-axis gravity accelerometer and 3-axis gyroscope.
// - https://docs.m5stack.com/en/unit/imu
// - https://github.com/tanakamasayuki/I2C_MPU6886

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "I2C_MPU6886.h"

//-------------------------------------------------------------------
const int I2C_ADR = 0x68;

I2C_MPU6886 imu(I2C_ADR, Wire);

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  Wire.begin();

  while (imu.begin() != 0) {
    Serial.print(".");
    delay(1000);
  }
}

//-------------------------------------------------------------------
void loop(void)
{
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
  float t;

  imu.getAccel(&ax, &ay, &az);
  imu.getGyro(&gx, &gy, &gz);
  imu.getTemp(&t);

  Serial.printf("%f, %f, %f, %f, %f, %f, %f\n", ax, ay, az, gx, gy, gz, t);

  delay(100);
}
