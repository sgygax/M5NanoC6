// Die eingebaute blaue LED des M5NanoC6 mit PWM ansteuern.
// - https://docs.m5stack.com/en/core/M5NanoC6

//-------------------------------------------------------------------
const int PIN_LED = 7;

//-------------------------------------------------------------------
void setup()
{
  // blaue led ausschalten
  analogWrite(PIN_LED, 0);
}

//-------------------------------------------------------------------
void loop()
{
  // blaue led einblenden (0..100%)
  for (int tg = 0; tg <= 255; tg++) {
    analogWrite(PIN_LED, tg);
    delay(10);
  }

  // blaue led ausblenden (100..0%)
  for (int tg = 255; tg >= 0; tg--) {
    analogWrite(PIN_LED, tg);
    delay(10);
  }
}
