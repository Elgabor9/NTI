/*
* GccApplication1.c
*
* Created: 8/31/2026 7:42:41 PM
* Author : ELgabor
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"

#include "KEYPAD_int.h"


int main(void)
{
	DIO_voidInitialization();
	DIO_voidSetPortDirection(DPORTD,OUTPUT);
	KEYPAD_init();
	
	
	/* Replace with your application code */
	while (1)
	{
		
		SevSegment_voidSetValue(KEYPAD_get(),DPORTD,COMMON_CATHODE);
		
	}
}