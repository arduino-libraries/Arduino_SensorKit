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
#include "DHT.h"                        // Temp & Humidity
#include "U8x8lib.h"                    // OLED Display

//Defines
#ifndef DHTTYPE
  #define DHTTYPE DHT11
#endif
#ifndef DHTPIN
  #define DHTPIN 3
#endif

//Make the declared components from the .cpp to the sketch available
extern U8X8_SSD1306_128X64_NONAME_SW_I2C Oled;
extern SensorKit_LIS3DHTR Accelerometer;
extern SensorKit_BMP280 Pressure;
extern DHT Environment;
#endif
