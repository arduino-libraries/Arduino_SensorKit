/*
    Copyright (C) Arduino SA

    This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
    distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

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