/*
  Arduino_Grove_Library.h - Library wrapper for the Arduino Sensor Kit https://sensorkit.arduino.cc/
  Created by Lenard George Swamy and Pablo Marquínez, October 19, 2020.
  Released into the public domain.
*/

#ifndef Arduino_SensorKit_h
#define Arduino_SensorKit_h

#include "Arduino.h"
#include "Wire.h"

//Libraries for components
#include "Arduino_SensorKit_BMP280.h"   // Pressure
#include "Arduino_SensorKit_LIS3DHTR.h" // Accel
#include "Grove_Temperature_And_Humidity_Sensor/DHT.h"                        // Temp & Humidity
#include "U8x8lib.h"                    // OLED Display

class SensorKit_DHT;

//Make the declared components from the .cpp to the sketch available
extern U8X8_SSD1306_128X64_NONAME_SW_I2C Oled;
extern SensorKit_LIS3DHTR Accelerometer;
extern SensorKit_BMP280 Pressure;
extern SensorKit_DHT Environment;
extern DHT Environment_I2C;

//Subclass DHT
class SensorKit_DHT : public DHT {
  public:
  SensorKit_DHT(uint8_t pin, uint8_t type) : DHT(pin, type) {};
  void setPin(uint8_t pin) {
    Environment = SensorKit_DHT(pin, DHT11);
  };
};

#endif
