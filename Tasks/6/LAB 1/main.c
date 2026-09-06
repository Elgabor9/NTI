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


int main(void)
{
	DIO_voidInitialization();
	INTERRUPT_init();
	
	DIO_voidSetPinDirection(DPORTD, PIN2, INPUT);
	DIO_voidSetPinDirection(DPORTD, PIN3, INPUT);
	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN1, OUTPUT);
	
	DIO_voidSetPinValue(DPORTD, PIN2, HIGH);
	DIO_voidSetPinValue(DPORTD, PIN3, HIGH);
	
	/* Replace with your application code */
	while (1)
	{
			
	}
	
}

ISR(INT0_vect)
{
	DIO_voidSetPinValue(DPORTC, PIN1, 1-DIO_u8ReadPinValue(DPORTD, PIN2));
}

ISR(INT1_vect)
{
	DIO_voidSetPinValue(DPORTC, PIN0, 1-DIO_u8ReadPinValue(DPORTD, PIN3));
}


