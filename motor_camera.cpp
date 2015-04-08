#include <avr/io.h>
#include <Arduino.h>
#include <avr/interrupt.h>
#include "motor_camera.h"
#include "stepperMotor.h"
#include "cameraShutter.h"
#include "globalVariables.h"
#include "misc.h"

#define moduloDivider 10

void mCamContinuous(unsigned char NOFP, unsigned char SSC, unsigned char TBF, unsigned char NOFT, unsigned char DBF, unsigned char dir){
	// This function allows the camera to continously shoot given the parameters set by the user
	// NOFP = Number of Frames Per Position
	// SSC = Shutter Speed Compensation (measured in seconds)
	// TBF = Time Between Frames
	// NOFT = Number of Frames Total
 	// DBF = Distance Between Frames (1mm increments only)
	// dir = Direction (TRUE = CW = towards motor, FALSE = CCW = away from motor; note orientation is with the bottom of motor facing you)
	
	unsigned char cNOFT;
	unsigned char sQ = DBF/moduloDivider;
	//DBF quotient for step function
	unsigned char sR = DBF%moduloDivider;
	//DBF remainder for step function
	while(NOFT != cNOFT){
		camContinuous(NOFP, SSC, TBF);
		delay(10);
		//Minor delay stop any vibrations from affecting the shot prior to movement
		step(dir, sQ, sR);
		disableMotor();
		Serial.print("moved: ");
		Serial.println(DBF);
		delay(1000);
	}
}