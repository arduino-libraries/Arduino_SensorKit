#include "Arduino_SensorKit.h"

SensorKit kit;

void setup() {
  kit.begin();
}

void loop() {
  int random_value = random(0, 1023);   //read value from A0

  Oled.clearBuffer();                   // clear the internal memory
  Oled.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  Oled.setCursor(0, 10);
  Oled.print("Analog Value:");  // write something to the internal memory
  Oled.print(random_value);             // print random value read from pin A0
  Oled.sendBuffer();                    // transfer internal memory to the display
  delay(1000);
}
