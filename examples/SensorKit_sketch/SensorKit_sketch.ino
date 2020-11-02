#include "Arduino_SensorKit.h"

SensorKit kit;

int pressure;
int accelX;
int humidity;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  kit.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pressure = Pressure.readPressure();
  accelX = Accelerometer.readX();
  humidity = Environment.readHumidity();

  Serial.print("Pressure: ");
  Serial.println(pressure);
  Serial.println();

  Serial.print("Accel X: ");
  Serial.println(accelX);
  
  Serial.print("Humidity: ");
  Serial.println(humidity);

  printScreen();
  delay(1000);
}

void printScreen() {
  Oled.clearBuffer();                   // clear the internal memory
  Oled.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  Oled.drawStr(0, 10, "Analog Value:");  // write something to the internal memory
  Oled.print(pressure);             // print random value read from pin A0
  Oled.sendBuffer();                    // transfer internal memory to the display
}
