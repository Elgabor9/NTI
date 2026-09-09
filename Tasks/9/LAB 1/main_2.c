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

#include "UART_int.h"


int main(void)
{
	DIO_voidInitialization();
	UART_voidInit();
	
	DIO_voidSetPortDirection(DPORTC,OUTPUT);
	
	
	/* Replace with your application code */
	while (1)
	{
		
		u32 val=UART_u8Receive();
		
		switch(val)
		{
			case 0:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
				break;
			case 1:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
				break;
			case 2:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
				break;
			case 3:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN3,HIGH);
				break;
			case 4:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN4,HIGH);
				break;
			case 5:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN5,HIGH);
				break;
			case 6:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN6,HIGH);
				break;
			case 7:
				DIO_voidSetPortValue(DPORTC,LOW);
				DIO_voidSetPinValue(DPORTC,PIN7,HIGH);
				break;
			
		}
		
	}
	
	
}
