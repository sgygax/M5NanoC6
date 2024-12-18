// 2 Tasten
// - https://docs.m5stack.com/en/unit/dual_button

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
const int PIN_BUTTON_A = 1;
const int PIN_BUTTON_B = 2;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
}

//-------------------------------------------------------------------
void loop()
{
  bool button_a = digitalRead(PIN_BUTTON_A);
  bool button_b = digitalRead(PIN_BUTTON_B);

  Serial.print(button_a);
  Serial.print(", ");
  Serial.println(button_b);

  delay(100);
}
