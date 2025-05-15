/*
    Copyright (C) Arduino SA

    This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
    distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#ifndef Arduino_SensorKit_LIS3DHTR_h
#define Arduino_SensorKit_LIS3DHTR_h

#include "LIS3DHTR.h"
#include "Wire.h"

class SensorKit_LIS3DHTR{

    LIS3DHTR<TwoWire> LIS;
    
    public:
        SensorKit_LIS3DHTR(TwoWire& w) : _wire(&w) {};
        bool begin();

        bool available();
        float readX();
        float readY();
        float readZ();

        void setOutputDataRate(odr_type_t odr);
    private:
        TwoWire* _wire;
};

#endif