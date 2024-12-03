// A mini passive buzzer.
// - https://docs.m5stack.com/en/unit/buzzer

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
const int PIN_DIGITAL_SIGNAL = 2;

//-------------------------------------------------------------------
void setup(void)
{

}

//-------------------------------------------------------------------
void loop(void)
{
  tone(PIN_DIGITAL_SIGNAL, 500, 100);
  delay(1000);

  tone(PIN_DIGITAL_SIGNAL, 1000, 100);
  delay(1000);
  
  tone(PIN_DIGITAL_SIGNAL, 2000, 500);
  delay(2000);
}
