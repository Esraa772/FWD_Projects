/*
 * Bit_Math.h
 *
 *  Created on: Dec 30, 2022
 *      Author: Esraa Abdelnaby
 */

#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_

#define SET_BIT(Reg,Bit)                 ( (Reg) |=  ( (1) << (Bit) )  )
#define CLR_BIT(Reg,Bit)                 ( (Reg) &= ~( (1) << (Bit) )  )
#define TGL_BIT(Reg,Bit)                 ( (Reg) ^=  ( (1) << (Bit) )  )

#define GET_BIT(Reg,Bit)				 ( ((Reg) >> (Bit)) & (1) )

#define ASSIGN_REG(Reg,Value)			 ( (Reg) = (Value) )
#define ASSIGN_NIB_HIGH(Reg,Value)		 ( (Reg) = ( (Reg) & (0x0f) ) | ( (Value) << (4) ) )
#define ASSIGN_NIB_LOW(Reg,Value)		 ( (Reg) = ( (Reg) & (0xf0) ) | (Value) )

#define SET_REG(Reg)					 ( (Reg) = (0xff) )
#define RST_REG(Reg)					 ( (Reg) = (0x00) )

#define SET_NIB_HIGH(Reg)				 ( (Reg) = ( (Reg) & (0x0f) ) | (0x0f) )
#define SET_NIB_LOW(Reg)				 ( (Reg) = ( (Reg) & (0xf0) ) | (0xf0) )

#define RST_NIB_HIGH(Reg)				 ( (Reg) = ( (Reg) & (0x0f) ) | (0x00) )
#define RST_NIB_LOW(Reg)				 ( (Reg) = ( (Reg) & (0xf0) ) | (0x00) )

#define GET_NIB_HIGH(Reg)				 ( (Reg) & (0x0f) )
#define GET_NIB_LOW(Reg)				 ( (Reg) & (0xf0) )

#define ROT_REG_RIGHT(Reg,Step)			 ( (Reg) = ( (Reg) >> (Step) ) | ( (Reg) << ((8) - (Step) ) ) )
#define ROT_REG_LEFT(Reg,Step)			 ( (Reg) = ( (Reg) << (Step) ) | ( (Reg) >> ((8) - (Step) ) ) )


#define RCONC(a,x,c,d,e,f,g,h)	0b##a##x##c##d##e##f##g##h  //0b0000000

/*CONC ==> send number to RCONC :for example CONC(a,b,c,d,e,f,g,h) RCONC(0,0,0,0,0,0,0,0)
 * RCONC ==> 0b00000000
 * */
#define CONC(a,x,c,d,e,f,g,h)   RCONC(a,x,c,d,e,f,g,h) // replace each character with its value
/*note : high nibble 5-8
low nibble 1-4*/
#endif /* BIT_MATHS_H_ */
