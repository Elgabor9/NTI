/*******************************************/
/*********** Author: Elgabor ***************/
/*********** Date : 01/09/2026 *************/
/*******************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidInitialization(void)
{

	DDRA = DIO_PORTA_DIRECTION;
	DDRB = DIO_PORTB_DIRECTION;
	DDRC = DIO_PORTC_DIRECTION;
	DDRD = DIO_PORTD_DIRECTION;
	
}

void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
	if(PortID<4)
	{

		if(Direction == OUTPUT)
		{
			switch(PortID)
				{
					case DPORTA: Set_Bit(DDRA, PinID); break;
					case DPORTB: Set_Bit(DDRB, PinID); break;
					case DPORTC: Set_Bit(DDRC, PinID); break;
					case DPORTD: Set_Bit(DDRD, PinID); break;
				}
		}
		else if(Direction == INPUT)
		{
			switch(PortID)
				{
					case DPORTA: Clear_Bit(DDRA, PinID); break;
					case DPORTB: Clear_Bit(DDRB, PinID); break;
					case DPORTC: Clear_Bit(DDRC, PinID); break;
					case DPORTD: Clear_Bit(DDRD, PinID); break;
				}
		}
		else{}
	}
	else{}

}





/**Output Mode*/

void  DIO_viodSetPinValue(u8 PortID, u8 PinID, u8 Value)
{
	if(PortID<4 && PinID<8)
	{

		if(Value == HIGH)
		{
			switch(PortID)
				{
					case DPORTA: Set_Bit(PORTA, PinID); break;
					case DPORTB: Set_Bit(PORTB, PinID); break;
					case DPORTC: Set_Bit(PORTC, PinID); break;
					case DPORTD: Set_Bit(PORTD, PinID); break;
				}
		}
		else if(Value == LOW)
		{
			switch(PortID)
				{
					case DPORTA: Clear_Bit(PORTA, PinID); break;
					case DPORTB: Clear_Bit(PORTB, PinID); break;
					case DPORTC: Clear_Bit(PORTC, PinID); break;
					case DPORTD: Clear_Bit(PORTD, PinID); break;
				}
		}
		else{}
	}
	else{}
	
}


u8 DIO_u8ReadPinValue(u8 PortID, u8 PinID)
{
	u8 val=10;

	if(PortID<4 && PinID<8)
	{

		switch(PortID)
			{
				case DPORTA: val = Get_Bit(PORTA, PinID); break;
				case DPORTB: val = Get_Bit(PORTB, PinID); break;
				case DPORTC: val = Get_Bit(PORTC, PinID); break;
				case DPORTD: val = Get_Bit(PORTD, PinID); break;
			}
	}
	else{}

	return val;

}

void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{

	if(PortID<4)
	{

		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
			case DPORTA: for(u8 i=0;i<8;i++) Set_Bit(DDRA, i) ; break;
			case DPORTB: for(u8 i=0;i<8;i++) Set_Bit(DDRB, i) ; break;
			case DPORTC: for(u8 i=0;i<8;i++) Set_Bit(DDRC, i) ; break;
			case DPORTD: for(u8 i=0;i<8;i++) Set_Bit(DDRD, i) ; break;
			}
		}
		else if(Direction == INPUT)
		{
			switch(PortID)
			{
			case DPORTA: for(u8 i=0;i<8;i++) Clear_Bit(DDRA, i) ; break;
			case DPORTB: for(u8 i=0;i<8;i++) Clear_Bit(DDRB, i) ; break;
			case DPORTC: for(u8 i=0;i<8;i++) Clear_Bit(DDRC, i) ; break;
			case DPORTD: for(u8 i=0;i<8;i++) Clear_Bit(DDRD, i) ; break;
			}
		}
		else{}
	}
	else{}

}

void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
    if(PortID < 4)
    {
        switch(PortID)
        {
            case DPORTA: PORTA = Value; break;
            case DPORTB: PORTB = Value; break;
            case DPORTC: PORTC = Value; break;
            case DPORTD: PORTD = Value; break;
        }
    }
}

u8 DIO_u8ReadPortValue(u8 PortID)
{
    u8 val = 0;

    if(PortID < 4)
    {
        switch(PortID)
        {
            case DPORTA: val = PINA; break;
            case DPORTB: val = PINB; break;
            case DPORTC: val = PINC; break;
            case DPORTD: val = PIND; break;
        }
    }
    return val;

}