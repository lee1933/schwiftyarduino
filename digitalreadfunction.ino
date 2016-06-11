/* This sketch allows users to determine the state of the push button by 
displaying it on a serial monitor through serial connection */


int pushButton = 7;     // digital pin 7 has a push button

void setup() {
  // initialize serial communication between Arduino and serial monitor at 9600 bits per second:
  Serial.begin(9600);
  // initialize push button as input
  pinMode(pushButton, INPUT);
}

void loop() {
  // read the input pin and stores in buttonState
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (buttonState==1){
  Serial.println("ON");
  }
  else {
  Serial.println("OFF");
  delay(100);  // delay in between reads for stability
  }
}

// Adapted from DigitalReadSerial sketch in Arduino IDE 


