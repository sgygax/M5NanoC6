// Einfaches kooperotives Multitasking mit 3 Task auf dem M5NanoC6.

//-------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>

//-------------------------------------------------------------------
// blaue led
const int PIN_LED = 7;

//-------------------------------------------------------------------
// neopixel rgb-led
const int PIN_POWER_RGB_ENABLE = 19;
const int PIN_DATA_RGB = 20;

const int NUM_LEDS = 1;

Adafruit_NeoPixel rgb(NUM_LEDS, PIN_DATA_RGB, NEO_GRB + NEO_KHZ800);

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);
}

//-------------------------------------------------------------------
void loop()
{
  static unsigned int timestamp1 = 0;
  static unsigned int timestamp2 = 0;
  static unsigned int timestamp3 = 0;

  // T=1000ms (f=1 Hz)
  if ((millis() - timestamp1) >= 1000) {
    timestamp1 = millis();
    Task_1();
  }

  // T=2ms (f=500 Hz)
  if ((millis() - timestamp2) >= 2) {
    timestamp2 = millis();
    Task_2();
  }

  // T=500ms (f=2 Hz)
  if ((millis() - timestamp3) >= 500) {
    timestamp3 = millis();
    Task_3();
  }
}

//-------------------------------------------------------------------
void Task_1(void)
{
  Serial.println("Hallo Welt...");
}

//-------------------------------------------------------------------
void Task_2(void)
{
  static int fsm = 0;
  static int tg = 0;

  switch (fsm) {
    default:
    case 0:
      // blaue led ausschalten
      analogWrite(PIN_LED, 0);
      fsm = 1;
      break;

    case 1:
      // blaue led einblenden (0..100%)
      analogWrite(PIN_LED, tg);
      tg++;
      if (tg >= 255) {
        fsm++;
      }
      break;

    case 2:
      // blaue led ausblenden (100..0%)
      analogWrite(PIN_LED, tg);
      tg--;
      if (tg <= 0) {
        fsm = 1;
      }
      break;
  }
}

//-------------------------------------------------------------------
void Task_3(void)
{
  static int fsm = 0;

  switch (fsm) {
    default:
    case 0:
      pinMode(PIN_POWER_RGB_ENABLE, OUTPUT);
      digitalWrite(PIN_POWER_RGB_ENABLE, HIGH);
      rgb.begin();
      rgb.show();
      fsm = 1;
      break;

    case 1:
      // rot 100%
      rgb.setPixelColor(0, rgb.Color(255, 0, 0));
      rgb.show();
      fsm++;
      break;

    case 2:
      // grün 100%
      rgb.setPixelColor(0, rgb.Color(0, 255, 0));
      rgb.show();
      fsm++;
      break;

    case 3:
      // blau 100%
      rgb.setPixelColor(0, rgb.Color(0, 0, 255));
      rgb.show();
      fsm++;
      break;

    case 4:
      // weiss 100%
      rgb.setPixelColor(0, rgb.Color(255, 255, 255));
      rgb.show();
      fsm = 1;
      break;
  }
}
