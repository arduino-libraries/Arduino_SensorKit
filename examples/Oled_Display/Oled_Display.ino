#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  int pot_value = analogRead(A0); // potentiometer

  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 33);
  Oled.print("Pot: ");
  Oled.print(pot_value);
  Oled.print("   "); // delete leftover characters
  Oled.refreshDisplay();
  delay(1000);
}
