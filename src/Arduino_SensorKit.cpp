#include "Arduino_Sensorkit.h"

//Declare component's classes
U8G2_SSD1306_128X64_NONAME_F_HW_I2C Oled(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
DHT Environment(DHTPIN, DHTTYPE);
SensorKit_LIS3DHTR Accelerometer;
SensorKit_BMP280 Pressure;

SensorKit::SensorKit(){}

bool SensorKit::begin(){
  Oled.begin();
  Oled.enableUTF8Print();

  Accelerometer.begin();
  delay(100);
  Accelerometer.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);

  Pressure.begin();
  Environment.begin();
}

void SensorKit::end(){

}
