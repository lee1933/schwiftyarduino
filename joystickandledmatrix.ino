/* This sketch detects analog signals from the potentiometers 
within the joystick and sends it to the serial monitor */

//initialize variable for x and y values on the joystick and the pushbutton at digital pin 4
int UD;
int LR ;
int button=4;

#include "LedControl.h" //  importing the library
// DIN to 10, CLK to 12, CS to 11
LedControl lc=LedControl(10,12,11,0);

void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  pinMode(button, INPUT); // button is input
  digitalWrite(button, HIGH); // initalize button as ON  

}

void loop() {
  UD = analogRead(A1); // read analog value at pin A1 and stores as UD
  LR = analogRead(A0);  // read analog value at pin A0 and stores as LR
  int state=digitalRead(button); //determines the state of button (HIGH or LOW)
  // scales down the value from 0-1023 to 0-7
  char x_translate = map(LR, 1021, 0, 0, 7); 
  char y_translate = map(UD, 1021, 0, 7, 0);

  Serial.print ("Button=");
  Serial.print(state, DEC);
  Serial.print(", UD = ");
  Serial.print(UD, DEC);
  Serial.print(", LR = ");
  Serial.print(LR, DEC);
  Serial.print(", x = ");
  Serial.print(x_translate, DEC); 
  Serial.print(", y = ");
  Serial.println(y_translate, DEC); 
  
    // clears display whenever a new value is updated 
    lc.clearDisplay(0);
    lc.setLed(0,x_translate,y_translate,true);  
    // if button is pressed, LED is OFF and vice versa 
    if (state==1){
    lc.setLed(0,x_translate,y_translate,true); 
    }
    else {
    lc.setLed(0,x_translate,y_translate,false); 
    }
   
  delay(150); //Mess with delay to tweak accuracy
}
