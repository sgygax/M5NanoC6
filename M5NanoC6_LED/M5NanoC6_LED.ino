// Die eingebaute blaue LED des M5NanoC6.
// https://docs.m5stack.com/en/core/M5NanoC6

//-------------------------------------------------------------------
const int PIN_LED = 7;

//-------------------------------------------------------------------
void setup() 
{
    pinMode(PIN_LED, OUTPUT);
}

//-------------------------------------------------------------------
void loop() 
{
    // blaue led on
    digitalWrite(PIN_LED, HIGH);
    delay(500);

    // blaue led off
    digitalWrite(PIN_LED, LOW);
    delay(500);
}
