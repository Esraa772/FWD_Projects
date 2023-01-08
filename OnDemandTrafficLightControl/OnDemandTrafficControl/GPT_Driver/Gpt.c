/*
 * Timer.c
 *
 *  Created on: Jan 1, 2023
 *      Author: Esraa Abdelnaby
 */

#include "../Service/Std_Types.h"
#include "../Service/ATmega32_Registers.h"
#include "../Service/Bit_Maths.h"
#include "../Service/Status.h"
#include <avr/interrupt.h>
#include "Gpt.h"

pfCallBackFunc AppNotifyTim0;
pfCallBackFunc AppNotifyTim1;
pfCallBackFunc AppNotifyTim2;

/*
 * Select Normal Mode for the specific Timer channel
 * */
u8 GPT_u8Init(Timer_e Copy_enuTimerChannel)
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		/*select normal mode*/
		_TCCR0.Bits.Bit3 = 0;
		_TCCR0.Bits.Bit6 = 0;

		/**/
		_TCCR0.Bits.Bit5 = 0;
		_TCCR0.Bits.Bit4 = 0;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_1)
	{
		_TCCR1A.Bits.Bit1 = 0;
		_TCCR1A.Bits.Bit0 = 0;

		_TCCR1B.Bits.Bit4 = 0;
		_TCCR1B.Bits.Bit3 = 0;

		_TCCR1A.Bits.Bit7 = 0;
		_TCCR1A.Bits.Bit6 = 0;

		_TCCR1B.Bits.Bit5 = 0;
		_TCCR1B.Bits.Bit4 = 0;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		_TCCR2.Bits.Bit6 = 0;
		_TCCR2.Bits.Bit3 = 0;

		_TCCR2.Bits.Bit5 = 0;
		_TCCR2.Bits.Bit4 = 0;

		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}

/*choose clock source*/
u8 GPT_u8StartTimer(Timer_e Copy_enuTimerChannel, u8 Copy_u8ClkSrc)
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		_TCCR0.Byte &= CLK_MASK;
		_TCCR0.Byte |= Copy_u8ClkSrc;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_1)
	{
		_TCCR0.Byte &= CLK_MASK;
		_TCCR0.Byte |= Copy_u8ClkSrc;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		_TCCR0.Byte &= CLK_MASK;
		_TCCR0.Byte |= Copy_u8ClkSrc;
		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}

/*choose clock source */
u8 GPT_u8StopTimer(Timer_e Copy_enuTimerChannel)
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		_TCCR0.Byte &= CLK_MASK;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_1)
	{
		_TCCR0.Byte &= CLK_MASK;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		_TCCR0.Byte &= CLK_MASK;
		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}

/*TCNT register (write value)*/
u8 GPT_u8LoadTimer8Bit(Timer_e Copy_enuTimerChannel, u8 Copy_u8LoadVal)
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		_TCNT0.Byte=Copy_u8LoadVal;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		_TCNT2.Byte=Copy_u8LoadVal;
		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}


/*TCNT register (write value)*/
u8 GPT_u8LoadTimer16Bit(Timer_e Copy_enuTimerChannel, u16 Copy_u16LoadVal)
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_1)
	{
		_TCNT1L.Byte = ((u8)(Copy_u16LoadVal));
		_TCNT1H.Byte = ((u8)(Copy_u16LoadVal << 8));
		Loc_u8Status = RT_SUCCESS;
	}
	return Loc_u8Status;
}

/*Enable overflow interrupt*/
u8 GPT_u8EnableNotification(Timer_e Copy_enuTimerChannel)
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		_TIMSK.Bits.Bit0 = 1;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_1)
	{
		_TIMSK.Bits.Bit2 = 1;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		_TIMSK.Bits.Bit6 = 1;
		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}

/*Disable overflow interrupt*/
u8 GPT_u8DisableNotification(Timer_e Copy_enuTimerChannel)
{

	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		_TIMSK.Bits.Bit0 = 0;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_1)
	{
		_TIMSK.Bits.Bit2 = 0;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		_TIMSK.Bits.Bit6 = 0;
		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}

/*Timer handler when the interrupt happend*/
u8 GPT_u8SetCallBack (Timer_e Copy_enuTimerChannel, pfCallBackFunc Copy_pfInterruptCbf )
{
	u8 Loc_u8Status = RT_PARAM;
	if (Copy_enuTimerChannel == Timer_0)
	{
		AppNotifyTim0 = Copy_pfInterruptCbf;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_1)
	{
		AppNotifyTim1 = Copy_pfInterruptCbf;
		Loc_u8Status = RT_SUCCESS;
	}
	else if (Copy_enuTimerChannel == Timer_2)
	{
		AppNotifyTim2 = Copy_pfInterruptCbf;
		Loc_u8Status = RT_SUCCESS;
	}

	return Loc_u8Status;
}

ISR(TIMER0_OVF_vect)
{
	AppNotifyTim0();
}

ISR(TIMER1_OVF_vect)
{
	AppNotifyTim1();
}

ISR(TIMER2_OVF_vect)
{
	AppNotifyTim2();
}
