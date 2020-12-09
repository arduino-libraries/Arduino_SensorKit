//#define DHTPIN 3 // By default its connected to pin D3, it can be changed, define it before the #include of the library
#include "Arduino_SensorKit.h"

void setup() {
  Serial.begin(9600);
  Environment.begin();
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
