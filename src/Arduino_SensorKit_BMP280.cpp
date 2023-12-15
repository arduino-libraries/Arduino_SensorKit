#include "Arduino_SensorKit_BMP280.h"

bool SensorKit_BMP280::begin(){
    return BMP.init(*_wire);
}

float SensorKit_BMP280::readTemperature(){
    return BMP.getTemperature();
}

uint32_t SensorKit_BMP280::readPressure(){
    return BMP.getPressure();
}

float SensorKit_BMP280::readAltitude(){
    return BMP.calcAltitude(readPressure());
}

