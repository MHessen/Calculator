/*
 * PubFun.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

/*
 * Public Functions Needed.
 */
#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_Config.h"
#include "PubFun.h"


void Name_in_Arabic(void)
{
	//-------------------------------------------------------------------------------
	LCD_vidWritecmnd(0b01000000);             // Goto CG-RAM
	//-------------------------------------------------------------------------------
	LCD_vidWriteCharacter(0b00000000);        // ã
	LCD_vidWriteCharacter(0b00000000);        // ã
	LCD_vidWriteCharacter(0b00000000);        // ã
	LCD_vidWriteCharacter(0b00001111);        // ã
	LCD_vidWriteCharacter(0b00001001);        // ã
	LCD_vidWriteCharacter(0b00001001);        // ã
	LCD_vidWriteCharacter(0b00011111);        // ã
	LCD_vidWriteCharacter(0b00000000);        // ã

	LCD_vidWriteCharacter(0b00000000);        // Í
	LCD_vidWriteCharacter(0b00000000);        // Í
	LCD_vidWriteCharacter(0b00001110);        // Í
	LCD_vidWriteCharacter(0b00001001);        // Í
	LCD_vidWriteCharacter(0b00000001);        // Í
	LCD_vidWriteCharacter(0b00000001);        // Í
	LCD_vidWriteCharacter(0b00011111);        // Í
	LCD_vidWriteCharacter(0b00000000);        // Í

	LCD_vidWriteCharacter(0b00000000);        // ã
	LCD_vidWriteCharacter(0b00000000);        // ã
	LCD_vidWriteCharacter(0b00000000);        // ã
	LCD_vidWriteCharacter(0b00001111);        // ã
	LCD_vidWriteCharacter(0b00001001);        // ã
	LCD_vidWriteCharacter(0b00001001);        // ã
	LCD_vidWriteCharacter(0b00011111);        // ã
	LCD_vidWriteCharacter(0b00000000);        // ã

	LCD_vidWriteCharacter(0b00000000);        // Ï
	LCD_vidWriteCharacter(0b00000000);        // Ï
	LCD_vidWriteCharacter(0b00000000);        // Ï
	LCD_vidWriteCharacter(0b00000001);        // Ï
	LCD_vidWriteCharacter(0b00000001);        // Ï
	LCD_vidWriteCharacter(0b00000001);        // Ï
	LCD_vidWriteCharacter(0b00001111);        // Ï
	LCD_vidWriteCharacter(0b00000000);        // Ï
	//------------------------------------------------------------------------------
	LCD_SetPosition(0,0);                     // Go Back to DD-RAM
	//--------------------------------------------------------------------------
	/*
	 * Displaying my name "ãÍãÏ" in Arabic
	 * */
	/*
		LCD_vidWriteCharacter(3);                 // Print Address 3 which specified for CG-RAM
		LCD_vidWriteCharacter(2);                 // Print Address 2 which specified for CG-RAM
		LCD_vidWriteCharacter(1);                 // Print Address 1 which specified for CG-RAM
		LCD_vidWriteCharacter(0);                 // Print Address 0 which specified for CG-RAM
	 */
	/*
	 * END
	 * */
	//-----------------------------------------------------------------------------

}
