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

#include "LCD_int.h"

#include "KEYPAD_int.h"

#include "STEPMOTOR_int.h"

#include "INTERRUPT_int.h"

#include "TIMER0_int.h"

#include "TIMER1_int.h"

#include "ADC_int.h"

#include "SPI_int.h"


int main(void)
{
	DIO_voidInitialization();
	SPI_voidInitMaster();
	
	/* Replace with your application code */
	while (1)
	{
		while (1)
		{
			for(u8 i = 0; i < 8; i++)
			{
				DIO_voidSetPinValue(DPORTB, PIN4, LOW);
				_delay_ms(10);
				SPI_u8Transceive(i);
				DIO_voidSetPinValue(DPORTB, PIN4, HIGH);
				_delay_ms(1000);
			}
		}
	}
		
	
}





