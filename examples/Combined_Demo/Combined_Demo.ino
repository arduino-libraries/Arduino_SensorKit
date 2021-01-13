// Combined Demo by Marc MERLIN <marc_soft@merlins.org>

#include "Arduino_SensorKit.h"
#define BUZZER 5

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

  Accelerometer.begin();
  Pressure.begin();

  pinMode(BUZZER, OUTPUT);
}

void loop() {

  Oled.setFont(u8x8_font_amstrad_cpc_extended_r); 

  // when using u8g8 instead of u8g2, cursor values
  // are in characters, not pixels
  Oled.setCursor(0, 4);
  // If accelerometer and altimeter are queried too close to one another
  // this causes a hang, so we read this first.
  Oled.print("x:"); 
  Oled.print(Accelerometer.readX()); 
  Oled.print(" y:"); 
  Oled.print(Accelerometer.readY());        
  Oled.setCursor(0, 5);
  Oled.print("z:"); 
  Oled.print(Accelerometer.readZ());
  Oled.print(" T:");
  Oled.print(Environment.readTemperature());
  Oled.print("C");

  Oled.setCursor(0, 0);
  Oled.print("But:"); 

  uint16_t pot_value = analogRead(pot);
  if (digitalRead(button)) {
    digitalWrite(led, HIGH);
    Oled.print("1"); 
    tone(BUZZER, pot_value);
  } else {
    digitalWrite(led, LOW);
    Oled.print("0"); 
    noTone(BUZZER);
  }

  Oled.setCursor(0, 1);
  Oled.print("BuzPot: ");
  Oled.print(pot_value);
  Oled.print("Hz  ");

  uint16_t mic_value = analogRead(mic);
  Oled.setCursor(0, 2);
  Oled.print("Mic: ");
  Oled.print(mic_value);
  Oled.print("   ");

  uint16_t light_value = analogRead(light);
  Oled.setCursor(0, 3);
  Oled.print("Light: ");
  Oled.print(light_value);
  Oled.print("   ");

  Oled.setCursor(0, 6);
  Oled.print("Hum: ");
  Oled.print(Environment.readHumidity());
  Oled.print("%");

  Oled.setCursor(0, 7);
  Oled.print("Alt:"); 
  Oled.print(Pressure.readAltitude());

  delay(100);
}
