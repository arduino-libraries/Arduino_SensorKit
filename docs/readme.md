# **Sensor Kit Reference**

This documentation contains information about the classes and the usage of **Arduino_SensorKit** library which is primarily used in the [Arduino Sensor Kit](https://sensorkit.arduino.cc/). This library is a wrapper for other libraries such as 
* [u8g2 Library for monochrome displayes](https://github.com/olikraus/u8g2)
* [Seeed_Arduino_LIS3DHTR for the 3 Axis Accelerometer](github.com/Seeed-Studio/Seeed_Arduino_LIS3DHTR)
* [Grove_BMP280 Library for the Barometer](https://github.com/Seeed-Studio/Grove_BMP280)
* [DHT-sensor-library for the Temperature and Humidity Sensor](https://github.com/adafruit/DHT-sensor-library)

The Arduino_SensorKit Library can be downloaded from the Arduino IDE’s library manager or from the [github repository](https://github.com/arduino-libraries/Arduino_SensorKit)

## Using the SensorKit Class

### Declaration 

```cpp
  #include "Arduino_SensorKit.h"

  SensorKit kit;  //Declare the object to use it later

  void setup(){}
  void loop(){}
```

### Initialization

Using the function `begin()` at the beginning of the `setup()`

```cpp
  #include "Arduino_SensorKit.h"

  SensorKit kit;  //Declare the object to use it later

  void setup(){
    kit.begin();
  }

  void loop(){}
```

##  Using the Grove - OLED Display 0.96 inch


### Initialising the driver

Init and returns true if success, already done in the `SensorKit`'s object `begin()`

```cpp
if(!Oled.begin()){
  Serial.println("Error");
  while(1);
}
Serial.println("Ok");
```
### Printing "hello world" 

```cpp
#include "Arduino_SensorKit.h"

SensorKit kit;

void setup() {
  kit.begin();
}

void loop() {
  Oled.clearBuffer();                   // clear the internal memory
  Oled.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  Oled.setCursor(0, 10);
  Oled.print("Hello World");  // write something to the internal memory
  Oled.sendBuffer();                    // transfer internal memory to the display
  delay(1000);
}
```

### Printing values

```cpp
Oled.print(value);
```

## Using the Grove - 3-Axis Digital Accelerometer (±1.5g)

### Initialising the sensor

Init and returns true if success, already done in the `SensorKit`'s object `begin()`

```cpp
  if (!Accelerometer.begin()){
    Serial.println("Error");  // Accelerometer didnt initialized
    while(1);                 // Stop the program
  }
  Serial.println("Init complete");
```

### Reading the Acceleration X

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

### Reading the coordinate values

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

### Check if the sensor has reads available
 
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
        
## Using the Grove Barometer Sensor (BMP280)

### Initialising the sensor
Init and returns true if success, already done in the `SensorKit`'s object `begin()`
```cpp
  if (!Pressure.begin()){
    Serial.println("Error");  // Accelerometer didnt initialized
    while(1);                 // Stop the program
  }
  Serial.println("Init complete");
```

### Reading the Temperature values

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

### Reading the Pressure values

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

### Reading the Altitude values
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
        
## Using the Grove - Temperature & Humidity Sensor (DHT11) 

DHT sensor can read Temperature and Humidity. 

### DHTPIN
By default, once you include the library it has been set to digital pin `3`, it can be changed by adding
```cpp
#define DHTPIN yourPin
```
    
### Initialising the sensor
```cpp
  if (!Environment.begin()){
    Serial.println("Error");  // Accelerometer didnt initialized
    while(1);                 // Stop the program
  }
  Serial.println("Init complete");
```

### Reading the Temperature values

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

### Reading the Humidity values 

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
