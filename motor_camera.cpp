#include <avr/io.h>
#include <Arduino.h>
#include <avr/interrupt.h>
#include "motor_camera.h"
#include "stepperMotor.h"
#include "cameraShutter.h"
#include "globalVariables.h"
#include "misc.h"

void mCamContinuous(unsigned char NOFP, unsigned char SSC, unsigned char TBF, unsigned char NOFT, unsigned char DBF, unsigned char dir, unsigned char stepMS, unsigned char stepLS){
	unsigned char cNOFT;
	while(cNOFT != NOFT){
		camContinuous(NOFP, SSC, TBF);
		step(dir, stepMS, stepLS);
		delay(10);
	}
}
