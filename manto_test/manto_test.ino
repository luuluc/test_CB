   
#include <U8g2lib.h>

U8G2_ST7920_128X64_F_SW_SPI u8g2(
  U8G2_R0, 
  /* clock=*/ D5,  // SCLK → D18
  /* data=*/ D6,   // MOSI → D19
  /* cs=*/ D7,     // CS → D21
  /* reset=*/ U8X8_PIN_NONE
);

void setup() {
  u8g2.begin();          // Khởi tạo LCD
  u8g2.setFont(u8g2_font_6x10_tr); // Chọn font
  u8g2.clearBuffer();
  u8g2.drawStr(0, 10, "vi tri 1"); // Vẽ chữ tại (x=10, y=20)
  u8g2.drawStr(0, 20, "vi tri 2");
  u8g2.drawStr(0, 30, "vi tri 3");
  u8g2.drawStr(0, 40, "vi tri 4");
  u8g2.drawStr(0, 50, "vi tri 5");
  u8g2.drawStr(0, 60, "vi tri 6");
  u8g2.drawStr(70, 10, "vi tri 7");
  u8g2.drawStr(70, 20, "vi tri 8");
  u8g2.drawStr(70, 30, "vi tri 9");
  u8g2.drawStr(70, 40, "vi tri 10");
  u8g2.drawStr(70, 50, "vi tri 11");
  u8g2.drawStr(70, 60, "vi tri 12");
  u8g2.sendBuffer();     // Hiển thị lên LCD
}

void loop() {
  // Thêm code chạy chữ, animation...
}