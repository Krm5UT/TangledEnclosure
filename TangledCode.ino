#include <Servo.h>

Servo flowerServo;  // create Servo object to control a servo
const int flowerButton;
const int moonButton; 
Servo hairServo;
const int flynnButton;
Servo gothelServo;
const int sunButton;

int pos = 0;    // variable to store the servo position
int increment = 1;  // direction of movement (1 or -1)
unsigned long previousMillis = 0;  // stores last time servo was updated
const long interval = 15;  // interval between updates (milliseconds)

void setup() {
  flowerServo.attach(2);  // attaches the servo on pin 9 to the Servo object
  pinMode(flowerButton, INPUT)

  hairServo.attach(5);
  pinMode(flynnButton, INPUT)

  gothelServo.attach(8);

  pinMode(sunButton, INPUT)
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if it's time to update the servo
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // save the last time we updated
    
    // Update servo position
    flowerServo.write(pos);
    
    // Move to next position
    pos += increment;
    
    // Reverse direction at limits
    if (pos >= 180) {
      pos = 180;
      increment = -1;
    } else if (pos <= 0) {
      pos = 0;
      increment = 1;
    }
  }
  
  // Your code is now non-blocking!
  // You can add other tasks here that will run continuously
}
