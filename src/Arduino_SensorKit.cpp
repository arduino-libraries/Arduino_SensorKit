#include "Arduino_SensorKit.h"

//Declare component's classes
SensorKit_Oled Oled;
SensorKit_DHT11 Environment(3,DHT11);
SensorKit_DHT20 Environment_I2C;
SensorKit_LIS3DHTR Accelerometer(_WIRE);
SensorKit_BMP280 Pressure(_WIRE);