#include "Arduino_SensorKit.h"

SensorKit kit;

int button = 4;
int LED = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);

  kit.begin();

  pinMode(button , INPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button)) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
