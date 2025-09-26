/*
    Copyright (C) Arduino SA

    This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
    distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

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

