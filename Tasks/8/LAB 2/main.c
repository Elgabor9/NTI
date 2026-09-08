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
	INTERRUPT_init();
	ADC_voidInit();
	
	DIO_voidSetPinDirection(DPORTD, PIN4, OUTPUT);
	
	
	
	
	/* Replace with your application code */
	while (1)
	{
		
		TIMER0_voidSetCompare(ADC_u16Read(PIN0)/4);
		
	}
		
	
}

ISR(TIMER0_COMP_vect)
{
	
	static u8 state = LOW;
	
	if (state == LOW) state = HIGH;
	else state = LOW;
	
	DIO_voidSetPinValue(DPORTD, PIN4, state);
}



