#include "Arduino_SensorKit.h"

#if defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_MEGAAVR)
  #define _PIN_SDA SDA
  #define _PIN_SCL SCL
#elif defined(ARDUINO_GIGA)
  #define _PIN_SDA I2C_SDA1
  #define _PIN_SCL I2C_SCL1
#else
  #error "This board is not supported by Arduino_SensorKit"
#endif

//Declare component's classes
U8X8_SSD1306_128X64_NONAME_SW_I2C Oled(/* clock=*/ _PIN_SCL, /* data=*/ _PIN_SDA, /* reset=*/ U8X8_PIN_NONE);
DHT Environment(DHTPIN,DHT11);
DHT Environment_I2C(DHT20);
SensorKit_LIS3DHTR Accelerometer;
SensorKit_BMP280 Pressure;