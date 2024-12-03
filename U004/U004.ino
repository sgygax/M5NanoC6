// An infrared radiation detecting system.
// - https://docs.m5stack.com/en/unit/PIR

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
  bool pir_status = digitalRead(PIN_DIGITAL_SIGNAL);

  Serial.print("PIR = ");
  Serial.println(pir_status);

  delay(1000);
}
