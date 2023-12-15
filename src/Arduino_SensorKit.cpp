#include "Arduino_SensorKit.h"

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

//Declare component's classes
U8X8_SSD1306_128X64_NONAME_SW_I2C Oled_SW(_PIN_SCL, _PIN_SDA, U8X8_PIN_NONE);
U8X8_SSD1306_128X64_NONAME_HW_I2C Oled_HW(U8X8_PIN_NONE, _PIN_SCL, _PIN_SDA);
SensorKit_DHT Environment(3,DHT11);
DHT Environment_I2C(DHT20);
SensorKit_LIS3DHTR Accelerometer(_WIRE);
SensorKit_BMP280 Pressure;