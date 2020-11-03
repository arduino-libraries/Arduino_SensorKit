
/*
  Arduino_Grove_Library.h - Library for using the components in the Grove Breakout Board with Arduino.
  Created by Lenard George Swamy, October 19, 2020.
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
#include "U8g2lib.h"                    // Oled Display


//Defines
#ifndef DHTTYPE
  #define DHTTYPE DHT11
#endif
#ifndef DHTPIN
  #define DHTPIN 7
#endif

class SensorKit {
    
    public:
        SensorKit();
        bool begin();
        void end();

};

//Make the declared components from the .cpp to the sketch available
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C Oled;
extern SensorKit_LIS3DHTR Accelerometer;
extern SensorKit_BMP280 Pressure;
extern DHT Environment;
#endif