/*
 * ATmega32_Registers.h
 *
 *  Created on: Dec 30, 2022
 *      Author: Esraa Abdelnaby
 */

#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_


typedef union
{
	struct {
		u8 Bit0 : 1 ;
		u8 Bit1 : 1 ;
		u8 Bit2 : 1 ;
		u8 Bit3 : 1 ;
		u8 Bit4 : 1 ;
		u8 Bit5 : 1 ;
		u8 Bit6 : 1 ;
		u8 Bit7 : 1 ;
	}Bits;
	u8 Byte;
}tenuRegType;

/*                           Atmega32 Registers  								*/

#define _SREG 	(*((volatile tenuRegType*) 0x5F) )
#define _SPH 	(*((volatile tenuRegType*) 0x5E) )
#define _SPL 	(*((volatile tenuRegType*) 0x5D) )
#define _OCR0 	(*((volatile tenuRegType*) 0x5C) )
#define _GICR 	(*((volatile tenuRegType*) 0x5B) )
#define _GIFR 	(*((volatile tenuRegType*) 0x5A) )
#define _TIMSK 	(*((volatile tenuRegType*) 0x59) )
#define _TIFR 	(*((volatile tenuRegType*) 0x58) )
#define _SPMCR 	(*((volatile tenuRegType*) 0x57) )
#define _TWCR 	(*((volatile tenuRegType*) 0x56) )
#define _MCUCR 	(*((volatile tenuRegType*) 0x55) )
#define _MCUCSR (*((volatile tenuRegType*) 0x54) )
#define _TCCR0 	(*((volatile tenuRegType*) 0x53) )
#define _TCNT0 	(*((volatile tenuRegType*) 0x52) )
#define _OSCCAL (*((volatile tenuRegType*) 0x51) )
#define _OCDR 	(*((volatile tenuRegType*) 0x51) )
#define _SFIOR 	(*((volatile tenuRegType*) 0x50) )
#define _TCCR1A (*((volatile tenuRegType*) 0x4F) )
#define _TCCR1B (*((volatile tenuRegType*) 0x4E) )
#define _TCNT1H (*((volatile tenuRegType*) 0x4D) )
#define _TCNT1L (*((volatile tenuRegType*) 0x4C) )
#define _OCR1AH (*((volatile tenuRegType*) 0x4B) )
#define _OCR1AL (*((volatile tenuRegType*) 0x4A) )
#define _OCR1BH (*((volatile tenuRegType*) 0x49) )
#define _OCR1BL (*((volatile tenuRegType*) 0x48) )
#define _ICR1H 	(*((volatile tenuRegType*) 0x47) )
#define _ICR1L 	(*((volatile tenuRegType*) 0x46) )
#define _TCCR2 	(*((volatile tenuRegType*) 0x45) )
#define _TCNT2 	(*((volatile tenuRegType*) 0x44) )
#define _OCR2 	(*((volatile tenuRegType*) 0x43) )
#define _ASSR 	(*((volatile tenuRegType*) 0x42) )
#define _WDTCR 	(*((volatile tenuRegType*) 0x41) )
#define _UBRRH 	(*((volatile tenuRegType*) 0x40) )
#define _UCSRC 	(*((volatile tenuRegType*) 0x40) )
#define _EEARH 	(*((volatile tenuRegType*) 0x3F) )
#define _EEARL 	(*((volatile tenuRegType*) 0x3E) )
#define _EEDR 	(*((volatile tenuRegType*) 0x3D) )
#define _EECR 	(*((volatile tenuRegType*) 0x3C) )
#define PORTA 	(*((volatile tenuRegType*) 0x3B) )
#define DDRA 	(*((volatile tenuRegType*) 0x3A) )
#define PINA 	(*((volatile tenuRegType*) 0x39) )
#define PORTB 	(*((volatile tenuRegType*) 0x38) )
#define DDRB 	(*((volatile tenuRegType*) 0x37) )
#define PINB 	(*((volatile tenuRegType*) 0x36) )
#define PORTC 	(*((volatile tenuRegType*) 0x35) )
#define DDRC 	(*((volatile tenuRegType*) 0x34) )
#define PINC 	(*((volatile tenuRegType*) 0x33) )
#define PORTD 	(*((volatile tenuRegType*) 0x32) )
#define DDRD 	(*((volatile tenuRegType*) 0x31) )
#define PIND 	(*((volatile tenuRegType*) 0x30) )
#define _SPDR 	(*((volatile tenuRegType*) 0x2F) )
#define _SPSR 	(*((volatile tenuRegType*) 0x2E) )
#define _SPCR 	(*((volatile tenuRegType*) 0x2D) )
#define _UDR 	(*((volatile tenuRegType*) 0x2C) )
#define _UCSRA 	(*((volatile tenuRegType*) 0x2B) )
#define _UCSRB 	(*((volatile tenuRegType*) 0x2A) )
#define _UBRRL 	(*((volatile tenuRegType*) 0x29) )
#define _ACSR 	(*((volatile tenuRegType*) 0x28) )
#define _ADMUX 	(*((volatile tenuRegType*) 0x27) )
#define _ADCSRA (*((volatile tenuRegType*) 0x26) )
#define _ADCH 	(*((volatile tenuRegType*) 0x25) )
#define _ADCL 	(*((volatile tenuRegType*) 0x24) )
#define _TWDR 	(*((volatile tenuRegType*) 0x23) )
#define _TWAR 	(*((volatile tenuRegType*) 0x22) )
#define _TWSR 	(*((volatile tenuRegType*) 0x21) )
#define _TWB 	(*((volatile tenuRegType*) 0x20) )
#endif /* ATMEGA32_REGISTERS_H_ */
