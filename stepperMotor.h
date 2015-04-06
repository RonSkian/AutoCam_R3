#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_


void updt_stepperInfo(void);
void step(unsigned char dir, unsigned char stepMS, unsigned char stepLS);
void performStepping(void);
void reverseSteps(void);
void homeCarriage(unsigned char dir);
void enableMotor(void);
void disableMotor(void);

#endif