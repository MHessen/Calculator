/*
 * Keybad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */
#include "Types.h"
#include "Keybad_Config.h"
#include "Registers.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h> // To enable use of the function _delay_ms()


void keybad_Init (void)
{
	DIO_vidSetBitDirction(keybad_port , R0, 0);
	DIO_vidSetBitValue(keybad_port , R0, 1);

	DIO_vidSetBitDirction(keybad_port , R1, 0);
	DIO_vidSetBitValue(keybad_port ,R1, 1);

	DIO_vidSetBitDirction(keybad_port , R2, 0);
	DIO_vidSetBitValue( keybad_port ,  R2, 1);

	DIO_vidSetBitDirction( keybad_port ,  R3, 0);
	DIO_vidSetBitValue( keybad_port ,  R3, 1);

	DIO_vidSetBitDirction(keybad_port , C0 ,1);
	DIO_vidSetBitDirction( keybad_port , C1 ,1);
	DIO_vidSetBitDirction( keybad_port , C2 ,1);
	DIO_vidSetBitDirction( keybad_port , C3 ,1);

}


u8 Keybad_GetButtonStatus (u8 Button_num)
{
	const u8  Real_row [] = {R0,R1,R2,R3};
	const u8  Real_colm [] = {C0,C1,C2,C3};
	u8 read_x , value = 0 ;
	u8 Row = Button_num / 4 ;							//--Selecting the proper Button Row
	u8 Colm = Button_num % 4 ;							//--Selecting the proper Button Column just (0,1,2,3)

	DIO_vidSetBitValue(keybad_port , C0 , 1);
	DIO_vidSetBitValue(keybad_port , C1 , 1);
	DIO_vidSetBitValue(keybad_port , C2 , 1);
	DIO_vidSetBitValue(keybad_port , C3 , 1);

	DIO_vidSetBitValue(keybad_port , Real_colm[Colm] , 0);

	read_x = DIO_u8ReadBitValue(keybad_port , Real_row[Row]);

	if (read_x == 0)
	{
		_delay_ms(20);
		read_x = DIO_u8ReadBitValue(keybad_port , Real_row[Row]);
		if (read_x == 0)
		{value = 1 ;}

	}
	return value ;
}


