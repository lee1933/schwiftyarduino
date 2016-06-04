/* This sketch allows user to control the led such that is will blin on and then off continously */

int led=8; // initialize the led in pin 8

void setup() {
  pinMode(led, OUTPUT); // initialize led as output
}

void loop() {
  digitalWrite(led,HIGH);// turn led on 
  delay(500);            // led stays on for 0.5 sec
  digitalWrite(led,LOW);// turn led off 
  delay(500);           // led stays off for 0.5 sec
}




//lostboy
