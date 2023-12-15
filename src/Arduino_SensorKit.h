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
#undef DHT20
#include <DHT20.h>                                                           // Temp & Humidity
#include "U8g2/src/U8x8lib.h"                    // OLED Display

#if defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_MEGAAVR) || defined(ARDUINO_UNOR4_MINIMA) || defined(ARDUINO_UNOR4_WIFI)
  #define _PIN_SDA SDA
  #define _PIN_SCL SCL
  #define _WIRE Wire
#elif defined(ARDUINO_GIGA)
  #define _PIN_SDA I2C_SDA1
  #define _PIN_SCL I2C_SCL1
  #define _WIRE Wire1
#else
  #error "This board is not supported by Arduino_SensorKit"
#endif

// The upstream U8X8 library provides two variants, one for hardware I2C (using 
// the Wire object provided by Arduino) and one for software I2C. The latter 
// doesn't seem to work. However it seems that when breaking the sensors from
// the big PCB, the software I2C variant works better, so we support both 
// letting the user define SENSORKIT_USE_SW_I2C.
#ifdef SENSORKIT_USE_SW_I2C
  #define _Oled_class U8X8_SSD1306_128X64_NONAME_SW_I2C
#else
  #define _Oled_class U8X8_SSD1306_128X64_NONAME_HW_I2C
#endif
class SensorKit_Oled : public _Oled_class {
  public:
  #ifdef SENSORKIT_USE_SW_I2C
    SensorKit_Oled() : _Oled_class(_PIN_SCL, _PIN_SDA, U8X8_PIN_NONE) {};
  #else
    SensorKit_Oled() : _Oled_class(U8X8_PIN_NONE, _PIN_SCL, _PIN_SDA) {};
    bool begin(void) {
      _Oled_class::wire = &_WIRE;
      return _Oled_class::begin();
    };
  #endif
};
extern SensorKit_Oled Oled;

class SensorKit_DHT11;
class SensorKit_DHT20;
extern SensorKit_LIS3DHTR Accelerometer;
extern SensorKit_BMP280 Pressure;
extern SensorKit_DHT11 Environment;
extern SensorKit_DHT20 Environment_I2C;

// Subclass DHT
class SensorKit_DHT11 : public DHT {
  public:
  SensorKit_DHT11(uint8_t pin, uint8_t type) : DHT(pin, type) {};
  void setPin(uint8_t pin) {
    Environment = SensorKit_DHT11(pin, DHT11);
  };
};

class SensorKit_DHT20 : public DHT20 {
  public:
  SensorKit_DHT20() : DHT20(&_WIRE) {};
  bool begin(void) {
    _WIRE.begin();
    return DHT20::begin();
  };
  float readHumidity() { read(); return getHumidity(); };
  float readTemperature() { read(); return getTemperature(); };
};

#endif
