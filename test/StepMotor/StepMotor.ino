

#include <AccelStepper.h>
const byte Fullstep = 4;
const byte Halfstep = 8;
const short fullRevolution = 2038;
const float SteppDegree = 11.32; // Halfstep 11.32 - Fullstep 5.66

int senssor = 7;
int senssorStatus = 0;
// Pins IN1-IN3-IN2-IN4
AccelStepper stepper1(Halfstep, 11, 9, 10, 8);

void setup(void) {
  stepper1.setMaxSpeed(1000.0);   // set the maximum speed
  stepper1.setAcceleration(50); // set acceleration
  stepper1.setSpeed(1000);         // set initial speed
  stepper1.setCurrentPosition(0); // set position

	pinMode(senssor, INPUT);
}

void loop(void) {

  //float degree = 90;  // im Uhrzeigersinn
  //float moveRev = degree * SteppDegree;
  stepper1.moveTo(90 * SteppDegree);  // - für Uhrzeigersinn
  while (stepper1.distanceToGo() != 0) {
    stepper1.run();
	}
	delay(1000);

  stepper1.moveTo(0);  // - für Uhrzeigersinn
  while (stepper1.distanceToGo() != 0) {
    stepper1.run();
	}
	delay(1000);
}