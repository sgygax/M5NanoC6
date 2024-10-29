// The built-in button.
// - https://docs.m5stack.com/en/core/M5NanoC6

//-------------------------------------------------------------------
const int PIN_BUTTON = 9;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  pinMode(PIN_BUTTON, INPUT);
}

//-------------------------------------------------------------------
void loop()
{
  bool button = digitalRead(PIN_BUTTON);

  Serial.println(button);

  delay(100);
}
