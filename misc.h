#ifndef MISC_H_
#define MISC_H_

void delaySeconds_ini(void);
//Initiates timerCompare1 so it can increment cSec at 1 Hz
int delaySeconds_chk(unsigned int dV);
//Checks the the current time in seconds (cSec) after being initiated by delaySeconds_ini();

#endif
