// Schiebe-Potentiometer mit 14 Neopixel-RGB-LED.
// - https://docs.m5stack.com/en/unit/fader

//-------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>

//-------------------------------------------------------------------
const int PIN_POTENTIOMETER = 1;
const int PIN_DATA_RGB = 2;

const int NUM_LEDS = 14;

Adafruit_NeoPixel leds(NUM_LEDS, PIN_DATA_RGB, NEO_GRB + NEO_KHZ800);

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  pinMode(PIN_POTENTIOMETER, INPUT);

  leds.begin();
}

//-------------------------------------------------------------------
void loop()
{
  int rawADC = analogRead(PIN_POTENTIOMETER);

  int brightness = map(rawADC, 0, 4095, 0, 255);
  leds.setBrightness(brightness);

  for (int x = 0; x < NUM_LEDS; x++) {
    unsigned int color = leds.ColorHSV(x * (65536 / NUM_LEDS), 255, 255); 
    leds.setPixelColor(x, color); // 0x00RRGGBB
  }
  leds.show();

  Serial.println(rawADC);

  delay(100);
}
