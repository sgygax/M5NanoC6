// An external Neopixel-stripe with 30 RGB-LEDs (GRB order of primary color).
// - https://docs.m5stack.com/en/core/M5NanoC6

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>

//-------------------------------------------------------------------
const int PIN_DATA_STRIPE = 1; // 1, 2

const int NUM_LEDS = 30;

Adafruit_NeoPixel stripe(NUM_LEDS, PIN_DATA_STRIPE, NEO_GRB + NEO_KHZ800); // GRB order of primary color

//-------------------------------------------------------------------
void setup()
{
  stripe.begin();
  stripe.show();
}

//-------------------------------------------------------------------
void loop()
{
  for (int x = 0; x < NUM_LEDS; x++) {
    // R=100% G=0%, B=0%
    stripe.setPixelColor(x, 255, 0, 0);
  }
  stripe.show();
  delay(500);

  for (int x = 0; x < NUM_LEDS; x++) {
    // R=0% G=100%, B=0%
    stripe.setPixelColor(x, 0, 255, 0);
  }
  stripe.show();
  delay(500);

  for (int x = 0; x < NUM_LEDS; x++) {
    // R=0% G=0%, B=100%
    stripe.setPixelColor(x, 0, 0, 255);
  }
  stripe.show();
  delay(500);

  for (int x = 0; x < NUM_LEDS; x++) {
    // R=100% G=100%, B=100%
    stripe.setPixelColor(x, 255, 255, 255);
  }
  stripe.show();
  delay(500);

  for (int x = 0; x < NUM_LEDS; x++) {
    // R=0% G=0%, B=0%
    stripe.setPixelColor(x, 0, 0, 0);
  }
  stripe.show();
  delay(500);
}
