// https://docs.m5stack.com/en/arduino/m5gfx/m5gfx#m5unitoledh
// 1.3" 128 x 64

#include <M5UnitOLED.h>

//-------------------------------------------------------------------
M5UnitOLED display;

//-------------------------------------------------------------------
void setup(void)
{
  display.init();
  display.setRotation(3); // 0 1 2 3
  display.setColorDepth(1); // 1 bit farbtiefe

  display.setFont(&fonts::Font0);
  display.setTextWrap(false);
  display.setTextSize(1);
  display.setTextColor(TFT_WHITE, TFT_BLACK);

  display.clear();
}

//-------------------------------------------------------------------
void loop(void)
{
  // setCursor, print
  display.setCursor(10, 30);
  display.print("Hallo Welt !!!");
  delay(1000);
  display.clear();
  
  // fillScreen
  display.fillScreen(TFT_WHITE);
  delay(1000);

  display.fillScreen(TFT_BLACK);
  delay(1000);

  // drawPixel
  for (int p = 0; p < 10000; p++) {
    int x = random(0, 128);
    int y = random(0, 64);
    display.drawPixel(x, y, TFT_WHITE);
  }
  delay(1000);
  display.clear();

  // drawLine
  for (int p = 0; p < 100; p++) {
    int x0 = random(0, 128);
    int y0 = random(0, 64);
    int x1 = random(0, 128);
    int y1 = random(0, 64);
    display.drawLine(x0, y0, x1, y1, TFT_WHITE);
    delay(10);
  }
  delay(1000);
  display.clear();

  // drawRect
  for (int p = 0; p < 10; p++) {
    int x = random(0, 128);
    int y = random(0, 64);
    int w = random(5, 30);
    int h = random(5, 30);
    display.drawRect(x, y, w, h, TFT_WHITE);
    delay(100);
  }
  delay(1000);
  display.clear();

  // fillRect
  for (int p = 0; p < 10; p++) {
    int x = random(0, 128);
    int y = random(0, 64);
    int w = random(5, 30);
    int h = random(5, 30);
    display.fillRect(x, y, w, h, TFT_WHITE);
    delay(100);
  }
  delay(1000);
  display.clear();

  // drawCircle
  for (int p = 0; p < 10; p++) {
    int x = random(0, 128);
    int y = random(0, 64);
    int r = random(5, 15);
    display.drawCircle(x, y, r, TFT_WHITE);
    delay(100);
  }
  delay(1000);
  display.clear();

  // fillCircle
  for (int p = 0; p < 10; p++) {
    int x = random(0, 128);
    int y = random(0, 64);
    int r = random(5, 15);
    display.fillCircle(x, y, r, TFT_WHITE);
    delay(100);
  }
  delay(1000);
  display.clear();

  // drawTriangle
  for (int p = 0; p < 10; p++) {
    int x0 = random(0, 128);
    int y0 = random(0, 64);
    int x1 = random(0, 128);
    int y1 = random(0, 64);
    int x2 = random(0, 128);
    int y2 = random(0, 64);
    display.drawTriangle(x0, y0, x1, y1, x2, y2, TFT_WHITE);
    delay(100);
  }
  delay(1000);
  display.clear();

  // fillTriangle
  for (int p = 0; p < 10; p++) {
    int x0 = random(0, 128);
    int y0 = random(0, 64);
    int x1 = random(0, 128);
    int y1 = random(0, 64);
    int x2 = random(0, 128);
    int y2 = random(0, 64);
    display.fillTriangle(x0, y0, x1, y1, x2, y2, TFT_WHITE);
    delay(100);
  }
  delay(1000);
  display.clear();
}
