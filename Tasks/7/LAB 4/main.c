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
	ADC_voidInit();
	
	//DIO_voidSetPinDirection(DPORTA,PIN0,INPUT);
	DIO_voidSetPinDirection(DPORTD,PIN3,OUTPUT);
	
	
	
	/* Replace with your application code */
	while (1)
	{
		if (ADC_u16Read(0) < 300)
		{
			DIO_voidSetPinValue(DPORTD, PIN3, HIGH);
		}
		else
		{
			DIO_voidSetPinValue(DPORTD, PIN3, LOW);
		}
	}
		
	
}



