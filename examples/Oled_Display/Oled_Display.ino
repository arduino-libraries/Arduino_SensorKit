#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  int random_value = random(0, 1023);   // create a random value

  Oled.setFont(u8x8_font_chroma48medium8_r); 
  // Y needs to be a multiple of 9 for a font of 8 or the display
  // will end up in an incorrect place.
  Oled.setCursor(0, 27);
  Oled.print("Value: ");
  Oled.print(random_value)
  Oled.refreshDisplay();
  delay(1000);
}
