#include "Arduino_SensorKit.h"

SensorKit kit;

float pressure;

void setup() {
  Serial.begin(9600);
  kit.begin();
}

void loop() {
  // Get and print temperatures
  Serial.print("Temp: ");
  Serial.print(Pressure.getTemperature());
  Serial.println("C"); // The unit for  Celsius because        original arduino don't support speical symbols

  // Get and print atmospheric pressure data
  Serial.print("Pressure: ");
  Serial.print(pressure = Pressure.readPressure());
  Serial.println("Pa");

  // Get and print altitude data
  Serial.print("Altitude: ");
  Serial.print(Pressure.calcAltitude(pressure));
  Serial.println("m");

  Serial.println("\n");//add a line between output of different times.

  delay(1000);
}
