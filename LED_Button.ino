/* This sketch allows users to turn LED on and off using a push button.Nosferatu*/ 

int led= 8;       // initialize LED at digital pin 8
int button=2;     // initialize push button at digital pin 7

void setup() {
 
  pinMode(led, OUTPUT);         // initialize digital pin 8 as OUTPUT
  pinMode(button, INPUT);       // initialize digital pin 2 as INPUT
 
}

void loop() {
  // ascertain if the push button is engaged or not by storing values of HIGH and LOW
  int buttonstate=digitalRead(button);
  if (buttonstate==1){
  // turn LED on 
  digitalWrite(led, HIGH);
  }
  else{
  // turn LED off 
  digitalWrite(led, LOW);
  }  
}
