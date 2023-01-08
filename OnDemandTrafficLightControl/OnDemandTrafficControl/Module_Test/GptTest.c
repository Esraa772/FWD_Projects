/*
 * TestSchM.c
 *
 *  Created on: Jan 1, 2023
 *      Author: Esraa Abdelnaby
 */

#include "../Service/Std_types.h"
#include "../Service/Bit_Maths.h"
#include "../Service/ATmega32_Registers.h"
#include "../Port_Driver/Port.h"
#include "../Service/System.h"
#include <avr/interrupt.h>

#include "../GPT_Driver/Gpt.h"

void func1(void)
{
	TGL_BIT(PORTB,3);
	TGL_BIT(PORTB,2);

}

void func2(void)
{
	TGL_BIT(PORTB,2);
}

int main(void)
{
	Port_vid_Init();

	GPT_u8Init(Timer_0);

	GPT_u8EnableNotification(Timer_0);

	GPT_u8SetCallBack(Timer_0,func1);

	GPT_u8LoadTimer8Bit(Timer_0,248);

	GPT_u8StartTimer(Timer_0,CLK_1024_PRESCALER);

	System_vidEnableGlobalInterrupt();
	while(1)
	{

	}
	return 0;
}


