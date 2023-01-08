/*
 * ExtInt_cfg.h
 *
 *  Created on: Jan 8, 2023
 *      Author: Esraa Abdelnaby
 */

#ifndef EXTERNAL_INTERRUPT_DRIVER_EXTINT_CFG_H_
#define EXTERNAL_INTERRUPT_DRIVER_EXTINT_CFG_H_

#define EXT_INT_OFF				0
#define EXT_INT_ON				1

#define DEF_STATE_INT_0		EXT_INT_ON
#define DEF_STATE_INT_1		EXT_INT_OFF
#define DEF_STATE_INT_2		EXT_INT_OFF


/*	Default modes are :
 * 					1- EXT_INTR_u8FALLING_EDGE
 * 					2- EXT_INTR_u8RISING_EDGE
 * 					3- EXT_INTR_u8LOW_LEVEL
 * 					4- EXT_INTR_u8ANY_LOGICAL_CHANGE
 * 					*/

#if DEF_STATE_INT_0 == EXT_INT_ON
#define DEF_MODE_INT_0		EXT_INT_u8LOW_LEVEL
#endif

#if DEF_STATE_INT_1 == EXT_INT_ON
#define DEF_MODE_INT_1		EXT_INT_u8LOW_LEVEL
#endif

/*	Default modes are :
 *  		 EXT_INT2_u8RISING_EDGE
 *			 EXT_INT2_u8FALLING_EDGE
 * */

#if DEF_STATE_INT_2 == EXT_INT_ON
#define DEF_MODE_INT_2		EXT_INT2_u8RISING_EDGE
#endif


#endif /* EXTERNAL_INTERRUPT_DRIVER_EXTINT_CFG_H_ */
