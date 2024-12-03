// Dreh-Potentiometer
// - https://docs.m5stack.com/en/unit/angle

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
const int PIN_ANALOG_SIGNAL = 1;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  pinMode(PIN_ANALOG_SIGNAL, INPUT);
}

//-------------------------------------------------------------------
void loop(void)
{
  int angle_status = analogRead(PIN_ANALOG_SIGNAL);

  Serial.print("angle_status = ");
  Serial.println(angle_status);

  delay(50);
}
