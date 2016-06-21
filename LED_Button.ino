/* This sketch allows users to turn LED on and off using a push button.Nosferatu*/ 

int led= 8;       // initialize LED at digital pin 8
int button=7;     // initialize push button at digital pin 7

void setup() {
 
  pinMode(led, OUTPUT);         // initialize digital pin 8 as OUTPUT
  pinMode(button, OUTPUT);      // initialize digital pin 7 as OUTPUT

}

void loop() {
  // ascertain if the push button is engaged or not by storing values of HIGH and LOW
  int buttonstate=digitalRead(button);
  if (buttonstate==0){
  // turn LED on 
  digitalWrite(led, HIGH);
  }
  else{
  // turn LED off 
  digitalWrite(led, LOW);
  }  
}
