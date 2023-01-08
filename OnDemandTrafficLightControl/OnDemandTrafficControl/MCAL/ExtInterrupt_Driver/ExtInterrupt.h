/*
 * ExtInterrupt.h
 *
 *  Created on: Jan 8, 2023
 *      Author: Esraa Abdelnaby
 */

#ifndef EXTERNAL_INTERRUPT_DRIVER_EXTINTERRUPT_H_
#define EXTERNAL_INTERRUPT_DRIVER_EXTINTERRUPT_H_

	/*External interrupts */
#define EXT_INT_u8INT_0						(u8)0
#define EXT_INT_u8INT_1						(u8)1
#define EXT_INT_u8INT_2						(u8)2

	/*External interrupts modes */
#define EXT_INT_u8LOW_LEVEL					(u8)0
#define EXT_INT_u8ANY_LOGICAL_CHANGE		(u8)1
#define EXT_INT_u8RISING_EDGE				(u8)2
#define EXT_INT_u8FALLING_EDGE				(u8)3

#define EXT_INT2_u8RISING_EDGE				(u8)0
#define EXT_INT2_u8FALLING_EDGE				(u8)BIT_MASK_6



void ExtIntr_vidInit(void);

void ExtIntr_vidSetCallBack(pfCallBackFunc Copy_pfunIsr,u8 Copy_u8IntrNumber);

void ExtIntr_vidEnableIntr(u8 Copy_u8IntrNumber);

void ExtIntr_vidDisbleIntr(u8 Copy_u8IntrNumber);

void ExtIntr_vidSetIntrMode(u8 Copy_u8IntrNumber,u8 Copy_u8IntrMode);

#endif /* EXTERNAL_INTERRUPT_DRIVER_EXTINTERRUPT_H_ */
