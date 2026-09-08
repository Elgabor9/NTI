/*
* GccApplication1.c
*
* Created: 8/31/2026 7:42:41 PM
* Author : ELgabor
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"

#include "KEYPAD_int.h"

#include "STEPMOTOR_int.h"

#include "INTERRUPT_int.h"

#include "TIMER0_int.h"


int main(void)
{
	DIO_voidInitialization();
	TIMER0_voidInit();
	
	DIO_voidSetPinDirection(DPORTD, PIN4, OUTPUT);
	
	
	
	
	/* Replace with your application code */
	while (1)
	{
		
		DIO_voidSetPinValue(DPORTD,PIN4,HIGH);
		TIMER0_voidDelay1Sec();
		DIO_voidSetPinValue(DPORTD,PIN4,LOW);
		TIMER0_voidDelay1Sec();
		
	}
		
	
}



