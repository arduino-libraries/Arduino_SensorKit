#include "Arduino_SensorKit.h"

//uncomment line below if using DHT20
//#define Environment Environment_I2C

void setup() {
  //uncomment line below if using DHT20
  //Wire.begin();

  //uncomment line below if you're connecting your DHT20 to pin a different than 3
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
