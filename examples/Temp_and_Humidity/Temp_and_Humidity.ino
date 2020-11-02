#include "Arduino_SensorKit.h"

SensorKit kit;

#define DHT_PIN 7

void setup() {
  Serial.begin(9600);
  kit.begin();
}

void loop() {
  
  Serial.print("Temperature = ");
  Serial.print(Environment.readTemperature()); //print temperature
  Serial.println(" C");
  Serial.print("Humidity = ");
  Serial.print(Environment.readHumidity()); //print humidity
  Serial.println(" %");
  delay(2000);
}
