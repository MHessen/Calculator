/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_vidWritecmnd(u8 character);
void LCD_vidWritecmnd(u8 cmnd);
void LCD_Init(void);
void LCD_WriteNumber (f64 num);
void LCD_WriteString(u8 str [],int count);
void LCD_SetPosition (u8 row , u8 colm);

#endif /* LCD_H_ */

