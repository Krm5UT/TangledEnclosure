#include <Servo.h>

Servo flowerServo;  // create Servo object to control a servo
int flowerButt;
const int flowerButtPin = 3;
int flowerButtState = 0;
int lastflowerButtState = 0;
int flowerButtVal;
bool flower = false;

const int moonButt;

Servo hairServo;  // create Servo object to control a servo
int flynnButt;
const int flynnButtPin = 3;
int flynnButtState = 0;
int lastflynnButtState = 0;
int flynnButtVal;
bool flynn = false;



Servo gothelServo;
const int sunButton;



int pos = 0;                       // variable to store the servo position
int increment = 1;                 // direction of movement (1 or -1)
unsigned long previousMillis = 0;  // stores last time servo was updated
const long interval = 15;          // interval between updates (milliseconds)

void setup() {
  Serial.begin(9600);
  flowerServo.attach(2);  // attaches the servo on pin 9 to the Servo object
  pinMode(flowerButt, INPUT);

  hairServo.attach(4);
  pinMode(flynnButt, INPUT);

  // gothelServo.attach(6);

  // pinMode(sunButton, INPUT);
}

void loop() {
  flowerButtVal = digitalRead(flowerButtPin);
  Serial.println(flowerButtVal);
  flowerButtState = digitalRead(flowerButtPin);  // Read directly into flowerButtState
  unsigned long currentMillis = millis();


  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (flowerButtState != lastflowerButtState) {
      if (flowerButtState == HIGH) {
        Serial.println("MoonLanding affirmative");
        flowerServo.write(45);
        flower = true;
      } else {
        flowerServo.write(0);
        flower = false;
      }
      lastflowerButtState = flowerButtState;  // Update inside the if block
    }
  }

 void loop() {
  flynnButtVal = digitalRead(flynnButtPin);
  Serial.println(flynnButtVal);
  flynnButtState = digitalRead(flynnButtPin);  // Read directly into flynnButtState
  unsigned long currentMillis = millis();


  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (flynnButtState != lastflynnButtState) {
      if (flynnButtState == HIGH) {
        Serial.println("MoonLanding affirmative");
        flynnServo.write(45);
        flynn = true;
      } else {
        flynnServo.write(0);
        flynn = false;
      }
      lastflynnButtState = flynnButtState;  // Update inside the if block
    }
  }
}
