#include "Arduino_SensorKit.h"

void setup() {
  Serial.begin(9600);
  Pressure.begin();
}

void loop() {
  // Get and print temperatures
  Serial.print("Temp: ");
  Serial.print(Pressure.readTemperature());
  Serial.println("C"); // The unit for Celsius because original Arduino don't support special symbols

  // Get and print atmospheric pressure data
  Serial.print("Pressure: ");
  Serial.print(Pressure.readPressure());
  Serial.println("Pa");

  // Get and print altitude data
  Serial.print("Altitude: ");
  Serial.print(Pressure.readAltitude());
  Serial.println("m");

  Serial.println("\n");//add a line between output of different times.

  delay(1000);
}
