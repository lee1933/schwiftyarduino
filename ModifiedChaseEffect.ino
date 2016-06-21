/* This sketch allows users to manipulate LEDs such that they flash sequentially from one to the other*/

byte ledPin[]= {0,1,2,3,4,5,6,7,8};       //initialize the leds in pins 0-8 in an array
int direction=1;                          // increment of 1. This allows the code to cycle through every led
int currentLED=0;                         // a counter that starts from pin 0
unsigned long changeTime;                 // a variable that describes how much time has passed 
int pot=2 ;                               // initialize potentiometer at analog pin A2

void setup() {
  //initializes every pin as an output. millis() calculates how much time the Arduino began 
  //running in milliseconds and is stored in changeTime. Since the program will run this just once, changeTime=0
  for (int x=0; x<9 ; x++){              
      pinMode(ledPin[x],OUTPUT); }
      changeTime=millis();
}

void loop() {
  // Calculates the difference in time between how long the Arduino started running and the last registered time the LED blinked
   int ledDelay=analogRead(pot);        // delay between each LED is dictated by potentiometer value 0-1023.
   if ((millis()-changeTime)>ledDelay) {
      changeLED();
      changeTime=millis();
 
   }
}

void changeLED(){
    // turns all the 9 LEDs OFF 
    for(int x=0; x<9; x++) {
        digitalWrite(ledPin[x], LOW);    
    }
    digitalWrite(ledPin[currentLED],HIGH);
    currentLED+=direction;
    if (currentLED==8) {direction= -1;} // after the last LED, it will go backward
    if (currentLED==0) {direction=1;}   // after the first LED, it will go forward

}

