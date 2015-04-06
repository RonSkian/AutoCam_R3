#include <avr/io.h>
#include <Arduino.h>
#include <avr/interrupt.h>
#include "globalVariables.h"
#include "initialization.h"
#include "stepperMotor.h"
//#include "fonts.h"

 void timerCompare0_ini(void){								  // -Initialization of the Timer Compare 0
	TCCR0A  = 0;                                       	      // This regulates the menu navigation arrow to show where user is pointing                      
	TCCR0B  = 0;                                                              
	TCNT0   = 0;                                       
	OCR0A   = 256;                                     	      // -compare match register ((16MHz/64/200Hz)-1)
	TCCR0A |= (1 << WGM01);                                   // -CTC mode
	TCCR0B |= ((1 << CS02) | (1 << CS00));                    // -1024 prescaler
	TIMSK0 |= (1 << OCIE0A);                                  // -Enable timer compare interrupt
}
 
void timerCompare1_ini(void){                                 // -Initialization of the Timer Compare 1 
	TCCR1A  = 0;                                              // -Timer compare 1 A ISR, this regulates the shooting activity
	TCCR1B  = 0;
	TCCR1C  = 0;               								  // Clear TCCR1C	
	TCNT1   = 0;
	OCR1A   = 15624;                                          // -compare match register ((16MHz/1024/1Hz) - 1)
	TCCR1B |= (1 << WGM12);                                   // -CTC mode
	TCCR1B |= ((1 << CS12) | (1 << CS10));                    // -1024 prescaler
	TIMSK1 |= (1 << OCIE1A);                                  // -Enable timer compare interrupt
}

void timerCompare2_ini(void){                                 // -Initialization of the Timer Compare 1 
	TCCR2A  = 0;                                              // -Timer compare 1 A ISR, this regulates the rotary encoder refresh rate
	TCCR2B  = 0;                                	                               
	TCNT2   = 0;                                                              
	OCR2A   = 124;                                            // -compare match register ((16MHz/1024/500Hz) - 1)
	TCCR2A |= (1 << WGM21);                                   // -CTC mode
	TCCR2B |= (1 << CS22) | (1 << CS21);   					  // -256 prescaler
	TIMSK2 |= (1 << OCIE2A);                                  // -Enable timer compare interrupt 2 A
}

void int0_ini(void){                                          // -Initialize INT0 external interrupt
                                                              // -External interrupt for the push button on pin 2 which                                  
                                                              // determines which level and submenus the user is currently on
	EIMSK  |= (1<<INT0);                                      // -Enable INT0 for pin 2 
	EICRA  |= (1<<ISC01) | (1<<ISC00);                        // -ISC01 = 1, ISC00 = 1, Interrupt on rising edge
}

void int1_ini(void){                                          // -Initialize INT1 external interrupt
                                                              // -External interrupt for the two end stops/ limit switches                                
                                                              // that determines whether the camera carriage has reached the end
	EIMSK  |= (1<<INT1);                                      // -Enable INT1 for pin 3
	EICRA  |= (1<<ISC11) | (1<<ISC10);                        // -ISC11 = 1, ISC10 = 1, Interrupt on rising edge
}

void pinSetup(void){
	pinMode(focusCamera, OUTPUT);
	pinMode(releaseShutter, OUTPUT);
	pinMode(pushButton, INPUT);
	pinMode(pin_A, INPUT);
	pinMode(pin_B, INPUT);
	pinMode(A5, OUTPUT);		                              //Direction
	pinMode(A4, OUTPUT);		                              //Steps
	pinMode(A3, OUTPUT);		                              //Sleep (ALOW)
	pinMode(A2, OUTPUT);
}

//void LCD_ini(void){  
//	unsigned char counter = 0;
//	lcd.begin(16, 2);                                         // -set up the LCD's number of columns and rows:
//	lcd.setCursor(5, 0);
//	lcd.write(byte(3));
//	lcd.write(byte(0));
//	lcd.print(".");
//	lcd.write(byte(1));
//	lcd.write(byte(0));
//	lcd.write(byte(2));
//	lcd.setCursor(6, 1);
//	lcd.write(byte(5));
//	lcd.write(byte(6));
//	lcd.print(".");
//	lcd.write(byte(7));
//	
//	for(int i = 0; i < 10; i++){
//		if(counter == 0){
//			lcd.setCursor(5, 0);
//			lcd.write(byte(4));
//			counter = 1;
//		}
//		else{
//			lcd.setCursor(5, 0);
//			lcd.write(byte(3));
//			counter = 0;
//		}
//		delay(25000);
//	}
//}

void stepperMTR_ini(void){
	digitalWrite(A3, HIGH);		                              //disable the driver
	delayMicroseconds(10);
}

