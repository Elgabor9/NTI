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
	
	DIO_voidSetPinDirection(DPORTA,PIN0,INPUT);
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
	
	
	
	/* Replace with your application code */
	while (1)
	{
		if (ADC_u16Read(0) < (1.5*1024)/5)
		{
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		
		else if((ADC_u16Read(0) >= (1.5*1024)/5) && (ADC_u16Read(0) < (3*1024)/5) )
		{
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN2, LOW);
		}
		else if (ADC_u16Read(0) >= (3*1024)/5)
		{
			DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
		}
	}
	
}



