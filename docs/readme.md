# **Sensor Kit Reference**

This is a basic documentation about the library for the *SensorKit* .

The library it's a wrapper of some libraries to use with the ![Arduino Sensor Kit](), it can be downloaded from the Arduino IDE’s library manager or by going to the [github repository](https://github.com/arduino-libraries/Arduino_SensorKit)

## Classes
### SensorKit

#### Constructor of the object

```cpp
#include "Arduino_SensorKit.h"

SensorKit kit;  //Declare the object to use it later

void setup(){}
void loop(){}
```

#### Initialization

Using the function `begin()` at the beginning of the `setup()`

```cpp
#include "Arduino_SensorKit.h"

SensorKit kit;  //Declare the object to use it later

void setup(){
  kit.begin();
}

void loop(){}
```

###  Oled

Using U8G2 library

### Accelerometer

Using LIS3DHTR library, this library renames their functions.
github.com/Seeed-Studio/Seeed_Arduino_LIS3DHTR
        
#### Using the Accelerometer

```cpp
#include "Arduino_SensorKit.h"

SensorKit kit;  //Declare the object to use it later

float acceleration;

void setup(){
  kit.begin();
}

void loop(){
  Serial.begin(9600);
  acceleration = Accelerometer.readX();
  Serial.println(acceleration);
}
```

#### bool begin()

Init and returns true if success, already done in the `SensorKit`'s object `begin()`

#### bool available()

Return if the sensor its good to give the data

#### float readX()

Return X axis acceleration

#### float readY()

Return Y axis acceleration

#### float readZ()

Return Z axis acceleration

#### void setOutputDataRate(odr_type_t odr);
        
###  Pressure
#### DHTPIN
By default, once you include the library it has been set to digital pin 3, it can be changed by adding
`#define DHTPIN yourPin` 
#### bool begin();
Init and returns true if success, already done in the `SensorKit`'s object `begin()`
#### void end();

#### float readTemperature();
#### uint32_t readPressure();
#### float readAltitude();
        
### Environment
        It has DHTPIN defined by default to digital pin 3, you can redefine it by adding
        `#define DHTPIN yourPin`
