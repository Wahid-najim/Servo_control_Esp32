#include <ESP32Servo.h>

const int potPins[] = {39, 34, 35, 32};

const int servoPins[] = {17, 5, 18, 19};
const int numServos = 4;

Servo servos[numServos]; 

void setup() {

  for (int i = 0; i < numServos; i++) {
    servos[i].attach(servoPins[i]);
  }
}

void loop() {
  for (int i = 0; i < numServos; i++) {
    int potValue = analogRead(potPins[i]); 
    int angle = map(potValue, 0, 4095, 0, 180); 
    servos[i].write(angle); 
  }
  delay(15); 
}
