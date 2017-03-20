/*
  String to Integer conversion

 Reads a serial input string until it sees a newline, then converts
 the string to a number if the characters are digits.

 The circuit:
 No external components needed.

 created 29 Nov 2010
 by Tom Igoe

 This example code is in the public domain.
 */
#include <VarSpeedServo.h> 

VarSpeedServo servo;
String inString = "";    // string to hold input
int a;
int a_previous=800;
const int fastincrement = 10;
const int fastincrementdelay = 5;
const int slowincrement = 10;
const int slowincrementdelay = 50;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  servo.attach(9);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  servo.writeMicroseconds(800);
  Serial.println("Please provide a pulse width value between 800-2000(microseconds)");
 
}

void loop() {
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      
      Serial.print("Input pulse width value: ");
      a= inString.toInt();
      Serial.println(a);
      //Serial.print("String: ");
      //Serial.println(inString);
      // clear the string for new input:
      inString = "";
      if ((a >=800) && (a <=2000)){
        Serial.print("Input accepted:");
        Serial.println(a);
         if(a_previous>=a){            
          for (int x=a_previous; x>a; x-=slowincrement){
            servo.attach(9);
            servo.writeMicroseconds(x);
            delay (slowincrementdelay);
          }
          servo.detach();
          a_previous=a;
          Serial.print("Last recorded input:");
          Serial.println(a_previous);
        }
         if (a>a_previous){
          for (int x=a_previous; x<a; x+=fastincrement){
            servo.attach(9);
            servo.writeMicroseconds(x);
            delay (fastincrementdelay);
          }
          servo.detach();
          a_previous=a;
          Serial.print("Last recorded input:");
          Serial.println(a_previous);
        }
      }
      else {
        Serial.print("Input rejected:");
        Serial.println("Please provide a pulse width value between 800-2000(microseconds)");
      }
      }
    }
    
  }


