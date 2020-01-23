/*
  microStepper.h - Library for stepper motor driving
  Created by San Zamoyski, 30.05.2017, updated in 2020

  based on
  Created by Clayton P. Webster, February 20th, 2010
  Released into the public domain
*/

#ifndef hmicroStepper_h // keep from including twice
#define hmicroStepper_h

#define microsteps 32

#include "Arduino.h"

class hMicroStepper
{
  public:
    hMicroStepper(int coil1a, int coil1b, int coil2a, int coil2b, int steps);
    void disable();
    void takestep(boolean invert);
    
  private:
    //void setPwmFrequency(int pin, int divisor);  
    
    int _coil1a;
    int _coil1b;
    int _coil2a;
    int _coil2b;
    
    int _counter;
    boolean _invert;
    byte _increment;
    //const int microsteps = 16;

	//8 steps: uint8_t microstepcurve[] = {0, 50, 98, 142, 180, 212, 236, 250, 255};
	//4 steps: uint8_t microstepcurve[] = {0, 98, 180, 236, 255};	//0
	//4 steps: uint8_t microstepcurve[] = {255, 157, 75, 19, 0};	//1
	byte _steps[microsteps][4] = {

        {	0	,	0	,	1	,	0	},
        {	1	,	205	,	1	,	5	},
        {	1	,	157	,	1	,	19	},
        {	1	,	113	,	1	,	43	},
        {	1	,	75	,	1	,	75	},
        {	1	,	43	,	1	,	113	},
        {	1	,	19	,	1	,	157	},
        {	1	,	5	,	1	,	205	},
        {	1	,	0	,	1	,	255	},
        {	1	,	5	,	0	,	50	},
        {	1	,	19	,	0	,	98	},
        {	1	,	43	,	0	,	142	},
        {	1	,	75	,	0	,	180	},
        {	1	,	113	,	0	,	212	},
        {	1	,	157	,	0	,	236	},
        {	1	,	205	,	0	,	250	},
        {	1	,	255	,	0	,	255	},
        {	0	,	50	,	0	,	250	},
        {	0	,	98	,	0	,	236	},
        {	0	,	142	,	0	,	212	},
        {	0	,	180	,	0	,	180	},
        {	0	,	212	,	0	,	142	},
        {	0	,	236	,	0	,	98	},
        {	0	,	250	,	0	,	50	},
        {	0	,	255	,	0	,	0	},
        {	0	,	250	,	1	,	205	},
        {	0	,	236	,	1	,	157	},
        {	0	,	212	,	1	,	113	},
        {	0	,	180	,	1	,	75	},
        {	0	,	142	,	1	,	43	},
        {	0	,	98	,	1	,	19	},
        {	0	,	50	,	1	,	5	}

	};
};

#endif


