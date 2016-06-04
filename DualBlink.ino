/* This sketch allows users to control two leds such that they blink in an alternate fashion. */
int led1=8; //  initialize red led in digital pin 8
int led2=2; //  initialize green led in digital pin 2

void setup() {
  pinMode(led1,OUTPUT); // initialize digital pin 8 as output
  pinMode(led2,OUTPUT); //  initialize digital pin 2 as output  
}

void loop() {
  digitalWrite(led1,HIGH);  //turns red led on
  digitalWrite(led2,LOW);   // turns green led off 
  delay(500);               // holds for 0.5 sec
  digitalWrite(led1,LOW);   //turns red led off
  digitalWrite(led2,HIGH);  //turns green led on
  delay(500);               //hold for 0.5 sec 

}



//lostboy
