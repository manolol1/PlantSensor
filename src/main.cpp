#include <Arduino.h>

// define pin numbers
const int SENSOR1 = 25;
const int SENSOR2 = 26;
const int LED1 = 5;
const int LED2 = 18;

// define threshold values for plant dryness - might need further testing and optimization
const int PLANT1_THRESHOLD = 2400;
const int PLANT2_THRESHOLD = 2400;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read values from sensors
  int plant1Value = analogRead(SENSOR1);
  int plant2Value = analogRead(SENSOR2);

  // determine status of plants
  bool isPlant1Dry = plant1Value > PLANT1_THRESHOLD;
  bool isPlant2Dry = plant2Value > PLANT2_THRESHOLD;

  // control LEDs
  if(isPlant1Dry){
    digitalWrite(LED1, HIGH);
  } else{
    digitalWrite(LED1, LOW);
  }

  if(isPlant2Dry){
    digitalWrite(LED2, HIGH);
  } else{
    digitalWrite(LED2, LOW);
  }

  // log sensor data and plant status to serial output
  Serial.println("------------------");
  Serial.print("Plant 1: ");
  Serial.print(plant1Value);
  Serial.print("  ");
  Serial.println(isPlant1Dry);

  Serial.print("Plant 2: ");
  Serial.print(plant2Value);
  Serial.print("  ");
  Serial.println(isPlant2Dry);

  delay(1000);
}