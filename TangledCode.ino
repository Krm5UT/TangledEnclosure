#include <Servo.h>

Servo myservo;  // create Servo object to control a servo

int pos = 0;    // variable to store the servo position
int increment = 1;  // direction of movement (1 or -1)
unsigned long previousMillis = 0;  // stores last time servo was updated
const long interval = 15;  // interval between updates (milliseconds)

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if it's time to update the servo
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // save the last time we updated
    
    // Update servo position
    myservo.write(pos);
    
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
