/*
 * Dio_Test.c
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
#include "../../../MCAL/DIO_Driver/Dio.h"

#include <util/delay.h>

int main(void)
{
	Port_vid_Init();

	while(1)
	{
		if (Dio_u8GetPinVal(Port_enuPin_26) == 0)
		{
			Dio_u8TglPinVal(Port_enuPin_0);
			Dio_u8TglPinVal(Port_enuPin_1);
			Dio_u8TglPinVal(Port_enuPin_2);
		}
		else
		{
			Dio_u8TglPinVal(Port_enuPin_8);
			Dio_u8TglPinVal(Port_enuPin_9);
			Dio_u8TglPinVal(Port_enuPin_10);
		}
		_delay_ms(500);
	}
	return 0;
}
