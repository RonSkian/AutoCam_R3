#include <avr/io.h>
#include <Arduino.h>
#include <avr/interrupt.h>
#include "globalVariables.h"
#include "cameraShutter.h"
#include "misc.h"


void takePicture(void){
	// This function allows the camera to perform the shutter actuation
	// NOTE: get the timing right, it just goes apeshit while in start mode.
	digitalWrite(focusCamera, HIGH);                                    
	digitalWrite(releaseShutter, HIGH);		
	//digitalWrite(A2, HIGH);
	delay(50);
	digitalWrite(focusCamera, LOW);
	digitalWrite(releaseShutter, LOW);
	//digitalWrite(A2, LOW);
	delay(10);
	Serial.println("Picture taken");
}


void camContinuous(unsigned char NOF, unsigned char SSC, unsigned char TBF){
	// This function allows the camera to continously shoot given the parameters set by the user
	// NOF = Number of Frames
	// SSC = Shutter Speed Compensation (measured in seconds)
	// TBF  = Time Between Frames

	unsigned char cF;
	//cF = current frame

	delay(50);
	//Delay just a moment so the person is well away from the controls that might cause vibration to the camera
	takePicture();
	delaySeconds_ini();
	cF++;
	Serial.println("first picture ^^");
	while(NOF != cF){
		//Serial.println(cSec);
		//Serial.println(SSC);
		if(delaySeconds_chk(SSC)){
			takePicture();
			if(NOF >= cF){
				delaySeconds_ini();
				cF++;
			}
			else{
				break;
			}
		}
	}
}
