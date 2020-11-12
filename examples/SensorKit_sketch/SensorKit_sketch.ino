#include "Arduino_SensorKit.h"

SensorKit kit;

float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  Serial.println("init");
  
  kit.begin();
  Oled.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature = Pressure.readTemperature();
  Serial.println(temperature);
  
  printScreen();
}

void printScreen() {
  Oled.clearBuffer();                   // clear the internal memory
  Oled.setCursor(0, 10);
  Oled.print(temperature);             // print random value read from pin A0
  Oled.print(" ºC");
  Oled.sendBuffer();                    // transfer internal memory to the display
  delay(1000);
}
