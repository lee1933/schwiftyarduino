#include <LedControl.h> //import LedControl library

int DIN=10;           // initialize data in at pin 10
int CS= 11;           // initialize chip select at pin 11
int CLK=12;           // initialize clock pulse source at pin 12
int delay_time=500;

// alien invader animation in hexadecimal (2 frames)
byte alien[]= {0x24,0x24,0x7E,0xDB,0xDB,0xFF,0xA5,0x24};
byte alien2[]= {0x24,0xA5,0xFF,0xDB,0xDB,0x7E,0x24,0x42};

// squid animation in hexa and binary form 
byte squid[]= {0x18,0x3C,0x7E,0xDB,0xFF,0x24,0x42,0xA5};
byte squid2[]= 
{

B00011000,
B00111100,
B01111110,
B11011011,
B11111111,
B00100100,
B01000010,
B01000010
};

LedControl lc=LedControl(DIN, CLK, CS, 0);

void setup() {
  // put your setup code here, to run once:
lc.shutdown(0,false);         // wake up LED matrix 
lc.setIntensity(0,8);         // set brightness to medium 
lc.clearDisplay(0);             // switches of all LEDs on matrix 
}

void loop() {
  printByte(alien);
  delay(delay_time);
  printByte(alien2);
  delay(delay_time);
  printByte(squid);
  delay(delay_time);
  printByte(squid2);
  delay(delay_time);

}

// printByte lights up the LED matrix by rows.
void printByte( byte character[]){
  // loops 8 times 
  for (int i=0;i<8;i++)
  {
    // lights up the LED by rows with each matrix indexing 
    lc.setRow(0,i,character[i]);
  }
}

  

