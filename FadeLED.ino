

int led=6;
int brightness=0;
int interval=5;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
brightness+=interval;
analogWrite(led,brightness);
if (brightness==0) { interval=-interval;}
if (brightness==255) {interval= -interval;}
delay(30);
}
  

