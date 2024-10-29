// https://docs.m5stack.com/en/unit/lcd
// 1.14" 240 x 135

//-------------------------------------------------------------------
#include <M5UnitLCD.h>

//-------------------------------------------------------------------
M5UnitLCD display;

//-------------------------------------------------------------------
void setup(void)
{
  display.init();
  display.setRotation(3); // 0 1 2 3
  display.setColorDepth(8); // 8 bit farbtiefe

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
    int x = random(0, 240);
    int y = random(0, 135);
    display.drawPixel(x, y, TFT_WHITE);
  }
  display.clear();

  // drawPixel
  for (int p = 0; p < 10000; p++) {
    int x = random(0, 240);
    int y = random(0, 135);
    int c = random(0, 0xFFFF + 1);
    display.drawPixel(x, y, c);
  }
  display.clear();

  // drawLine
  for (int p = 0; p < 1000; p++) {
    int x0 = random(0, 240);
    int y0 = random(0, 135);
    int x1 = random(0, 240);
    int y1 = random(0, 135);
    int c = random(0, 0xFFFF + 1);
    display.drawLine(x0, y0, x1, y1, c);
  }
  display.clear();

  // drawRect
  for (int p = 0; p < 1000; p++) {
    int x = random(0, 240);
    int y = random(0, 135);
    int w = random(5, 50);
    int h = random(5, 50);
    int c = random(0, 0xFFFF + 1);
    display.drawRect(x, y, w, h, c);
  }
  display.clear();

  // fillRect
  for (int p = 0; p < 1000; p++) {
    int x = random(0, 240);
    int y = random(0, 135);
    int w = random(5, 50);
    int h = random(5, 50);
    int c = random(0, 0xFFFF + 1);
    display.fillRect(x, y, w, h, c);
  }
  display.clear();

  // drawCircle
  for (int p = 0; p < 1000; p++) {
    int x = random(0, 240);
    int y = random(0, 135);
    int r = random(5, 50);
    int c = random(0, 0xFFFF + 1);
    display.drawCircle(x, y, r, c);
  }
  display.clear();

  // fillCircle
  for (int p = 0; p < 1000; p++) {
    int x = random(0, 240);
    int y = random(0, 135);
    int r = random(5, 50);
    int c = random(0, 0xFFFF + 1);
    display.fillCircle(x, y, r, c);
  }
  display.clear();

  // drawTriangle
  for (int p = 0; p < 1000; p++) {
    int x0 = random(0, 240);
    int y0 = random(0, 135);
    int x1 = random(0, 240);
    int y1 = random(0, 135);
    int x2 = random(0, 240);
    int y2 = random(0, 135);
    int c = random(0, 0xFFFF + 1);
    display.drawTriangle(x0, y0, x1, y1, x2, y2, c);
  }
  display.clear();

  // fillTriangle
  for (int p = 0; p < 1000; p++) {
    int x0 = random(0, 240);
    int y0 = random(0, 135);
    int x1 = random(0, 240);
    int y1 = random(0, 135);
    int x2 = random(0, 240);
    int y2 = random(0, 135);
    int c = random(0, 0xFFFF + 1);
    display.fillTriangle(x0, y0, x1, y1, x2, y2, c);
  }
  display.clear();
}
