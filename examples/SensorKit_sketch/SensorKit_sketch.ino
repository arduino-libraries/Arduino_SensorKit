#include "Arduino_SensorKit.h"

SensorKit kit;

int pressure;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  kit.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pressure = BMP.getPressure();
  
  Serial.print("Pressure: ");
  Serial.println(pressure);
}
