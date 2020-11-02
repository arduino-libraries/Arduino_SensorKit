#include "Arduino_Sensorkit.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
int dhtPin = -10;

SensorKit::SensorKit(){}

bool SensorKit::begin(){
  BMP.init();
  LIS.begin(Wire);
}

void SensorKit::end(){}

BMP280 BMP;
LIS3DHTR<TwoWire> LIS;
//DHT ENV;