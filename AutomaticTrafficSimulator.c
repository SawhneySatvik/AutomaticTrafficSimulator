#include <MyBlink.h>
#include <Arduino.h>

int sensorPinNorth = 2;
int sensorPinSouth = 3;
int sensorPinEast = 4;
int sensorPinWest = 5;

int redPinNorth = 6;
int greenPinNorth = 7;
int yellowPinNorth = 8;
int redPinSouth = 9;
int greenPinSouth = 10;
int yellowPinSouth = 11;
int redPinEast = 12;
int greenPinEast = 13;
int yellowPinEast = 14;
int redPinWest = 15;
int greenPinWest = 16;
int yellowPinWest = 17;

int greenLightTime = 10; 
int redLightTime = 5;
int yellowLightTime = 5;
unsigned long previousMillis = 0;

void setup() {
  pinMode(sensorPinNorth, INPUT);
  pinMode(sensorPinSouth, INPUT);
  pinMode(sensorPinEast, INPUT);
  pinMode(sensorPinWest, INPUT);
 
  pinMode(redPinNorth, OUTPUT);
  pinMode(greenPinNorth, OUTPUT);
  pinMode(yellowPinNorth, OUTPUT);
  
  pinMode(redPinSouth, OUTPUT);
  pinMode(greenPinSouth, OUTPUT);
  pinMode(yellowPinSouth, OUTPUT);
  
  pinMode(redPinWest, OUTPUT);
  pinMode(greenPinWest, OUTPUT);
  pinMode(yellowPinWest, OUTPUT);
  
  pinMode(redPinEast, OUTPUT);
  pinMode(greenPinEast, OUTPUT);
  pinMode(yellowPinEast, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  
  int sensorValueNorth = digitalRead(sensorPinNorth);
  int sensorValueSouth = digitalRead(sensorPinSouth);
  int sensorValueEast = digitalRead(sensorPinEast);
  int sensorValueWest = digitalRead(sensorPinWest);
  
  // Adjust traffic signal timings based on sensor data
  
  if (sensorValueNorth == HIGH || sensorValueSouth == HIGH || sensorValueEast == HIGH || sensorValueWest == HIGH) {
    // Vehicle detected on one of the roads
    greenLightTime = 5; // Adjust green light duration
    redLightTime = 10;  // Adjust red light duration
  } else {
    // No vehicle detected
    greenLightTime = 10; // Default green light duration
    redLightTime = 5;   // Default red light duration
  }

  // Control traffic signals for each direction
  if (currentMillis - previousMillis >= greenLightTime * 1000) {
    previousMillis = currentMillis;
  }

}
