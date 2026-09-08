#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "TIMER1_int.h"
#include "TIMER1_config.h"
#include "TIMER1_private.h"

void TIMER1_voidInitServo(void)
{

    Clear_Bit(TCCR1A, 0);
    Set_Bit(TCCR1A, 1);
    Set_Bit(TCCR1B, 3);
    Set_Bit(TCCR1B, 4);

    Clear_Bit(TCCR1A, 6);
    Set_Bit(TCCR1A, 7);

    ICR1 = 19999;

    Clear_Bit(TCCR1B, 0);
    Set_Bit(TCCR1B, 1);
    Clear_Bit(TCCR1B, 2);
}

void TIMER1_voidSetServoAngle(u8 Angle)
{
    // protection
    if (Angle > 180)
    {
        Angle = 180;
    }

    OCR1A = 1000 + (((u32)Angle * 1000) / 180);
}