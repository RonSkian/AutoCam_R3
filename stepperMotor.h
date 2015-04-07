#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

void updt_stepperInfo(void);
void step(unsigned char dir, unsigned char stepMS, unsigned char stepLS);
// char dir = Direction (TRUE = CW = towards motor, FALSE = CCW = away from motor; note orientation is with the bottom of motor facing you)
// char stepMS = Most significant step value
// char stepLS = Least significant step value
// e.g 1.5 mm, stepMS = 1, stepLS = 5
void performStepping(void);
void reverseSteps(void);
void homeCarriage(unsigned char dir);
void enableMotor(void);
void disableMotor(void);

#endif