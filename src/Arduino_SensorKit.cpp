/*
    Copyright (C) Arduino SA

    This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
    distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include "Arduino_SensorKit.h"

//Declare component's classes
SensorKit_Oled Oled;
SensorKit_DHT11 Environment(3,DHT11);
SensorKit_DHT20 Environment_I2C;
SensorKit_LIS3DHTR Accelerometer(_WIRE);
SensorKit_BMP280 Pressure(_WIRE);