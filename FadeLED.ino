/* This sketch allows users to manipulate an LED such that is fades in and out */

int led=6;              //initialize LED at digital pin 6
int brightness=0;       // LED brightness is OFF initially 
int interval=1;         // this dictates the rate at which the LED gradually gets brighter or dimmer 


void setup() {
  
  pinMode(led, OUTPUT); // initialize the LED as an output 

}

void loop() {
// the brightness of the LED increases by the rate   
brightness+=interval; 
// delivers an amount of power to the LED writing PWM signal with duty cycle 
analogWrite(led,brightness);
// if LED achieves peak brightness, it will start to get dimmer
if (brightness==255) { interval=-interval;}
// if LED is dimmed, it will gradually get brighter
if (brightness==0) {interval= -interval;}
// delay for stability 
delay(30);
}
  

