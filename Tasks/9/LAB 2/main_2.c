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

#include "SPI_int.h"


int main(void)
{
    DIO_voidInitialization();
    SPI_voidInitSlave();
    
    DIO_voidSetPortDirection(DPORTC, OUTPUT);
    DIO_voidSetPortValue(DPORTC, LOW);
    
    while (1)
    {
        
        u8 val = SPI_u8Transceive(0xFF);
        
        if (val >= 0 && val <= 7)
        {
            if (DIO_u8ReadPinValue(DPORTC, val) == HIGH)
            {
                DIO_voidSetPinValue(DPORTC, val, LOW);
            }
            else
            {
                DIO_voidSetPinValue(DPORTC, val, HIGH);
            }
        }
    }
}