/*
 * Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DR . radwa hussein
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_


/*
	Header File includes Registers Address of ATmega32L
*/


/*
	For DDR Registers
*/

#define DDRA *((volatile u8*) 0x3A)
#define DDRB *((volatile u8*) 0x37)
#define DDRC *((volatile u8*) 0x34)
#define DDRD *((volatile u8*) 0x31)

/*
	For PORT Registers

*/

#define PORTA *((volatile u8*) 0x3B)
#define PORTB *((volatile u8*) 0x38)
#define PORTC *((volatile u8*) 0x35)
#define PORTD *((volatile u8*) 0x32)

/*
	For PIN Registers
*/

#define PINA *((volatile u8*) 0x39)
#define PINB *((volatile u8*) 0x36)
#define PINC *((volatile u8*) 0x33)
#define PIND *((volatile u8*) 0x30)



#endif /* REGISTERS_H_ */
