#ifndef Arduino_SensorKit_BMP280_h
#define Arduino_SensorKit_BMP280_h

#include "Seeed_BMP280.h"

class SensorKit_BMP280 {

    BMP280 BMP;

    public:
        SensorKit_BMP280();
        bool begin();
        void end();

        float readTemperature();
        uint32_t readPressure();
        float readAltitude();
};

#endif