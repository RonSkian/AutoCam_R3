//#include <LiquidCrystal.h>
#include "globalVariables.h"

volatile unsigned char currML0 = 0;	// Current menu level 0
volatile unsigned char currML1 = notDefined;	// Current menu level 1
volatile unsigned char currML2 = notDefined;	// Current menu level 2
volatile unsigned char currML3 = notDefined;	// Current menu level 3
volatile unsigned char currML4 = notDefined;	// Current menu level 4
volatile unsigned char currCRF = NO;


volatile unsigned char ML0prev = notDefined;
volatile unsigned char ML1prev = notDefined;
volatile unsigned char ML2prev = notDefined;
volatile unsigned char ML3prev = notDefined;
volatile unsigned char ML4prev = notDefined;

volatile int stepperDelay; 
volatile float stepperSpeed;
volatile int SSLeastSig;
volatile int SSMostSig;
volatile unsigned int stepperDistance;		//Desired distance for stepper to move with relation to leadscrew
volatile unsigned char stepperDistanceMS;
volatile unsigned char stepperDistanceLS;
volatile unsigned char limSwHit;

volatile unsigned int CM_DistDiv = 1;		//This should be the distance division where you move 1 mm every cycle.
volatile unsigned int CM_DistDivMS;
volatile unsigned int CM_DistDivLS;
volatile unsigned int CM_ShotPerDiv = 1;
volatile unsigned int CM_DistCov = 0;
volatile unsigned int CSS_shutterStart = NO;
volatile unsigned int CSS_shutterNotDone = YES;

volatile unsigned int cSec = 0;

volatile unsigned char contShutterInterval;
volatile char contHr;
volatile char contMin;
volatile char contSec = 5;

volatile char stiHr;
volatile char stiMin;
volatile char stiSec;

volatile char currHr;
volatile char currMin;
volatile char currSec;

volatile char test;

// volatile char stiHr_curr;
// volatile char stiMin_curr;
// volatile char stiSec_curr;

// volatile char stiTimeLeftHr;
// volatile char stiTimeLeftMin;
// volatile char stiTimeLeftSec;

//LiquidCrystal lcd(LCDRS, LCDEnable, LCDDR4, LCDDR5, LCDDR6, LCDDR7);

