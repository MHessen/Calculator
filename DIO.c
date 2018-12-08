/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */


#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define ClrBit(Register,Pin) Register&=(~(1<<Pin))

/*
------------------------------DIO DDR Registers--------------------------------
*/

void DIO_vidSetPortDirction (u8 port_number , u8 value)  // 1 :  Output & 0 : Input
{
	switch (port_number)
	{
		case 0:
			DDRA = value ;
			break ;
		case 1 :
			DDRB = value ;
			break ;
		case 2 :
			DDRC = value ;
			break ;
		case 3 :
			DDRD = value ;
			break ;
	}


}

void DIO_vidSetBitDirction (u8 port_number ,u8 pin_number , u8 value)
{
	switch (port_number)
	{
	case 0 :
		{
			if (1==value)
			SetBit (DDRA,pin_number) ;
		else if (0==value)
			ClrBit (DDRA,pin_number);
		}
		break ;

	case 1 :
			{
				if (1==value)
				SetBit (DDRB,pin_number) ;
			else if (0==value)
				ClrBit (DDRB,pin_number);
			}
			break ;
	case 2 :
			{
				if (1==value)
				SetBit (DDRC,pin_number) ;
			else if (0==value)
				ClrBit (DDRC,pin_number);
			}
			break ;
	case 3 :
			{
				if (1==value)
				SetBit (DDRD,pin_number) ;
			else if (0==value)
				ClrBit (DDRD,pin_number);
			}
			break ;
	}
}

/*
------------------------------DIO PORT Registers------------------------------------------
*/
void DIO_vidSetPortValue (u8 port_number , u8 value)
{
	switch (port_number)
		{
			case 0:
				PORTA = value ;
				break ;
			case 1 :
				PORTB = value ;
				break ;
			case 2:
				PORTC = value ;
				break ;
			case 3:
				PORTD = value ;
				break ;
		}
}


void DIO_vidSetBitValue (u8 port_number ,u8 pin_number , u8 value)
{
	switch (port_number)
		{
		case 0 :
			{
				if (1==value)
				SetBit (PORTA,pin_number) ;
			else if (0==value)
				ClrBit (PORTA,pin_number);
			}
			break ;

		case 1 :
				{
					if (1==value)
					SetBit (PORTB,pin_number) ;
				else if (0==value)
					ClrBit (PORTB,pin_number);
				}
				break ;
		case 2 :
				{
					if (1==value)
					SetBit (PORTC,pin_number) ;
				else if (0==value)
					ClrBit (PORTC,pin_number);
				}
				break ;
		case 3 :
				{
					if (1==value)
					SetBit (PORTD,pin_number) ;
				else if (0==value)
					ClrBit (PORTD,pin_number);
				}
				break ;
		}


}


/*
 -------------------------------DIO PIN Registers-------------------------------------
 */

u8 DIO_u8ReadPortValue (u8 port_number)
{
	u8 value ;

	switch(port_number)
	{

		case 0:
			value = PINA ;
			break ;
		case 1:
			value = PINB ;
			break ;
		case 2:
			value = PINC ;
		   break ;
		case 3:
			value = PIND ;
			break ;
	}

	return value ;
}

// Read a specified Pin value

u8 DIO_u8ReadBitValue ( u8 port_number , u8 pin_number )
{
	u8 x , res ;

	switch (port_number)
	{
		case 0:
		{
			x = PINA & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break ;

		case 1 :
		{
			x = PINB & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break;

		case 2 :
		{
			x = PINC & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break ;

		case 3:
		{
			x = PIND & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break ;
	}

	return res ;

}
