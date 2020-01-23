#include <hMicroStepper.h>
#include <Stepper.h>

// make sure to use PWM pins for motors if you plan on using microstepping
//arduino nano PWM pins: 3, 5, 6, 9, 10, 12

//Example pins for motors:
//MOTOR A: 2, 3, 4, 5
//MOTOR B: 6, 7, 8, 12

const int x_coil1a = 7;   //non_pwm
const int x_coil1b = 6;   //pwm
const int x_coil2a = 8;   //non_pwm
const int x_coil2b = 12;  //pwm

int i;

//4 is full step (normal operation), 32 is max resolution for this library
const int resolution = 32;

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// initialize both libraries on definied pins
Stepper myStepper(stepsPerRevolution, x_coil1a, x_coil1b, x_coil2a, x_coil2b);
hMicroStepper uStepper(x_coil1a, x_coil1b, x_coil2a, x_coil2b, resolution);

void setup()
{
  myStepper.setSpeed(2000);

  //TODO: set PWM to high frequency, for even smoother run.
}

void loop()
{
  i = 0;
  while(i<400) {
    uStepper.takestep(true);
    delay(32*4/resolution);
    i++;
  }  

  i = 0;
  while(i<400*4/resolution) {
    myStepper.step(-1);
    delay(32);
    i++;
  }  
}
