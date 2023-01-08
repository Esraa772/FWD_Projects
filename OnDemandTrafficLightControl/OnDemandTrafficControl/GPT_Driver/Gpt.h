/*
 * Timer_int.h
 *
 *  Created on: Jan 1, 2023
 *      Author: Esraa Abdelnaby
 */

#ifndef GPT_INT_H_
#define GPT_INT_H_

typedef enum{
	Timer_0,
	Timer_1,
	Timer_2
}Timer_e;

pfCallBackFunc PtrFuncT0;
pfCallBackFunc PtrFuncT1;
pfCallBackFunc PtrFuncT2;


/*Clock source */
#define CLK_MASK			   0xF8
#define CLK_STOPPED				0
#define CLK_NO_PRESCALER		1
#define CLK_8_PRESCALER			2
#define CLK_64_PRESCALER		3
#define CLK_256_PRESCALER		4
#define CLK_1024_PRESCALER		5
#define CLK_EXT_FALLING_EDGE	6
#define CLK_EXT_RISING_EDGE		7

/*Select mode*/
extern u8 GPT_u8Init(Timer_e Copy_enuTimerChannel);

/*choose clock source*/
extern u8 GPT_u8StartTimer(Timer_e Copy_enuTimerChannel, u8 Copy_u8ClkSrc);

/*choose clock source */
extern u8 GPT_u8StopTimer(Timer_e Copy_enuTimerChannel);

/*TCNT register (write value)*/
extern u8 GPT_u8LoadTimer8Bit(Timer_e Copy_enuTimerChannel, u8 Copy_u8LoadVal);


/*TCNT register (write value)*/
extern u8 GPT_u8LoadTimer16Bit(Timer_e Copy_enuTimerChannel, u16 Copy_u16LoadVal);

/*Enable overflow interrupt*/
extern u8 GPT_u8EnableNotification(Timer_e Copy_enuTimerChannel);

/*Disable overflow interrupt*/
extern u8 GPT_u8DisableNotification(Timer_e Copy_enuTimerChannel);

/*Timer handler when the interrupt happend*/
extern u8 GPT_vidSetCallBack (Timer_e Copy_enuTimerChannel, pfCallBackFunc Copy_pfInterruptCbf );

#endif /* GPT_INT_H_ */
