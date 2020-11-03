#include "Arduino_Sensorkit.h"

//Declare component's classes
U8G2_SSD1306_128X64_NONAME_F_SW_I2C Oled(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
DHT Environment(DHTPIN, DHTTYPE);
SensorKit_LIS3DHTR Accelerometer;
SensorKit_BMP280 Pressure;

//Pointers to access them inside the class
U8G2_SSD1306_128X64_NONAME_F_SW_I2C& pOled = Oled;
SensorKit_LIS3DHTR& pAccelerometer = Accelerometer;
SensorKit_BMP280& pPressure = Pressure;
DHT& pEnvironment = Environment;

SensorKit::SensorKit(){}

bool SensorKit::begin(){
  pOled.begin();

  pAccelerometer.begin();
  delay(100);
  pAccelerometer.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);

  pPressure.begin();
  pEnvironment.begin();
}

void SensorKit::end(){

}