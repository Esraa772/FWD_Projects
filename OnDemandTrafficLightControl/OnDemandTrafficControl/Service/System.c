/*
 * System.c
 *
 *  Created on: Jan 1, 2023
 *      Author: Esraa Abdelnaby
 */
#include "Std_Types.h"
#include "Bit_Maths.h"
#include "Atmega32_Registers.h"


void System_vidEnableGlobalInterrupt(void)
{
	SET_BIT(_SREG.Byte,7);
}
void System_vidDisableGlobalInterrupt(void)
{
	CLR_BIT(_SREG.Byte,7);
}
