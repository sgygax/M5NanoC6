// The built-in infrared (IR) LED.
// - https://docs.m5stack.com/en/core/M5NanoC6

//-------------------------------------------------------------------
const int PIN_LED_IR = 3;

//-------------------------------------------------------------------
void setup() 
{
    pinMode(PIN_LED_IR, OUTPUT);
}

//-------------------------------------------------------------------
void loop() 
{
    // infrared led on
    digitalWrite(PIN_LED_IR, HIGH);
    delay(500);

    // infrared led off
    digitalWrite(PIN_LED_IR, LOW);
    delay(500);
}
