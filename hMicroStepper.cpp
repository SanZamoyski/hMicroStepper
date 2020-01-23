/*
  microStepper.cpp - Library for stepper motor driving
  Created by San Zamoyski, 30.05.2017, updated in 2020

  based on 
  Clayton P. Webster, February 20th, 2010
  Released into the public domain
*/

#include "Arduino.h"
#include "hMicroStepper.h"


							//non-pwm	pwm		non-pwm		pwm
hMicroStepper::hMicroStepper(int coil1a, int coil1b, int coil2a, int coil2b, int steps)
{
  pinMode(coil1a, OUTPUT);
  pinMode(coil1b, OUTPUT);
  pinMode(coil2a, OUTPUT);
  pinMode(coil2b, OUTPUT);
  
  //TODO: enable hight PWM frequency in library
  // so it's even smoother
  //Serial.println("Setting coils freq");
  //setPwmFrequency(coil1b, 1);
  //setPwmFrequency(coil2b, 1);
  
  _increment = microsteps/steps;
  
  _coil1a = coil1a;
  _coil1b = coil1b;
  _coil2a = coil2a;
  _coil2b = coil2b;
  _counter = 1;
  
}


void hMicroStepper::disable()
{
  digitalWrite(_coil1a, LOW);
  digitalWrite(_coil1b, LOW);
  digitalWrite(_coil2a, LOW);
  digitalWrite(_coil2b, LOW);
}

void hMicroStepper::takestep(boolean invert)
{
    if (invert) { // CW
      _counter = _counter - _increment;
      
      // reset counter if they go too low
      if (_counter < 0) {
         _counter = (_counter+microsteps)%microsteps;
      }
    }
    else { // CCW
      _counter = _counter + _increment;
      
      // roll over counter if they go too high
      if (_counter >= microsteps) {
            _counter = _counter%microsteps;
      }
    }

	// use analogWrite to create pwm for each MOSFET
    digitalWrite(_coil1a, _steps[_counter][0]);
    analogWrite(_coil1b, _steps[_counter][1]);
    digitalWrite(_coil2a, _steps[_counter][2]);
    analogWrite(_coil2b, _steps[_counter][3]);
}
