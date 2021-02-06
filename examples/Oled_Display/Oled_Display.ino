#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  int random_value = random(0, 1023);   // create a random value

  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 3);
  Oled.print("Value: ");
  Oled.print(random_value);
  delay(1000);
}
