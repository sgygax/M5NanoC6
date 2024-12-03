// A infrared surface temperature measuring system using the MLX90614 chipset.
// - https://docs.m5stack.com/en/unit/ncir
// - https://github.com/adafruit/Adafruit-MLX90614-Library
// - https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/docs/datasheet/hat/MLX90614-Datasheet-Melexis_en.pdf

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include "Adafruit_MLX90614.h"

//-------------------------------------------------------------------
Adafruit_MLX90614 sensor;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (sensor.begin() == false) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("Emissivity = ");
  Serial.println(sensor.readEmissivity());
}

//-------------------------------------------------------------------
void loop(void)
{
  Serial.print("Ambient = "); 
  Serial.print(sensor.readAmbientTempC());
  Serial.print("*C \t");
  
  Serial.print("Object = "); 
  Serial.print(sensor.readObjectTempC()); 
  Serial.println("*C");

  delay(1000);
}
