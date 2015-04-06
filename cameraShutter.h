#ifndef CAMERASHUTTER_H_
#define CAMERASHUTTER_H_

void takePicture(void);
	// This function allows the camera to perform the shutter actuation
	// NOTE: get the timing right, it just goes apeshit while in start mode.

void camContinuous(unsigned char NOF, unsigned char SSC, unsigned char TBF);
	// This function allows the camera to continously shoot given the parameters set by the user
	// NOF = Number of Frames
	// SSC = Shutter Speed Compensation (measured in seconds)
	// TBF  = Time Between Frames

#endif