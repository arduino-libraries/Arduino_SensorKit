// Combined Demo by Marc MERLIN <marc_soft@merlins.org>

#include "Arduino_SensorKit.h"

uint8_t button = 4;
uint8_t led = 6;
uint8_t pot = A0;
uint8_t mic = A2;
uint8_t light = A3;

void setup() {
  #if 0
  // Accelerometer and Oled both share the same I2C address
  // both cannot be used at the same time, unless you solder
  // across the I2C address solder pads on the Oled module
  Accelerometer.begin();
  // Same problem with pressure sensor
  Pressure.begin();
  #endif

  pinMode(mic , INPUT);
  pinMode(light , INPUT);

  pinMode(button , INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  Environment.begin();

  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {

  Oled.setFont(u8x8_font_amstrad_cpc_extended_r); 

  #if 0
  Oled.setCursor(0, 0);
  Oled.print("x:"); 
  Oled.print(Accelerometer.readX()); 
  Oled.print("  ");
  Oled.print("y:"); 
  Oled.print(Accelerometer.readY());        
  Oled.print("  ");
  Oled.print("z:"); 
  Oled.print(Accelerometer.readZ());
  // Similar problem with pressure sensor
  Oled.print(Pressure.readAltitude());
  #endif

  Oled.setCursor(0, 0);
  Oled.print("But:"); 
  if (digitalRead(button)) {
    digitalWrite(led, HIGH);
    Oled.print("1"); 
  } else {
    digitalWrite(led, LOW);
    Oled.print("0"); 
  }

  // https://github.com/olikraus/u8g2/wiki/u8x8reference#print
  // looks like we need an offset of 9 for a font of 8
  // if the offset is wrong, the text gets displayed on
  // the wrong line
  uint16_t pot_value = analogRead(pot);
  Oled.setCursor(0, 9);
  Oled.print("Pot: ");
  Oled.print(pot_value);
  Oled.print("   ");

  uint16_t mic_value = analogRead(mic);
  Oled.setCursor(0, 18);
  Oled.print("Mic: ");
  Oled.print(mic_value);
  Oled.print("   ");

  uint16_t light_value = analogRead(light);
  Oled.setCursor(0, 27);
  Oled.print("Light: ");
  Oled.print(light_value);
  Oled.print("   ");

  Oled.setCursor(0, 45);
  Oled.print("Temp:");
  Oled.print(Environment.readTemperature());
  Oled.print("C");

  Oled.setCursor(0, 54);
  Oled.print("Hum: ");
  Oled.print(Environment.readHumidity());
  Oled.print("%");

  Oled.refreshDisplay();
  delay(100);
}
