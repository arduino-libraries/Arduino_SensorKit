#ifndef Arduino_SensorKit_BMP280_h
#define Arduino_SensorKit_BMP280_h

#include "Grove_-_Barometer_Sensor_BMP280/Seeed_BMP280.h"

class SensorKit_BMP280 {

    BMP280 BMP;

    public:
        SensorKit_BMP280(TwoWire& w) : _wire(&w) {};
        bool begin();
        void end();

        float readTemperature();
        uint32_t readPressure();
        float readAltitude();
    private:
        TwoWire* _wire;
};

#endif