#include <Arduino.h>
#include "globalVariables.h"
#include "stepperMotor.h"
#include "misc.h"

#define stepsPerMM 3200/0.8	
//(stepperResolution/pitch)*stepperDistance
#define moduloDivider 10

void updt_stepperInfo(void){
	stepperDelay = (int)(((0.8*1000000)/(2*stepperSpeed*3200))); 
	// stepperDelay = (pitch*conversion to integer microsseconds)/(2*DesiredStepperSpeed*stepperResolution) -> units (mm/s), remember to put it in 1/16th steps
	SSMostSig = (int)stepperSpeed;								
	// Integer component Bit for stepperSpeed
	SSLeastSig = ((int)(stepperSpeed*10)%10);					
	// Decimal component for stepperSpeed
	
	stepperDistanceMS = stepperDistance/moduloDivider;
	stepperDistanceLS = stepperDistance%moduloDivider;
	
	CM_DistDivMS = CM_DistDiv/moduloDivider;
	CM_DistDivLS = CM_DistDiv%moduloDivider;
}

void step(unsigned char dir, unsigned char stepMS, unsigned char stepLS){
	// char dir = Direction (TRUE = CW = towards motor, FALSE = CCW = away from motor; note orientation is with the bottom of motor facing you)
	// char stepMS = Most significant step value
	// char stepLS = Least significant step value
	// e.g 1.5 mm, stepMS = 1, stepLS = 5

	enableMotor();			                            
	digitalWrite(A5,dir);										
	//Adjust the direction of rotation of stepper
	delayMicroseconds(10);

	if(stepMS>=1){
		for(int i=0;i<stepMS;i++){
			if(limSwHit == YES){
				break;
			}
			for(int j=0;j<moduloDivider;j++){	
				if(limSwHit == YES){
					break;
				}
				for(int k=0;k<stepsPerMM;k++){
					if(limSwHit == YES){
						break;
					}
					performStepping();
				}
			}
		}
	}
	if(stepLS>=1){	
		for(int i=0;i<stepLS;i++){
			if(limSwHit == YES){
				break;
			}		
			for(int j=0;j<stepsPerMM;j++){
				if(limSwHit == YES){
					break;
				}
				performStepping();
			}
		}
	}
	if(limSwHit == YES){
		digitalWrite(A5,!dir);									
		//Adjust the direction of rotation of stepper
		delayMicroseconds(10);
		reverseSteps();
		limSwHit = NO;
		digitalWrite(A2, limSwHit);
	}
}

void homeCarriage(unsigned char dir){
	// Homes the carriage towards either side of the rail, does not stop until it hits a limit switch or when the push button is pressed.
	// char dir = Direction (FALSE = CW = towards motor, TRUE = CCW = away from motor; note orientation is with the bottom of motor facing you)

	enableMotor();
	digitalWrite(A5,dir);									
	//Adjust the direction of rotation of stepper
	delayMicroseconds(10);
	while(!limSwHit){
		performStepping();
	}
	if(limSwHit == YES){
		digitalWrite(A5,!dir);									
		//Adjust the direction of rotation of stepper
		delayMicroseconds(10);
		reverseSteps();
		limSwHit = NO;
		digitalWrite(A2, limSwHit);
		disableMotor();
	}	
}

void reverseSteps(void){

	for(int i=0;i<3;i++){		
	//for loop reverses for 3 mm
		for(int j=0;j<stepsPerMM;j++){
			digitalWrite(A4, HIGH);
			delayMicroseconds(32);			            
			//Affects the speed
			digitalWrite(A4, LOW);
			delayMicroseconds(32);			            
			//Affects the speed
		}
	}
}

void enableMotor(void){
	digitalWrite(A3, LOW);			                            //enable the driver
	delayMicroseconds(10);
}

void disableMotor(void){
	digitalWrite(A3, HIGH);				//disable the driver
	delayMicroseconds(10);	
}

void performStepping(void){
	digitalWrite(A4, HIGH);
	delayMicroseconds(stepperDelay);			            //Affects the speed
	digitalWrite(A4, LOW);
	delayMicroseconds(stepperDelay);			            //Affects the speed
}