// Combined Demo by Marc MERLIN <marc_soft@merlins.org>

#include "Arduino_SensorKit.h"

uint8_t button = 4;
uint8_t led = 6;
uint8_t pot = A0;
uint8_t mic = A2;
uint8_t light = A3;

// From https://playground.arduino.cc/Main/I2cScanner/
// learn more about I2C here
// https://www.seeedstudio.com/blog/2019/09/25/uart-vs-i2c-vs-spi-communication-protocols-and-uses/
// Scanner from https://github.com/RobTillaart/Arduino/blob/master/sketches/MultiSpeedI2CScanner/MultiSpeedI2CScanner.ino
// 30038	25	0x19		V	V	V	V	V	V	V	V
// 30133	60	0x3C		V	V	V	V	V	V	V	V
// 30296	119	0x77		V	V	V	V	V	V	V	V
void i2c_scan() {
  uint8_t error, address, nDevices;
 
  Wire.begin();
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    //Serial.println("I2C scan");
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
}

void setup() {
  Serial.begin(115200);
  // Running scan stops the OLED from working
  //i2c_scan();

  pinMode(mic , INPUT);
  pinMode(light , INPUT);

  pinMode(button , INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  Environment.begin();

  Oled.begin();
  Oled.setFlipMode(true);

  // Enabling any of those 2 stops the OLED from working
  //Accelerometer.begin();
  //Pressure.begin();
}

void loop() {

  Oled.setFont(u8x8_font_amstrad_cpc_extended_r); 

  #if 0
  Oled.setCursor(0, 0);
  Oled.print("x:"); 
  Oled.print(Accelerometer.readX()); 
  Oled.print("  ");
  Oled.print("y:"); 
  Oled.print(Accelerometer.readY());        
  Oled.print("  ");
  Oled.print("z:"); 
  Oled.print(Accelerometer.readZ());
  // Similar problem with pressure sensor
  Oled.print(Pressure.readAltitude());
  #endif

  Oled.setCursor(0, 0);
  Oled.print("But:"); 
  if (digitalRead(button)) {
    digitalWrite(led, HIGH);
    Oled.print("1"); 
  } else {
    digitalWrite(led, LOW);
    Oled.print("0"); 
  }

  // https://github.com/olikraus/u8g2/wiki/u8x8reference#print
  // looks like we need an offset of 9 for a font of 8
  // if the offset is wrong, the text gets displayed on
  // the wrong line
  uint16_t pot_value = analogRead(pot);
  Oled.setCursor(0, 9);
  Oled.print("Pot: ");
  Oled.print(pot_value);
  Oled.print("   ");

  uint16_t mic_value = analogRead(mic);
  Oled.setCursor(0, 18);
  Oled.print("Mic: ");
  Oled.print(mic_value);
  Oled.print("   ");

  uint16_t light_value = analogRead(light);
  Oled.setCursor(0, 27);
  Oled.print("Light: ");
  Oled.print(light_value);
  Oled.print("   ");

  Oled.setCursor(0, 45);
  Oled.print("Temp:");
  Oled.print(Environment.readTemperature());
  Oled.print("C");

  Oled.setCursor(0, 54);
  Oled.print("Hum: ");
  Oled.print(Environment.readHumidity());
  Oled.print("%");

  Oled.refreshDisplay();
  delay(100);
}
