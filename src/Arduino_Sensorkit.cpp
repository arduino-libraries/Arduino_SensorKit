
#include "Arduino.h"
#include "Arduino_Sensorkit.h"

// ++++++++++++++++++++++++++++++++++++++
// Functions related to the Accelerometer
// ++++++++++++++++++++++++++++++++++++++

void BreakoutBoard::init_Accelerometer(){

  ACCELEROMETER.begin(WIRE, 0x19);
  delay(100);
  ACCELEROMETER.setFullScaleRange(LIS3DHTR_RANGE_2G);
  ACCELEROMETER.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  Serial.println("Accelerometer Connected !");

}

float BreakoutBoard::getAccelerationValue(char axis){

  switch(axis)
  {
    case 'X':
    return ACCELEROMETER.getAccelerationX();
    case 'Y':
    return ACCELEROMETER.getAccelerationY();
    case 'Z':
    return ACCELEROMETER.getAccelerationY();
    default :
    Serial.print("Invalid Input");
    while(1);
    break ;
  }

}

// ++++++++++++++++++++++++++++++++++++++++
// Functions related to the Pressure Sensor
// ++++++++++++++++++++++++++++++++++++++++

void BreakoutBoard::init_PressureSensor() {

    if (!bmp280.init()) {
        Serial.println("Device not connected or broken!");
    }
    else {
        Serial.println("Pressure Sensor Connected !");
    }
}

float BreakoutBoard::getPressureValue() {
  return bmp280.getPressure();
}

float BreakoutBoard::getAltitudeValue() {
  return bmp280.calcAltitude( bmp280.getPressure());
}

// ++++++++++++++++++++++++++++++++++++++++
// Functions related to the OLED Screen
// ++++++++++++++++++++++++++++++++++++++++

void BreakoutBoard::init_OLEDScreen(){

  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr);   // set a suitable font

}

void BreakoutBoard::setLabel(char *s){

  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.drawStr(0,10,s);
  //u8g2.print(a);                        // print random value read from pin A0
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);
}

void BreakoutBoard::setValue_float(float b){

  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.drawStr(0,10,"Analog Value:");   // write something to the internal memory
  u8g2.print(b);                        // print random value read from pin A0
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);
}

void BreakoutBoard::setValue_char(char c){

  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.drawStr(0,10,"Analog Value:");   // write something to the internal memory
  u8g2.print(c);                        // print random value read from pin A0
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);

}

void BreakoutBoard::setValue_char(char c){

  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.drawStr(0,10,"Analog Value:");   // write something to the internal memory
  u8g2.print(c);                        // print random value read from pin A0
  u8g2.sendBuffer();                    // transfer internal memory to the display
  delay(1000);

}
