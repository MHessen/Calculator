#include "Types.h"
#include "Registers.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#define FstSevSeg_Port 1
#define SecSevSeg_Port 2


void Draw_vidNumber (u8 port_num , u8 num)
{
	switch  (num)
	{
		case 0 :
		{
			DIO_vidSetPortValue ( port_num ,0b10100000 );
			break ;
		}

		case 1 :
		{
			DIO_vidSetPortValue ( port_num ,0b11111001 );
			break ;
		}

		case 2 :
		{
			DIO_vidSetPortValue ( port_num ,0b11000100 );
			break ;
		}

		case 3 :
		{
			DIO_vidSetPortValue ( port_num ,0b11010000 );
			break ;
		}

		case 4 :
		{
			DIO_vidSetPortValue ( port_num ,0b10011001 );
			break ;
		}

		case 5 :
		{
			DIO_vidSetPortValue ( port_num ,0b10010010 );
			break ;
		}

		case 6 :
		{
			DIO_vidSetPortValue ( port_num ,0b10000010 );
			break ;
		}

		case 7 :
		{
			DIO_vidSetPortValue ( port_num ,0b11111000 );
			break ;
		}

		case 8 :
		{
			DIO_vidSetPortValue ( port_num ,0b10000000 );
			break ;
		}

		case 9 :
		{
			DIO_vidSetPortValue ( port_num ,0b10010000 );
			break ;
		}
	}

}

//-----------------------------------------------------------
//Count Down Counter
//-----------------------------------------------------------

void Count_vidDown (u8 stSevSeg_port , u8 ndSevSeg_port , u8 count , u16 tms)
{
	u8  x , y , units , tens ;
	u16 i ;

	units = (count % 10) ;
	tens = (count / 10) ;

	if (count<=9)
	{
		Draw_vidNumber(stSevSeg_port,0);
		for (x=0 ; x<(count+1) ; x++)
		{
			Draw_vidNumber(ndSevSeg_port,x);
			for (i=0 ; i<tms ; i++)
			{
				_delay_ms(1);
			}

		}
	}
	else
	{
		for ( x=0 ; x<tens ; x++ )
		{
			Draw_vidNumber( stSevSeg_port , x );

			if ( tens==(x+1) )
			{
				for (y=0 ; y<10 ; y++)
				{
					Draw_vidNumber( ndSevSeg_port , y );
					for (i=0 ; i<tms ; i++)
					{
						_delay_ms(1);
					}
					if (9 == y )
					{
						Draw_vidNumber( stSevSeg_port , (x+1));
					}
				}
				for (y=0 ; y<(units+1) ; y++)
				{
					Draw_vidNumber( ndSevSeg_port , y );
					for (i=0 ; i<tms ; i++)
					{
						_delay_ms(1);
					}

				}
			}
			else
			{
				for (y=0 ; y<10 ; y++)
				{
					Draw_vidNumber( ndSevSeg_port , y );
					for (i=0 ; i<tms ; i++)
					{
						_delay_ms(1);
					}

				}
			}
		}


	}


}


/*
 * Display a 2 bit Number
 * */

void  Disp_2bitNum (u8 Disp_Num )
{
	/*
	 * FstSevSeg_Port 1
	 * SecSevSeg_Port 2
	 * */

	u8 units , tens ;
	units = Disp_Num %10 ;
	tens = Disp_Num / 10 ;

	Draw_vidNumber(FstSevSeg_Port , tens);				// Displaying the Tens Number in the Lifted Sev.Segment
	Draw_vidNumber(SecSevSeg_Port , units);				// Displaying the Units Number in the Righted Sev.Segment


}
