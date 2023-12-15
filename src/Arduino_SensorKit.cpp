#include "Arduino_SensorKit.h"

//Declare component's classes
SensorKit_Oled Oled;
SensorKit_DHT Environment(3,DHT11);
DHT Environment_I2C(DHT20);
SensorKit_LIS3DHTR Accelerometer(_WIRE);
SensorKit_BMP280 Pressure(_WIRE);