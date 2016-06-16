/* This sketch allows users to manipulate the RGB led such that it fades from blue to red, 
  red to green and back to blue, continuing the cycle */


#define redpin 11      // red pin of the RGB led is connected to pin 11
#define greenpin 10   // green pin of the RGB led is connected to pin 10
#define bluepin 9    // blue pin of the RGB led is connected to pin 9

void setup() {
  pinMode(redpin, OUTPUT);      //initialize pin 11 as output
  pinMode(greenpin,OUTPUT);     //initialize pin 10 as output
  pinMode(bluepin, OUTPUT);     //initialize pin 9 as output
}

void loop() {
  // blue color fades into red
  for (int i=0; i<256;i++) {
    analogWrite(redpin, i);
    analogWrite(bluepin, 255-i);
    analogWrite(greenpin, 0);
    delay(30);
  }
  // red color fades into green
  for (int i=0; i<256; i++) {
    analogWrite(redpin, 255-i);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, i);
    delay(50);
  }
  // green color fades into blue 
  for (int i=0; i<256; i++) {
    analogWrite(redpin, 0);
    analogWrite(bluepin, i);
    analogWrite(greenpin, 255-i);
    delay(50);
  }
}

