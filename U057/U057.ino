// Gabel-Lichtschranke 90°
// - https://docs.m5stack.com/en/unit/OP.90

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
const int PIN_DIGITAL_SIGNAL = 1;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  pinMode(PIN_DIGITAL_SIGNAL, INPUT);
}

//-------------------------------------------------------------------
void loop(void)
{
  bool sensor_status = digitalRead(PIN_DIGITAL_SIGNAL);

  Serial.print("sensor_status = ");
  Serial.println(sensor_status);

  delay(100);
}
