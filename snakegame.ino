/* 
 - This sketch allows the users to re-create the retro snake game on the Arduino and 
 LED Matrix w MAX7219.
 - This sketch was created by Rostislav Pokorny so all credits go to him! 
 - Sketch is in Slovenian btw.
 */

#include "LedControl.h"
#include "pitches.h"
 
//Konstanty - 8x8 Matrix
const byte DIN = 5;
const byte CLK = 3;
const byte CS = 4;
LedControl lc = LedControl(DIN, CLK, CS, 1); // 1 = počet řadičů
 
//Konstanty - Tlačítka
const byte btnPrava = 13; // right 
const byte btnLeva = 12; // left 
const byte btnHorni = 11;// up
const byte btnDolni = 7; // down 
 
//Konstanty - Speaker
const byte speaker = 9;
 
///////////////////////////////////////////////////////////////////
//Proměnné
int had[8][8] = {0};
 
byte xHad = 4;
byte yHad = 5;
byte xPotrava = 0;
byte yPotrava = 0;
 
byte smer = 0;
int krok = 1;
long CasZmeny = 0;
int rychlost = 500;
byte skore = 0;
 
boolean snezeno = false;
boolean zvuk = true;
boolean probehlo = false;
 
///////////////////////////////////////////////////////////////////
//Deklarovaní melodie
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
 
//Deklarování čísel
int Cislo[11][7] = {
  {B00000000,B00000000,B00000000,B00000000,B00000001,B01111111,B00100001}, //1
  {B00000000,B00000000,B00110001,B01001001,B01000101,B00100011},//2
  {B00000000,B00000000,B01000110,B01101001,B01010001,B01000001,B01000010},//3
  {B00000000,B00001000,B11111111,B01001000,B00101000,B00011000,B00001000},//4
  {B00000000,B00000000,B00111110,B01000101,B01001001,B01010001,B00111110}, //5
  {B00000000,B00000000,B00000110,B01001001,B01001001,B00101001,B00011110}, //6
  {B00000000,B00000000,B01110000,B01001000,B01000111,B01000000,B01100000}, //7
  {B00000000,B00000000,B00110110,B01001001,B01001001,B01001001,B00110110}, //8
  {B00000000,B00000000,B00111100,B01001010,B01001001,B01001001,B00110000}, //9
  {B00000000,B00000000,B00111110,B01010001,B01001001,B01000101,B00111110}, //0
  {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}, //mezera
  };
 
void setup() {
  Serial.begin(9600);
  Serial.println("Hra Snake zahajena");
 
  randomSeed(analogRead(A0));
  GenerujPotravu();
 
  pinMode(btnLeva, INPUT_PULLUP);
  pinMode(btnPrava, INPUT_PULLUP);
  pinMode(btnHorni, INPUT_PULLUP);
  pinMode(btnDolni, INPUT_PULLUP);
 
  pinMode(speaker, OUTPUT);
 
  //Nactení 8x8 displeje
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
}
 
void loop() {
  if ((digitalRead(btnLeva) == false) && (smer != 0)) smer = 1;
  if ((digitalRead(btnPrava) == false) && (smer != 1)) smer = 0;
  if ((digitalRead(btnHorni) == false) && (smer != 3)) smer = 2;
  if ((digitalRead(btnDolni) == false) && (smer != 2)) smer = 3;
 
  if ((millis() - CasZmeny) > rychlost) {
    CasZmeny = millis();
 
    VymazHada(had);
    Skore();
    Pohyb();
 
    if (xHad == xPotrava && yHad == yPotrava) snezeno = true;
    if (had[xHad][yHad] != 0) GameOver();
 
    krok++;
    had[xHad][yHad] = krok;
  }
  Vykres(had, xPotrava, yPotrava);
}
///////////////////////////////////////////////////////////////////
// Funkce
void Skore() {
  if (snezeno == true) {
    snezeno = false;
    GenerujPotravu();
 
    skore++;
    tone(speaker, NOTE_C5, 200);
    rychlost -= 20;
 
    Serial.print ("Skore je: ");
    Serial.println (skore);
  }
}
 
void Vykres(int matice[8][8], byte x, byte y) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((matice[i][j] >= 1) || ((i == x) && (j == y) )) lc.setLed(0, i, j, true);
      else lc.setLed(0, i, j, false);
    }
  }
}
 
void VymazHada(int matice[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (matice[i][j] == (krok - skore)) matice[i][j] = 0;
    }
  }
}
 
void Pohyb() {
  switch (smer) {
    case 0:
      xHad++;
      break;
    case 1:
      xHad--;
      break;
    case 2:
      yHad++;
      break;
    case 3:
      yHad--;
      break;
  }
  if (xHad == 8) xHad = 0;
  if (yHad == 8) yHad = 0;
  if (xHad == 255) xHad = 7;
  if (yHad == 255) yHad = 7;
}
 
void GenerujPotravu() {
  lc.setLed(0, xPotrava, yPotrava, false);
  do {
    xPotrava = random(0, 8);
    yPotrava = random(0, 8);
  } while (had[xPotrava][yPotrava] != 0 );
}
 
void VykresCislo(byte cislo){
  if(cislo ==0) cislo = 10;
    for (int col=0; col<7; col++) {
      lc.setRow(0, col, Cislo[cislo-1][col]);    
  }
}
 
void GameOver() {
  Serial.println ("Game over");
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (zvuk == true) {
        int noteDuration = 1000 / noteDurations[col];
        tone(speaker, melody[col], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(speaker);
      }
      lc.setLed(0,col,row, true);
      delay(25);
    }
    zvuk = false;
  }
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, col, row, false); 
      delay(25);
    }
  }
  do {
       VykresCislo((skore/10)%10);
  delay(200);
  VykresCislo(skore%10);
  delay(200);
  VykresCislo(11);
  delay(1000);
  } while (true);
}
