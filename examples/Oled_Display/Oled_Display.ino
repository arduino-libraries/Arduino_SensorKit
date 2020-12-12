#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  int random_value = random(0, 1023);   //read value from A0

  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 33);
  Oled.print("Temp: ");
  Oled.print(random_value);
  Oled.print("C");
  Oled.refreshDisplay();
  delay(1000);
}
