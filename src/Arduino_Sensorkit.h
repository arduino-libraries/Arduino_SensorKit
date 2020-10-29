
/*
  Arduino_Grove_Library.h - Library for using the components in the Grove Breakout Board with Arduino.
  Created by Lenard George Swamy, October 19, 2020.
  Released into the public domain.
*/

#ifndef Arduino_Sensorkit_h
#define Arduino_Sensorkit_h

#include "Seeed_BMP280.h"
#include "LIS3DHTR.h"
#include "U8g2lib.h"
#include "Arduino.h"
#include "Wire.h"

class BreakoutBoard {

private:

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
#define PRESSURE_SENSOR BMP280;

#ifdef SOFTWAREWIRE
    #include <SoftwareWire.h>
    SoftwareWire myWire(3, 2);
    LIS3DHTR<SoftwareWire> ACCELEROMETER;       //Software I2C
    #define WIRE myWire
#else
    #include <Wire.h>
    LIS3DHTR<TwoWire> ACCELEROMETER;           //Hardware I2C
    #define WIRE Wire
#endif

BMP280 bmp280;
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

public:

    void init_Accelerometer();
    float getAccelerationValue(char axis);

    void init_PressureSensor();
    float getPressureValue();
    float getAltitudeValue();

    void init_OLEDScreen();
    void setLabel(char *label);
    void setValue_int(int a);
    void setValue_float(float b);
    void setValue_char(char c);

};

#endif

