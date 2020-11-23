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

#### Init the sensor

Init and returns true if success, already done in the `SensorKit`'s object `begin()`
```cpp
  if (!Accelerometer.begin()){
    Serial.println("Error");  // Accelerometer didnt initialized
    while(1);                 // Stop the program
  }
  Serial.println("Init complete");
```

#### Read values
```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;

  float x,y,z;        // Values for the readings

  setup(){
    Serial.begin(9600);
    kit.begin();
  }

  loop{
    x = Accelerometer.readX();
    y = Accelerometer.readY();
    z = Accelerometer.readZ();

    Serial.print("X axis: "); Serial.println(x);
    Serial.print("Y axis: "); Serial.println(y);
    Serial.print("Z axis: "); Serial.println(z);
  }
```

#### Check if the sensor has reads available
 
Return if the sensor its good to give the data

```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;

  float x,y,z;        // Values for the readings

  setup(){
    Serial.begin(9600);
    kit.begin();
  }

  loop{
    if(Accelerometer.available()){
      x = Accelerometer.readX();
      Serial.print("X axis: "); Serial.println(x);
    }
  }
```
        
###  Pressure

#### Init the sensor
Init and returns true if success, already done in the `SensorKit`'s object `begin()`
```cpp
  if (!Pressure.begin()){
    Serial.println("Error");  // Accelerometer didnt initialized
    while(1);                 // Stop the program
  }
  Serial.println("Init complete");
```

#### Get values
The Pressure sensor can get temperature, pressure and altitude

##### Temperature
```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;

  float temperature;        // Value for the reading

  setup(){
    Serial.begin(9600);
    kit.begin();
  }

  loop{
    temperature = Pressure.readTemperature();
    Serial.print("temperature :"); Serial.println(temperature);
    }
  }
```

##### Pressure
```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;

  uint32_t pressure;        // Value for the reading

  setup(){
    Serial.begin(9600);
    kit.begin();
  }

  loop{
    pressure = Pressure.readPressure();
    Serial.print("pressure :"); Serial.println(pressure);
    }
  }
```


##### Altitude
```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;

  float altitude;        // Value for the reading

  setup(){
    Serial.begin(9600);
    kit.begin();
  }

  loop{
    altitude = Pressure.readAltitude();
    Serial.print("altitude :"); Serial.println(altitude);
    }
  }
```
        
### Environment
DHT sensor can read Temperature and Humidity
#### DHTPIN
By default, once you include the library it has been set to digital pin `3`, it can be changed by adding
`#define DHTPIN yourPin` 
    
#### Init the sensor
```cpp
  if (!Environment.begin()){
    Serial.println("Error");  // Accelerometer didnt initialized
    while(1);                 // Stop the program
  }
  Serial.println("Init complete");
```

#### Temperature
```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;
  
  float temperature;
  
  void setup() {
    Serial.begin(9600);
    kit.begin();
  }

  void loop() {
    temperature = Environment.readTemperature();
    
    Serial.print("Temperature: ");
    Serial.print(temperature);  //print temperature
  }
```

#### Humidity
```cpp
  #include "Arduino_SensorKit.h"
  SensorKit kit;

  float humidity;

  void setup() {
    Serial.begin(9600);
    kit.begin();
  }

  void loop() {
    humidity = Environment.readHumidity();
    Serial.print("Temperature: ");
    Serial.print(temperature);  //print temperature
  }
```
