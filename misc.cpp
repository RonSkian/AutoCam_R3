//#include <LiquidCrystal.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "globalVariables.h"
//#include "menu.h"
//#include "rotaryEncoder.h"
//#include "cameraActions.h"
#include "misc.h"
#include "initialization.h"
//#include "fonts.h"
#include "stepperMotor.h"

int delaySeconds_chk(unsigned int dV){
	if(cSec == dV){
		TIMSK1 &= (0 << OCIE1A);	//turn off timer2 compA interrupt
		cSec = 0;
		return 1;
	}
	else if(cSec > dV){
		//do something that says it went over...
	}
	else{
		return 0;	//wait time isn't done yet
	}
}

void delaySeconds_ini(void){
	TIMSK1 = (1 << OCIE1A);	//turn on timer2 compA interrupt
	cSec = 0;	//cSec reset
}


// int delaySeconds_ini(unsigned char s, unsigned int dV){		// s = state (0 for OFF or 1 for ON), dV = delay value

	// switch(s){
	// case 0:		//OFF-OFF state
		
		// break;
	// case 1:		//OFF-ON state
		
		// break;
	// case 2:		//ON-ON state
		// if(cSec == dV){
			// //turn off timer2 compA interrupt
			// //cSec reset
			// //return 1;
			// //
		// }
		// else{
			// //wait time isn't done yet
			// //return 0;
		// }
		// break;
	// case 3:		//ON-OFF state
		// break;
	// default:	
		// break;
	// }

// }