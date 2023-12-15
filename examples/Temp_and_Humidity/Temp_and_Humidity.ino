#include "Arduino_SensorKit.h"

// Uncomment line below if your SensorKit is the variant with the DHT20 sensor
// (It's marked IIC on the PCB and has a black cover, while the DHT11 sensor
// has a blue cover.)
//#define Environment Environment_I2C

void setup() {
  // Uncomment line below if your kit has a DHT11 and you're connecting it to 
  // a pin different than 3
  //Environment.setPin(4);

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
