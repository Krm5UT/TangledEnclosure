#include <Servo.h>

// Servo Objects
Servo flowerServo;
Servo gothelRunServo;
Servo hairServo;
Servo gothelFallServo;
Servo weddingServo;

// Servo Pins
const int flowerServoPin = 2;
const int gothelRunPin   = 4;
const int hairServoPin   = 6;
const int gothelFallPin  = 8;
const int weddingServoPin = 10;

// Button Pins (INPUT_PULLUP = pressed LOW)
const int moonButtPin   = 3;
const int flowerButtPin = 5;
const int flynnButtPin  = 7;
const int hairButtPin   = 9;
const int sunButtPin    = 11;

// Button Last States
int lastMoonButtState;
int lastFlowerButtState;
int lastFlynnButtState;
int lastHairButtState;
int lastSunButtState;

// Story Progress Flags
bool moon = false;
bool flower = false;
bool flynn = false;
bool hair = false;
bool sun = false;

// Print "The End" Once
bool printedEnd = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Place moon into position");

  // Enable Internal Pull-Ups
  pinMode(moonButtPin, INPUT_PULLUP);
  pinMode(flowerButtPin, INPUT_PULLUP);
  pinMode(flynnButtPin, INPUT_PULLUP);
  pinMode(hairButtPin, INPUT_PULLUP);
  pinMode(sunButtPin, INPUT_PULLUP);

  // Read Initial Button States
  lastMoonButtState   = digitalRead(moonButtPin);
  lastFlowerButtState = digitalRead(flowerButtPin);
  lastFlynnButtState  = digitalRead(flynnButtPin);
  lastHairButtState   = digitalRead(hairButtPin);
  lastSunButtState    = digitalRead(sunButtPin);
  
  flowerServo.attach(flowerServoPin);
}

void loop() {

  // FIRST INTERACTION: MOON
  int moonState = digitalRead(moonButtPin);

  // Debug print to see what's happening
  // Serial.print("Moon button state: ");
  // Serial.println(moonState);

  // Detect LOW → HIGH
  if (!moon && lastMoonButtState == LOW && moonState == HIGH) {
     Serial.println("Night Falls TRIGGERED");

     flowerServo.write(0);
     delay(500);
     flowerServo.detach();

     moon = true;
     Serial.println("Place Flower into Position");
   }

   lastMoonButtState = moonState;

  // // SECOND INTERACTION: FLOWER/GOTHEL
  // int flowerState = digitalRead(flowerButtPin);
  // if (moon && !flower && lastFlowerButtState == HIGH && flowerState == LOW) {
  //   Serial.println("The royal baby was snatched!");

  //   gothelRunServo.attach(gothelRunPin);
  //   gothelRunServo.write(45);
  //   delay(500);
  //   gothelRunServo.detach();

  //   flower = true;
  // }
  // lastFlowerButtState = flowerState;



  // // THRID INTERACTION: FLYNN
  // int flynnState = digitalRead(flynnButtPin);
  // if (flower && !flynn && lastFlynnButtState == HIGH && flynnState == LOW) {
  //   Serial.println("Rapunzel has let down her hair!");

  //   hairServo.attach(hairServoPin);
  //   hairServo.write(45);
  //   delay(500);
  //   hairServo.detach();

  //   flynn = true;
  // }
  // lastFlynnButtState = flynnState;



  // // FOURTH INTERACTION: HAIR CUT
  // int hairState = digitalRead(hairButtPin);
  // if (flynn && !hair && lastHairButtState == HIGH && hairState == LOW) {
  //   Serial.println("The hair has been cut! Mother Gothel screeches and falls from the tower!");

  //   gothelFallServo.attach(gothelFallPin);
  //   gothelFallServo.write(45);
  //   delay(500);
  //   gothelFallServo.detach();

  //   hair = true;
  // }
  // lastHairButtState = hairState;



  // // FIFTH INTERACTION: WEDDING
  // int sunState = digitalRead(sunButtPin);
  // if (hair && !sun && lastSunButtState == HIGH && sunState == LOW) {
  //   Serial.println("Rapunzel & Flynn are soon to be wed, and they live happily ever after.");

  //   weddingServo.attach(weddingServoPin);
  //   weddingServo.write(45);
  //   delay(500);
  //   weddingServo.detach();

  //   sun = true;
  // }
  // lastSunButtState = sunState;



  // // PRINT END
  // if (sun && !printedEnd) {
  //   Serial.println("The End!");
  //   printedEnd = true;
  // }
  
}
