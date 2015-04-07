#ifndef MOTOR_CAMERA_H_
#define MOTOR_CAMERA_H_

void mCamContinuous(unsigned char NOF, unsigned char SSC, unsigned char TBF);
	// This function allows the camera to continously shoot given the parameters set by the user
	// NOF = Number of Frames
	// SSC = Shutter Speed Compensation (measured in seconds)
	// TBF  = Time Between Frames


#endif
