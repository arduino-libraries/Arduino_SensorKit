# **Sensor Kit Reference**

This documentation contains information about the classes and the usage of **Arduino_SensorKit** library which is primarily used in the [Arduino Sensor Kit](https://sensorkit.arduino.cc/). This library is a wrapper for other libraries such as 
* [u8g2 Library for monochrome displayes](https://github.com/olikraus/u8g2)
* [Seeed_Arduino_LIS3DHTR for the 3 Axis Accelerometer](https://github.com/Seeed-Studio/Seeed_Arduino_LIS3DHTR)
* [Grove_BMP280 Library for the Barometer](https://github.com/Seeed-Studio/Grove_BMP280)
* [DHT-sensor-library for the Temperature and Humidity Sensor](https://github.com/adafruit/DHT-sensor-library)

The Arduino_SensorKit Library can be downloaded from the Arduino IDE’s library manager or from the [github repository](https://github.com/arduino-libraries/Arduino_SensorKit)

# Classes

## Including the library 

```cpp
  #include "Arduino_SensorKit.h"

  void setup(){}
  void loop(){}
```

##  OLED
Using the Grove - OLED Display 0.96 inch

### Initialising the driver

Init the display driver

```cpp
  void setup(){
    Oled.begin();
  }
  void loop(){}
```
### Printing "hello world" 

```cpp
#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(1);  //Rotate it
}

void loop() {
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.drawString(0,0,"Hello World!");
  Oled.refreshDisplay();
  delay(1000);
}
```

### Printing values

```cpp
  Oled.print(value);
```

## Accelerometer
Using the Grove - 3-Axis Digital Accelerometer (±1.5g)

### Initialising the sensor

Initialize the sensor

```cpp
  void setup(){
    Accelerometer.begin();
  }
  void loop(){}
```

### Reading the Acceleration X

```cpp
  #include "Arduino_SensorKit.h"
  
  float acceleration;

  void setup(){
    Accelerometer.begin();
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

  float x,y,z;        // Values for the readings

  setup(){
    Serial.begin(9600);
    Accelerometer.begin();
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

  float x,y,z;        // Values for the readings

  setup(){
    Serial.begin(9600);
    Accelerometer.begin();
  }

  loop{
    if(Accelerometer.available()){
      x = Accelerometer.readX();
      Serial.print("X axis: "); Serial.println(x);
    }
  }
```
        
## Pressure
Using the Grove Barometer Sensor (BMP280)
The Pressure sensor can get temperature, pressure and altitude

### Initialising the sensor
Initialize the sensor
```cpp
   void setup(){
    Pressure.begin();
  }
  void loop(){}
```

### Reading the Temperature values

```cpp
  #include "Arduino_SensorKit.h"

  float temperature;        // Value for the reading

  setup(){
    Serial.begin(9600);
    Pressure.begin();
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

  uint32_t pressure;        // Value for the reading

  setup(){
    Serial.begin(9600);
    Pressure.begin();
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

  float altitude;        // Value for the reading

  setup(){
    Serial.begin(9600);
    Presure.begin();
  }

  loop{
    altitude = Pressure.readAltitude();
    Serial.print("altitude :"); Serial.println(altitude);
    }
  }
```
        
## Environment
Using the Grove - Temperature & Humidity Sensor (DHT11) 
DHT sensor can read Temperature and Humidity. 

### DHTPIN
By default, once you include the library it has been set to digital pin `3`, it can be changed by adding
```cpp
#define DHTPIN yourPin
```
    
### Initialising the sensor
```cpp
  void setup(){
    Environment.begin();
  }
  void loop(){}
```

### Reading the Temperature values

```cpp
  #include "Arduino_SensorKit.h"
  
  float temperature;
  
  void setup() {
    Serial.begin(9600);
    Environment.begin();
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

  float humidity;

  void setup() {
    Serial.begin(9600);
    Environment.begin();
  }

  void loop() {
    humidity = Environment.readHumidity();
    Serial.print("Humidity: ");
    Serial.print(humidity);  //print humidity
  }
```
