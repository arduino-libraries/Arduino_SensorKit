
/*
  Arduino_Grove_Library.h - Library for using the components in the Grove Breakout Board with Arduino.
  Created by Lenard George Swamy, October 19, 2020.
  Released into the public domain.
*/

#ifndef Arduino_SensorKit_h
#define Arduino_SensorKit_h

#include "Arduino.h"
#include "Wire.h"
#include "Seeed_BMP280.h"
#include "LIS3DHTR.h"
#include "U8g2lib.h"
#include "DHT.h"


//Defines
#define TEMP_SENSOR_PIN 3
#define LED_PIN 4
#define BUZZER_PIN 5
#define BUTTON_PIN 6
#define POT_PIN A0
#define SOUND_SENSOR A2
#define LIGHT_SENSOR A6
#define AXIS_X X
#define AXIS_Y Y
#define AXIS_Z Z

class SensorKit {
    
    public:
        SensorKit();
        bool begin();
        void end();

};

extern BMP280 BMP;
extern LIS3DHTR<TwoWire> LIS;
//extern DHT ENV;
//#define ENV DHT
#endif

