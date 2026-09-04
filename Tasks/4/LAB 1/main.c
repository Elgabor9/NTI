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


int main(void)
{
	DIO_voidInitialization();
	
	LCD_init();
	
	/* Replace with your application code */
	while (1)
	{
		LCD_SendString((u8*)"Ahmed Gaber");
		GoToXY(0,1);
		LCD_voidWriteNumber(-598234);
		GoToXY(0,0);

		
	}
}