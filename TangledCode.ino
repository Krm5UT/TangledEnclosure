#include <Servo.h>

Servo flowerServo;  // create Servo object to control a servo
int flowerButt;
const int flowerButtPin = 3;
int flowerButtState = 0;
int lastflowerButtState = 0;
int flowerButtVal;
bool flower = false;

const int moonButton;
Servo hairServo;
const int flynnButton;
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

  // hairServo.attach(5);
  // pinMode(flynnButt, INPUT);

  // gothelServo.attach(8);

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
}
