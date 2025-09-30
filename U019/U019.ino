// Earth
// - https://docs.m5stack.com/en/unit/earth

//-------------------------------------------------------------------
#define PIN_SIGNAL_ANALOG   1
#define PIN_SIGNAL_DIGITAL  2

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  pinMode(PIN_SIGNAL_DIGITAL, INPUT);
}

//-------------------------------------------------------------------
void loop(void)
{
  int a = analogRead(PIN_SIGNAL_ANALOG);
  
  bool d = digitalRead(PIN_SIGNAL_DIGITAL);

  Serial.printf("d:%u, a:%d \r\n", d, a);
  
  delay(1000);
}
