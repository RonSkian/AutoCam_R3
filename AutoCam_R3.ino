/* Notes
- Coded by Ronnie Kwan - Febuary 20th, 2014
- Uniformly we will use pull-down resistors

//DONE:
 Put the LCD to refresh on the timer compare B interrupt every at 60Hz // Not possible, the routine takes too long
 Double click to go back on the menu // Done
 Activate shooting in continuous mode // Done
 Be able to modify the time interval // Done
 Make sure camera gets out of sleep mode just before the shot // Done

 //TODO:
- Free shot Mode
- Set Total Time Modeee
- Time of Day Mode
- Bounded Time Mode
- External Trigger Mode?
- Settings menu
- Build robust lcd writing method that doesn't hard code the position of numbers
- Create custom characters
- Save previous values into EEPROM, see if possible first...
*/

//#include <LiquidCrystal.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "globalVariables.h"
//#include "menu.h"
//#include "rotaryEncoder.h"
#include "cameraShutter.h"
#include "misc.h"
#include "initialization.h"
//#include "fonts.h"
#include "stepperMotor.h"
//#include "contShttrStppr.h"

int incomingByte = 0;


void setup() {
	noInterrupts();
	pinSetup();
	stepperMTR_ini();
	stepperSpeed = 1;		//stepper manual speed = 2.5mm/s, max seems to be 3.2 mm/s with low vibrations, remember to put it in 1/16th steps
	stepperDistance = 10;	//stepper manual distance = 10mm
	limSwHit = NO;
	updt_stepperInfo();
	Serial.begin(9600);
	
	//lcd.createChar(0, A);
	//lcd.createChar(1, C);
	//lcd.createChar(2, M);
	//lcd.createChar(3, cameraShot_noFlash);
	//lcd.createChar(4, cameraShot_flash);
	//lcd.createChar(5, V);
	//lcd.createChar(6, num1);
	//lcd.createChar(7, num0);

	//LCD_ini();                                       // -set up the LCD's number of columns and rows
	//timerCompare0_ini();
	timerCompare1_ini();
	//timerCompare2_ini();
	//int0_ini();
	int1_ini();									// Start the external interrupt for the limit switches
	//TIMSK1 &= (0 << OCIE1A);

	//lcd.clear();
	interrupts();                                                             
}
 
ISR(TIMER1_COMPA_vect){                         // -Timer compare 1 A ISR, this regulates the shooting activity
	noInterrupts();
	// beginCameraShots();
	cSec++;
	interrupts();
}
                                                    
ISR(TIMER2_COMPA_vect){                         // -Timer compare 2 A ISR, this regulates the shooting activity
	noInterrupts();                             // -disable all interrupts
	interrupts();
	//updt_currLocation_rotaryTurn(); 
	//updt_contShutterInterval();
	updt_stepperInfo();
	interrupts();
}

ISR(INT0_vect){                                 // -External interrupt for the push button on pin 2 which
	noInterrupts();                             // determines which level and submenus the user is currently on
	//if((currML0 == 1 && currML1 == 0 && currML2 == 0 && currML3 == 0) ||
	//(currML0 == 1 && currML1 == 0 && currML2 == 1 && currML3 == 0)||
	//(currML0 == 1 && currML1 == 1 && currML2 == 0 && currML3 == 0)||
	//(currML0 == 1 && currML1 == 1 && currML2 == 1 && currML3 == 0)){
	//	limSwHit = YES;
	//	digitalWrite(A2, limSwHit);
	//}
	//else{
		//updt_currLocation_click();
	//}
	//EIFR |= (1<<INTF0);							// Clear the flag to make the double click work, in the case 
												// that you click while you're in the interrupt. ATMega328 
												// seems to remember it until it is allowed to interrupt again.
	interrupts();
}

ISR(INT1_vect){                                 // -External interrupt for the limitswitch on pin 2 which
	noInterrupts();                             // determines which level and submenus the user is currently on
	limSwHit = YES;
	digitalWrite(A2, limSwHit);
	EIFR |= (1<<INTF1);							// Clear the flag to make the double click work, in the case 
												// that you click while you're in the interrupt. ATMega328 
												// seems to remember it until it is allowed to interrupt again.
	interrupts();
}

void loop()  {                                  // -Menu navigation being is displayed on the LCD in this loop                                                                           
	//displayCurrentMenu(currML0, currML1, currML2, currML3, currML4, currCRF);
	// lcd.setCursor(0, 0);
	// lcd.print(cSec, DEC);
	//CSSProc();

	//takePicture();
	camContinuous(10, 3, 5);
	delay(10000);
}

