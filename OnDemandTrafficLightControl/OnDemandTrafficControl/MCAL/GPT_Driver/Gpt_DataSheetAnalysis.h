/*
 * Data sheet analysis
 *
 *  Created on: Jan 1, 2023
 *      Author: Esraa Abdelnaby
 */

#ifndef GPT_DATASHEETANALYSIS_H_
#define GPT_DATASHEETANALYSIS_H_

/*
8-bit Timer/Counter
TCCR0
 * Timer/Counter modes:
 * Normal Mode,
 * Clear Timer on compare match (CTC) Mode,
 * two types of PWM Modes
 --> WGM01 bit 3, WGM00 bit 6 <-- define mode
 * Mode	|	WGN01	|	WGM00	|	Mode of Operation | Top  |
 * -----|-----------|-----------|---------------------|------|
 * 	0	|	  0 	|	  0		|Normal				  | 0xFF |

 -->COM01 bit 5, COM00 bit 4 <--
 compare output mode , non PWM mode
 * 	COM01	|	COM00	|	Description
 *----------|-----------|---------------------
 * 	  0 	|	  0		|OC0 disconnected ,Normal port operation

 --> CS02 bit 2, CS01 bit 1, CS00 bit 0 <--
 Clock source select
 *	CS02	|	CS01	|	CS00	|	Description
 *	--------|-----------|-----------|--------------
 *	  0		|	  0		|	  0		|No CLK (Timer/counter Stopped)
 *	  0		|	  0		|	  1		|Clk with no prescaling
 *	  0		|	  1		|	  0		|clk with 8 prescaler
 *	  0		|	  1		|	  1		|clk with 64 prescaler
 *	  1		|	  0		|	  0		|clk with 256 prescaler
 *	  1		|	  0		|	  1		|clk with 1024 prescaler
 *	  1		|	  1		|	  0		|external clk source on T0, clk on falling edge
 *	  1		|	  1		|	  1		|external clk source on T0, clk on rising edge
 *
 *	TCNT0 : Read/write operations on Timer/counter unit 8-bit counter
 *
 *	TIMSK :
 *	Bit0-TOIE0 :	Timer/Counter0 overflow
 *
 *	TIFR :
 *	Bit0-TOV0	:	Timer/Counter0 Overflow Flag
 *
 *	======================================================
 *
 *	16-bit Timer/Counter (TCCR1A,TCCR1B)
 *
 *	TCCR1A
 *	COM1A1 Bit7, COM1A0 Bit6, COM1B1 Bit5, COM1B0 Bit4 => wil be set with 0 in Normal Mode
 *
 *	Mode selection "Combine TCCR1A and TCCR1B"
 *	WGM11 TCCR1A Bit1, WGM10 TCCR1A Bit0
 *	WGM13 TCCR1B Bit4, WGM12 TCCR1B Bit3
 * Mode	|	WGM13	|	WGM12	|	WGM11	|	WGM10	|	Mode of Operation | Top  |
 * -----|-----------|-----------|-----------|-----------|---------------------|------|
 * 	0	|	  0 	|	  0		|	  0		|	  0		|Normal				  | 0xFF |
 *
 *
 * 	Clock source select
 * 	CS12 TCCR1B Bit2, CS11 TCCR1B Bit1, CS10 TCCR1B Bit0
 *
 * 	CS12	|	CS11	|	CS10	|	Description
 *	--------|-----------|-----------|--------------
 *	  0		|	  0		|	  0		|No CLK (Timer/counter Stopped)
 *	  0		|	  0		|	  1		|Clk with no prescaling
 *	  0		|	  1		|	  0		|clk with 8 prescaler
 *	  0		|	  1		|	  1		|clk with 64 prescaler
 *	  1		|	  0		|	  0		|clk with 256 prescaler
 *	  1		|	  0		|	  1		|clk with 1024 prescaler
 *	  1		|	  1		|	  0		|external clk source on T1, clk on falling edge
 *	  1		|	  1		|	  1		|external clk source on T1, clk on rising edge
 *
 *
 * 	TCNT1H --|
 * 	 		 |--> for read/write operations on Timer/Counter unit 16-bit counter
 * 	TCNT1L --|
 *
 * 	TIMSK :
 * 	Bit 2 ==> TOIE1 Timer/counter 1 overflow interrupt Enable
 *
 * 	TIFR:
 * 	Bit 2 ==> TOV1 Timer/counter 1 overflow flag
 *
 * 	=====================================================================
 *
 * 	8-bit Timer/Counter 2
 *
 * 	TCCR2 :
 * Mode	|	WGN21	|	WGM20	|	Mode of Operation | Top  |
 * -----|-----------|-----------|---------------------|------|
 * 	0	|	  0 	|	  0		|	Normal				  | 0xFF |
 *
 * 	COM21	|	COM20	|	Description
 *----------|-----------|---------------------
 * 	  0 	|	  0		|OC0 disconnected ,Normal port operation
 *
 *
 * 	TCNT2 : Read / Write
 *
 * 	TIMSK : Bit6 - TOIE2 Timer/counter 2 overflow interrupt Enable
 *
 * 	TIFR : Bit6 - TOV2 timer/counter 2 overflow flag
 * */
#endif /* GPT_DATASHEETANALYSIS_H_ */
