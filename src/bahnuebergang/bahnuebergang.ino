#include <Servo.h>
int senssor = 7;
Servo sranke;
int senssorStatus = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(senssor, INPUT);
  sranke.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(senssorStatus == 0 & digitalRead(senssor) == HIGH) {
    sranke.write(0);
    while(digitalRead(senssor) == HIGH) delay(100);
    senssorStatus=1;
  }
  else if(senssorStatus == 1 & digitalRead(senssor) == HIGH){
    sranke.write(90);
    while(digitalRead(senssor) == HIGH) delay(100);
    senssorStatus=0;
  }
}
