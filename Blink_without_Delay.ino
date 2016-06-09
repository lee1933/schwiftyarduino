/* This is another way to blink an LED without using the function delay() function */

int led=13;               //In this example, I am using the built-in LED of the Arduino
int ledDelay= 200;       // Time in milliseconds between each blink 
unsigned long changeTime; // unsigned long is generally use to hold time as the value gets too large for int to store
int ledstate=HIGH ;       // initialize LED as ON 


void setup() {
  pinMode(led,OUTPUT);    // initialize digital pin 13 as an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((millis()-changeTime)>=ledDelay){ //determines if the difference between current time and the last time the LED blinked is greater than the delay in each blink
  changeTime=millis();                  // updates changeTime to the last second LED blinked 
    if (ledstate==LOW) {                // if LED is off, turn it on 
        ledstate=HIGH;}
    else{                               // if LED is on, turn it off 
        ledstate=LOW;}
  
  digitalWrite(led, ledstate);
  }
}

-lostboy
