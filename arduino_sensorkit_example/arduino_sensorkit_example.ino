#include <Arduino_Grove_Lib.h>

BreakoutBoard board; 

void setup() {

/*
// Initialise Accelerometer 
Serial.begin(115200); 
board.init_Accelerometer();
*/

/*
// Initialise Pressure Sensor
Serial.begin(9600);
board.init_PressureSensor(); 
*/

// Initialise OLED Screen
Serial.begin(9600);
board.init_OLEDScreen(); 

}

void loop() {

/*
// Printing values from the accelerometer
Serial.println(board.getAccelerationValue('X'));
Serial.println(board.getAccelerationValue('Y'));
Serial.println(board.getAccelerationValue('Z'));
*/

/*
// Printing values from the Pressure sensor
Serial.println(board.getPressureValue());
Serial.println(board.getAltitudeValue());
delay(200);
*/

//Printing values on the OLED Screen
board.setLabel("TEMPERATURE");
board.setValue_int(random(30,60));
board.setValue_float(random(30.0,60.0));

}
