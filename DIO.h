/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#ifndef DIO_H_
#define DIO_H_

void DIO_vidSetPortDirction (u8 port_number , u8 value) ;
void DIO_vidSetPortValue (u8 port_number , u8 value) ;
void DIO_vidSetBitDirction (u8 port_number ,u8 pin_number , u8 value);
void DIO_vidSetBitValue (u8 port_number ,u8 pin_number , u8 value);
u8 DIO_u8ReadPortValue (u8 port_number);
u8 DIO_u8ReadBitValue ( u8 port_number , u8 pin_number );

#endif /* DIO_H_ */
