/*
 * Port_Test.c
 *
 *  Created on: Jan 8, 2023
 *      Author: Esraa Abdelnaby
 */

#include "../../../Lib/Std_Types.h"
#include "../../../Lib/Bit_Maths.h"
#include "../../../Lib/Bit_Mask.h"
#include "../../../Lib/ATmega32_Registers.h"
#include "../../../Lib/Status.h"

#include "../../../MCAL/Port_Driver/Port.h"

#include <util/delay.h>

//int main(void)
//{
//	Port_vid_Init();
//
//	Port_u8SetPinDir(Port_enuPin_8, Port_enuOutput);
//	Port_u8SetPinMode(Port_enuPin_8, Port_enuOutputHigh);
//	Port_u8SetPinDir(Port_enuPin_9, Port_enuOutput);
//	Port_u8SetPinMode(Port_enuPin_9, Port_enuOutputLow);
//	Port_u8SetPinDir(Port_enuPin_10, Port_enuOutput);
//	Port_u8SetPinMode(Port_enuPin_10, Port_enuOutputHigh);
//
//	while(1)
//	{
//		if (GET_BIT(PIND.Byte, (Port_enuPin_2)) == 0)
//		{
//			TGL_BIT(PORTA.Byte, Port_enuPin_0);
//			TGL_BIT(PORTA.Byte, Port_enuPin_1);
//			TGL_BIT(PORTA.Byte, Port_enuPin_2);
//		}
//		else
//		{
//			TGL_BIT(PORTB.Byte, (Port_enuPin_8 % 8));
//			TGL_BIT(PORTB.Byte, (Port_enuPin_9 % 8));
//			TGL_BIT(PORTB.Byte, (Port_enuPin_10 % 8));
//		}
//		_delay_ms(500);
//	}
//	return 0;
//}
