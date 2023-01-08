/*
 * ExtInterrupt.c
 *
 *  Created on: Jan 8, 2023
 *      Author: Esraa Abdelnaby
 */

#include "../ExtInterrupt_Driver/ExtInterrupt.h"

#include "../../Service/Lib/Std_Types.h"
#include "../../Service/Lib/Bit_Maths.h"
#include "../../Service/Lib/Bit_Mask.h"
#include "../../Service/Lib/ATmega32_Registers.h"
#include "avr/interrupt.h"

#include "../ExtInterrupt_Driver/ExtInt_cfg.h"


#define INT_0_CLEAR_MASK		BIT0_CLEAR & BIT1_CLEAR
#define INT_1_CLEAR_MASK		BIT2_CLEAR & BIT3_CLEAR
#define INT_2_CLEAR_MASK		BIT6_CLEAR


/*array of pointer to function to serve the ISRs, (for CallBack functions) */
static pfCallBackFunc IsrFuns[3];

/*Default configuration */
void ExtIntr_vidInit(void){
#if DEF_STATE_INT_0 == EXT_INT_ON
	SET_BIT(GICR,6);
	MCUCR |= DEF_MODE_INT_0;
#endif

#if DEF_STATE_INT_1 == EXT_INT_ON
	SET_BIT(GICR,7);
	MCUCR |= DEF_MODE_INT_1 << 2;
#endif

#if DEF_STATE_INT_2 == EXT_INT_ON
	SET_BIT(GICR,5);
	MCUCSR |= DEF_MODE_INT_2;
#endif
}


void ExtIntr_vidSetCallBack(pfCallBackFunc Copy_pfunIsr,u8 Copy_u8IntrNumber){
	IsrFuns[Copy_u8IntrNumber] = Copy_pfunIsr;
}


void ExtIntr_vidEnableIntr(u8 Copy_u8IntrNumber){
	switch(Copy_u8IntrNumber){
	case EXT_INT_u8INT_0:	SET_BIT(GICR,6); break;
	case EXT_INT_u8INT_1:	SET_BIT(GICR,7); break;
	case EXT_INT_u8INT_2:	SET_BIT(GICR,5); break;
	}
}


void ExtIntr_vidDisbleIntr(u8 Copy_u8IntrNumber){
	switch(Copy_u8IntrNumber){
	case EXT_INT_u8INT_0:	CLR_BIT(GICR,6); break;
	case EXT_INT_u8INT_1:	CLR_BIT(GICR,7); break;
	case EXT_INT_u8INT_2:	CLR_BIT(GICR,5); break;
	}
}


void ExtIntr_vidSetIntrMode(u8 Copy_u8IntrNumber,u8 Copy_u8IntrMode){
	switch(Copy_u8IntrNumber){
	case EXT_INT_u8INT_0:	MCUCR  &= INT_0_CLEAR_MASK; MCUCR |= Copy_u8IntrMode;  break;
	case EXT_INT_u8INT_1:	MCUCR  &= INT_1_CLEAR_MASK; MCUCR |= (Copy_u8IntrMode << 2);  break;
	case EXT_INT_u8INT_2:
							ExtIntr_vidDisbleIntr(EXT_INT_u8INT_2);
							MCUCSR &= INT_2_CLEAR_MASK; MCUCSR |= Copy_u8IntrMode;
							GIFR |= BIT5;
							ExtIntr_vidEnableIntr(EXT_INT_u8INT_2);
							break;
	}
}


/************************************************************** ISRs *************************************************************/
ISR(INT0_vect)
{
	if(IsrFuns[0])
	{
		IsrFuns[0]();
	}
}


ISR(INT1_vect)
{
	if(IsrFuns[1])
	{
		IsrFuns[1]();
	}
}


ISR(INT2_vect)
{
	if(IsrFuns[2])
	{
		IsrFuns[2]();
	}
}
