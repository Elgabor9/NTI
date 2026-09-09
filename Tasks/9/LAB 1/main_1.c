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
	
	
	
	
	/* Replace with your application code */
	while (1)
	{
		
		for(u32 i=0;i<8;i++)
		{
			UART_voidTransmit(i);
			_delay_ms(1000);
		}
		
	}
	
	
}