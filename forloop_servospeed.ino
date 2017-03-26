#include <VarSpeedServo.h> 

VarSpeedServo servo;
const int angleIncrement = 5;
const int incrementDelay = 10;

void setup() {
  // put your setup code here, to run once:
servo.attach(9);
servo.writeMicroseconds(2000);
}

void loop() {

for (int angle = 2000; angle >800; angle -= angleIncrement) { 
 servo.writeMicroseconds(angle);
 delay (incrementDelay); // so we'll take 10 * 180 milliseconds = 1.8 seconds for the traverse.
}
servo.detach();
}
