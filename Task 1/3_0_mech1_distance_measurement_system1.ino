//display code based on https://www.tinkercad.com/things/bDCy8OIxJWC-ht16k33-with-arduino

#include "Adafruit_LEDBackpack.h"
// variables
Adafruit_7segment display = Adafruit_7segment();
const int trigPin = 7;
const int echoPin = 6;
int RedLED = 5;
int YellowLED = 4;
int GreenLED = 3;

float duration, distance;

void setup() {
   display.begin(0x70);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  
  Serial.print(distance);
  Serial.println("cm");
  display.println(distance);
  display.writeDisplay();
  
  if(distance <= 100){
    digitalWrite(GreenLED, HIGH);
    digitalWrite(YellowLED, LOW);
    digitalWrite(RedLED, LOW);
  }
  else if(100 < distance && distance <= 200){
    digitalWrite(YellowLED, HIGH);
    digitalWrite(GreenLED, LOW);
    digitalWrite(RedLED, LOW);
  }
  else if(200 < distance){
    digitalWrite(RedLED, HIGH);
    digitalWrite(YellowLED, LOW);
    digitalWrite(GreenLED, LOW);
  }

}
