#include "Arduino_SensorKit_LIS3DHTR.h"

SensorKit_LIS3DHTR::SensorKit_LIS3DHTR(){}

bool SensorKit_LIS3DHTR::begin(){
    LIS.begin(Wire);
    delay(100);
    LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
    return LIS;
}


bool SensorKit_LIS3DHTR::available(){
    return LIS.available();
}

float SensorKit_LIS3DHTR::readX(){
    return LIS.getAccelerationX();
}

float SensorKit_LIS3DHTR::readY(){
    return LIS.getAccelerationY();
}

float SensorKit_LIS3DHTR::readZ(){
    return LIS.getAccelerationZ();
}

void SensorKit_LIS3DHTR::setOutputDataRate(odr_type_t odr){
    LIS.setOutputDataRate(odr);
}