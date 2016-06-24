/* This sketch detects analog signals from the potentiometers 
within the joystick and sends it to the serial monitor */

int x_coordinate=0;       // x-direction pin of joystick connected to analog A0
int y_coordinate=1;       // y-direction pin of joystick connected to analog A1
int button=3;             // push button of joystick connected to digital pin 3

void setup(){
// pushbutton initialized as input, establish serial communication at 9600bps, initialize button as 1 
pinMode(button, INPUT);
Serial.begin(9600);
digitalWrite(button, HIGH);
}

void loop() {
  Serial.print("Switch:");
  Serial.print(digitalRead(button));  // determine if button of joystick is engaged or not
  Serial.print("\n");                 //establishes a new line 
  Serial.print("X-coordinate:");       
  Serial.print(analogRead(x_coordinate));   // determine value of x-potentiometer (0-1023)
  Serial.print("\n");                     //establishes a new line 
  Serial.print("Y-coordinate:");
  Serial.print(analogRead(y_coordinate));   // determine value of y-potentiometer (0-1023)
  Serial.print("\n\n");                   //establishes 2 new lines 
  delay(1000);                            // delay between each reading for stability 
}

//.json 
