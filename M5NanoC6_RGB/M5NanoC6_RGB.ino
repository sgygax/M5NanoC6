// Die eingebaute Neopixel RGB-LED des M5NanoC6.
// https://docs.m5stack.com/en/core/M5NanoC6

//-------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>

//-------------------------------------------------------------------
const int PIN_POWER_RGB_ENABLE = 19;
const int PIN_DATA_RGB = 20;

const int NUM_LEDS = 1;

Adafruit_NeoPixel rgb(NUM_LEDS, PIN_DATA_RGB, NEO_GRB + NEO_KHZ800);

//-------------------------------------------------------------------
void setup() 
{
    pinMode(PIN_POWER_RGB_ENABLE, OUTPUT);
    digitalWrite(PIN_POWER_RGB_ENABLE, HIGH);

    rgb.begin();
    rgb.show();
}

//-------------------------------------------------------------------
void loop() 
{
    // rot 100%
    rgb.setPixelColor(0, rgb.Color(255, 0, 0));
    rgb.show();
    delay(500);

    // grün 100%
    rgb.setPixelColor(0, rgb.Color(0, 255, 0));
    rgb.show();
    delay(500);

    // blau 100%
    rgb.setPixelColor(0, rgb.Color(0, 0, 255));
    rgb.show();
    delay(500);

    // weiss 100%
    rgb.setPixelColor(0, rgb.Color(255, 255, 255));
    rgb.show();
    delay(1000);
}
