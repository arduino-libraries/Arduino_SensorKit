#include "Arduino_SensorKit.h"

SensorKit kit;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  
  kit.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // 3 axis
  Serial.print("x:"); 
  Serial.print(Accelerometer.readX()); 
  Serial.print("  ");
  Serial.print("y:"); 
  Serial.print(Accelerometer.readY());        
  Serial.print("  ");
  Serial.print("z:"); 
  Serial.println(Accelerometer.readZ());
 
  delay(500);
}
