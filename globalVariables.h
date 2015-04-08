#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

//#include <LiquidCrystal.h>

//Human Interface pins begin
#define pin_A 6
#define pin_B 7
#define pushButton 2 //Interrupt enabled pin (both 2 and 3)
#define limitSwitches 3 //Interrupt enabled pin (both 2 and 3)
#define focusCamera 9		//red wire
#define releaseShutter 10		//green wire
//Human Interface pins end

#define oneClick 1
#define twoClick 2
#define NO 0
#define YES 1
#define notDefined 99

//LCD Define begin
#define LCDRS 4
#define LCDEnable 5
#define LCDDR4 8
#define LCDDR5 11
#define LCDDR6 12
#define LCDDR7 13
//LCD Define end

enum direction{
	neutral,
	positive,
	negative
};

enum currentHMSModifier{
  hour,
  minute,
  second
};

enum booleanStatements{
  FALSE,
  TRUE
};

enum menu {
  continuous, 
  setTimeOfDay,
  settings
};

enum continuousSubMenu{
  startCont,
  setTimeIntervalCont
};

enum setTimeSubMenu{
  startSetTime,
  setTimer,
  setTimeIntervalSetTime
};

enum settingsSubMenu{
  SDTimeInterval,
  SDTimer,
  adjustBrightness
};

extern volatile unsigned char currML0;	// Current menu level 0
extern volatile unsigned char currML1;	// Current menu level 1
extern volatile unsigned char currML2;	// Current menu level 2
extern volatile unsigned char currML3;	// Current menu level 3
extern volatile unsigned char currML4;	// Current menu level 4
extern volatile unsigned char currCRF;	// Current constant refresh status

extern volatile unsigned char ML0prev;
extern volatile unsigned char ML1prev;
extern volatile unsigned char ML2prev;
extern volatile unsigned char ML3prev;
extern volatile unsigned char ML4prev;

extern volatile int stepperDelay; 
extern volatile float stepperSpeed;
extern volatile int SSLeastSig;
extern volatile int SSMostSig;
extern volatile unsigned int stepperDistance;
extern volatile unsigned char stepperDistanceMS;
extern volatile unsigned char stepperDistanceLS;
extern volatile unsigned char limSwHit;

extern volatile unsigned int CM_DistDiv;		//note: MAX: 500mm DEFAULT: 1mm
extern volatile unsigned int CM_DistDivMS;
extern volatile unsigned int CM_DistDivLS;
extern volatile unsigned int CM_ShotPerDiv;		//note: MAX: 999shots DEFAULT: 1 S/DIV
extern volatile unsigned int CM_DistCov;		//note: MAX: 999mm DEFAULT: 0, therefore it will move until it hits limit switch
extern volatile unsigned int CSS_shutterStart;
extern volatile unsigned int CSS_shutterNotDone;

extern volatile unsigned int cSec;		//current seconds, used to keep track of the seconds that have past in Timer2 Comp A

//extern volatile unsigned char contShutterInterval;
//extern volatile char contHr;		//linked with cont+mtr mode
//extern volatile char contMin;		//linked with cont+mtr mode
//extern volatile char contSec;		//linked with cont+mtr mode
//
//extern volatile char stiHr;
//extern volatile char stiMin;
//extern volatile char stiSec;
//
//extern volatile char currHr;
//extern volatile char currMin;
//extern volatile char currSec;
//
//extern volatile char test;

// extern volatile char stiHr_curr;
// extern volatile char stiMin_curr;
// extern volatile char stiSec_curr;

// extern volatile char stiTimeLeftHr;
// extern volatile char stiTimeLeftMin;
// extern volatile char stiTimeLeftSec;

//extern LiquidCrystal lcd;

#endif
