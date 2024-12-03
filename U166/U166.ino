// A 0.43-inch mini OLED screen (72x40, B/W) using the SSD1315 chipset.
// - https://docs.m5stack.com/en/unit/MiniOLED%20Unit
// - https://github.com/olikraus/U8g2_Arduino

// GROVE PORT (UNIVERSAL):
// 1 GPIO1, TWI(SCL), UART(RX)
// 2 GPIO2, TWI(SDA), UART(TX)
// 3 +5V
// 4 GND

//-------------------------------------------------------------------
#include <Wire.h>
#include "U8g2lib.h"

//-------------------------------------------------------------------
U8G2_SSD1306_72X40_ER_F_HW_I2C display(U8G2_R0);

//-------------------------------------------------------------------
void setup(void)
{
  Wire.begin();
  display.begin();
}

//-------------------------------------------------------------------
void loop(void)
{
  // drawStr
  display.clearBuffer();
  display.setFont(u8g2_font_ncenB08_tr);
  display.setDrawColor(1);
  display.drawStr(10, 20, "Hallo");
  display.drawStr(10, 30, "Welt !!!"); // x, y
  display.sendBuffer();
  delay(1000);

  // drawStr
  display.clearBuffer();
  display.setFont(u8g2_font_ncenB14_tr);
  display.setDrawColor(1);
  for (int p = 0; p < 1000; p++) {
    display.clearBuffer();
    display.drawStr(10, 30, String(p).c_str());
    display.sendBuffer();
  }
  delay(1000);

  // drawPixel
  display.clearBuffer();
  display.setDrawColor(1);
  for (int p = 0; p < 100; p++) {
    int x = random(0, 72);
    int y = random(0, 40);
    display.drawPixel(x, y);
    display.sendBuffer();
  }
  delay(1000);

  // drawLine
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawLine(0, 0, 72, 40); // x0, y0, x1, y1
  display.sendBuffer();
  delay(1000);

  // drawFrame
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawFrame(0, 0, 72, 40); // x, y, w, h
  display.sendBuffer();
  delay(1000);

  // drawRFrame
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawRFrame(0, 0, 72, 40, 10); // x, y, w, h, r
  display.sendBuffer();
  delay(1000);

  // drawBox
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawBox(0, 0, 72, 40); // x, y, w, h
  display.sendBuffer();
  delay(1000);

  // drawRBox
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawRBox(0, 0, 72, 40, 10); // x, y, w, h, r
  display.sendBuffer();
  delay(1000);

  // drawCircle
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawCircle(30, 20, 15); // x, y, r
  display.sendBuffer();
  delay(1000);

  // drawDisc
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawDisc(40, 20, 15); // x, y, r
  display.sendBuffer();
  delay(1000);

  // drawEllipse
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawEllipse(30, 20, 15, 5); // x, y, rx, ry
  display.sendBuffer();
  delay(1000);

  // drawFilledEllipse
  display.clearBuffer();
  display.setDrawColor(1);
  display.drawFilledEllipse(40, 20, 15, 5); // x, y, rx, ry
  display.sendBuffer();
  delay(1000);
}
