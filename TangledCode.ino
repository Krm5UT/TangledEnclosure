#include <Servo.h>

Servo flowerServo;  // create Servo object to control a servo

// int moonButt; // I believe this is a syntax mistake
const int moonButtPin = 3;
int moonButtState = 0;
int lastmoonButtState = 0;
bool moon = false;

Servo gothelRunServo;

// int flowerButt;
const int flowerButtPin = 5;
int flowerButtState = 0;
int lastflowerButtState = 0;
// int flowerButtVal;
bool flower = false;

Servo hairServo;  // create Servo object to control a servo

// int flynnButt;
const int flynnButtPin = 7;
int flynnButtState = 0;
int lastflynnButtState = 0;
bool flynn = false;

Servo gothelFallServo;

// int hairButt;
const int hairButtPin = 9;
int hairButtState = 0;
int lasthairButtState = 0;
bool hair = false;

Servo weddingServo;

// int sunButt;
const int sunButtPin = 11;
int sunButtState = 0;
int lastsunButtState = 0;
bool sun = false;


// int pos = 0;                       // variable to store the servo position
// int increment = 1;                 // direction of movement (1 or -1)
// unsigned long previousMillis = 0;  // stores last time servo was updated
// const long interval = 15;          // interval between updates (milliseconds)

void setup() {
  Serial.begin(9600);
  Serial.println("Place moon into position");
  
  flowerServo.attach(2);  // attaches the servo on pin 2
  pinMode(moonButtPin, INPUT); // lists corresponding button

  gothelRunServo.attach(4);
  pinMode(flowerButtPin, INPUT);
    
  hairServo.attach(6);
  pinMode(flynnButtPin, INPUT);
  
  gothelFallServo.attach(8);
  pinMode(hairButtPin, INPUT);
  
  weddingServo.attach(10);
  pinMode(sunButtPin, INPUT);
}

void loop() {
  // flowerButtVal = digitalRead(moonButtPin); // for button testing purposes
  // Serial.println(moonButtVal);
  
  flynnButtState = digitalRead(flynnButtPin);
  hairButtState = digitalRead(hairButtPin);
  sunButtState = digitalRead(sunButtPin);
  
  // unsigned long currentMillis = millis(); // unused millis

  // First interaction
  moonButtState = digitalRead(moonButtPin);  // Moon button reads directly into moon button state
  if (moon == false) {
    flowerServo.write(0); // Sets initial position
  }
  if (moonButtState != lastmoonButtState) {
    if (moonButtState == HIGH) {
      Serial.println("Night Falls");
      flowerServo.write(45);
      moon = true;
    }
  }

  // Second interaction (Requires the 1st to have happened)
  if (moon == true) {
    flowerButtState = digitalRead(flowerButtPin);
    if (flower == false) {
      gothelRunServo.write(0); // Sets initial position
    }
  }
  if (flowerButtState != lastflowerButtState) {
    if (flowerButtState == HIGH) {
      Serial.println("The royal baby was snatched!");
      gothelRunServo.write(45);
      flower = true;
    }
  }

// Third interaction (Requires the 2nd to have happened)
  if (flower == true) {
    flynnButtState = digitalRead(flynnButtPin);
    if (flynn == false) {
      hairServo.write(0); // Sets initial position
    }
  }
  if (flynnButtState != lastflynnButtState) {
    if (flynnButtState == HIGH) {
      Serial.println("Rapunzel has let down her hair!");
      hairServo.write(45);
      flynn = true;
    }
 }

// Fourth interaction (Requires the 3rd to have happened)
  if (flynn == true) {
    hairButtState = digitalRead(hairButtPin);
    if (hair == false) {
      gothelFallServo.write(0); // Sets initial position
    }
  }
  if (hairButtState != lasthairButtState) {
    if (hairButtState == HIGH) {
      Serial.println("The hair has been cut! Mother Gothel screeches and falls from the tower!");
      gothelFallServo.write(45);
      hair = true;
    }
  }

// Final/Fifth interaction (Requires the 4th to have happened)
  if (hair == true) {
    sunButtState = digitalRead(sunButtPin);
    if (sun == false) {
      weddingServo.write(0); // Sets initial position
    }
  }
  if (sunButtState != lastsunButtState) {
    if (sunButtState == HIGH) {
      Serial.println("Rapunzel & Flynn are soon to be wed, and they live happily ever after.");
      weddingServo.write(45);
      sun = true;
      }
    }
    

  if (sun == true) { // If the final event has triggered = ends
    Serial.println("The End!");
  }

  // updates last state to avoid retriggering
  lastmoonButtState = moonButtState;
  lastflowerButtState = flowerButtState;
  lastflynnButtState = flynnButtState;
  lasthairButtState = hairButtState;
  lastsunButtState = sunButtState;
}

// Saving this vvv in case we need millis for coding but so far we do not
  // if (currentMillis - previousMillis >= interval) {
  //   previousMillis = currentMillis;

  //   if (moonButtState != lastmoonButtState) {
  //     if (moonButtState == HIGH) {
  //       Serial.println("MoonLanding affirmative");
  //       flowerServo.write(45);
  //       flower = true;
  //     } else {
  //       flowerServo.write(0);
  //       moon = false;
  //     }
  //     lastmoonButtState = moonButtState;  // Update inside the if block
  //   }
  // }
