#ifndef MOTOR_CAMERA_H_
#define MOTOR_CAMERA_H_

void mCamContinuous(unsigned char NOFP, unsigned char SSC, unsigned char TBF, unsigned char NOFT, unsigned char DBF, unsigned char dir);
	// This function allows the camera to continously shoot given the parameters set by the user
	// NOFP = Number of Frames Per Position
	// SSC = Shutter Speed Compensation (measured in seconds)
	// TBF = Time Between Frames
	// NOFT = Number of Frames Total
	// DBF = Distance Between Frames (1mm increments only)
	// dir = Direction (TRUE = CW = towards motor, FALSE = CCW = away from motor; note orientation is with the bottom of motor facing you)

#endif
