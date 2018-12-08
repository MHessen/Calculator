/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */


#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "LCD_Config.h"
#include "LCD.h"
#include "PubFun.h"
#include "SevnSegm.h"
#include "stdlib.h"
#include "Keybad_Config.h"
#include "Keybad.h"
#define F_CPU 8000000UL
#include <util/delay.h> // To enable use of the function _delay_ms()

int main (void)
{
	u8 i , value , opr , chs_flag ;
	f32 x , y , result ;

	u8 str0 [] = "Welcome";
	u8 str1 [] = "Select Operation";
	u8 str2 [] = "1:ADD";
	u8 str3 [] = "2:Sub";
	u8 str4 [] = "3:Mul";
	u8 str5 [] = "4:Divide";
	u8 str6 [] = "Operand 1: ";
	u8 str7 [] = "Operand 2: ";
	u8 str8 [] = "Result : ";

	LCD_Init();
	keybad_Init();

	LCD_WriteString(str0,sizeof(str0));					// Welcome
	_delay_ms(4000);
	LCD_vidWritecmnd(0b00000001);
	LCD_WriteString(str1,sizeof(str1));					// Select Operation
	_delay_ms(2000);

	while (1)
	{
		LCD_vidWritecmnd(0b00000001);
		LCD_WriteString(str2,sizeof(str2));					// -- 1:ADD
		LCD_SetPosition(0,7);
		LCD_WriteString(str3,sizeof(str3));					// -- 1:ADD 2:Sub
		LCD_SetPosition(1,0);
		LCD_WriteString(str4,sizeof(str4));					// -- 3:Mul
		LCD_SetPosition(1,7);
		LCD_WriteString(str5,sizeof(str5));					// -- 3:Mul 4:Divide

		chs_flag = 0 ;

		while (0 == chs_flag)
		{
			for (i=0 ; i<4 ; i++)
			{//Check Only The Upper Four Buttons For Operations + - * /
				value = Keybad_GetButtonStatus(i);

				if (0==i && 1==value)
				{
					opr=1;
					chs_flag=1;
					value=0;
				}
				else if (1==i && 1==value)
				{
					opr=2;
					chs_flag=1;
					value=0;
				}
				else if (2==i && 1==value)
				{
					opr=3;
					chs_flag=1;
					value=0;
				}
				else if (3==i && 1==value)
				{
					opr=4;
					chs_flag=1;
					value=0;
				}
			}
		}

		LCD_vidWritecmnd(0b00000001);
		LCD_SetPosition(0,0);
		LCD_WriteString(str6 , sizeof(str6));
		_delay_ms(1500);

		while (1 == chs_flag)										// This Scope --- chs_flag=1 , value=0 ,
		{
			for (i=0 ; i<16 ; i++)
			{
				value  = Keybad_GetButtonStatus(i);
				if (1 == value)
				{
					x=i;
					chs_flag=0;
					value=0;
					LCD_SetPosition(0,12);
					LCD_WriteNumber(x);
					_delay_ms(1500);
					break;
				}
			}
		}

		LCD_vidWritecmnd(0b00000001);
		LCD_SetPosition(0,0);
		LCD_WriteString(str7 , sizeof(str7));
		_delay_ms(1500);

		while (0==chs_flag)										// This Scope --- chs_flag=0 , value=0 ,
		{
			for (i=0 ; i<16 ; i++)
			{
				value  = Keybad_GetButtonStatus(i);
				if (1 == value)
				{
					y=i;
					chs_flag=1;
					value=0;
					LCD_SetPosition(0,12);
					LCD_WriteNumber(y);
					_delay_ms(1500);
					break;
				}
			}
		}

		switch (opr)
		{
		case 1:
		{
			result = x + y ;
			break ;
		}
		case 2:
		{
			result = x - y ;
			break ;
		}
		case 3:
		{
			result = x * y ;							// Send the Normal Number then Draw (.) then Send the % number
			break ;
		}
		case 4:
		{
			result = x / y ;
			break ;
		}
		}

		LCD_vidWritecmnd(0b00000001);
		LCD_SetPosition(0,0);
		LCD_WriteString(str8 , sizeof(str8));
		LCD_SetPosition(0,10);
		LCD_WriteNumber(result);
		_delay_ms(3000);

	}

	return 0 ;
}
