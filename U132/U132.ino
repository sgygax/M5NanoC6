// A mini passive buzzer.
// - https://docs.m5stack.com/en/unit/buzzer

//-------------------------------------------------------------------
const int PIN_DIGITAL_SIGNAL = 2;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);
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
