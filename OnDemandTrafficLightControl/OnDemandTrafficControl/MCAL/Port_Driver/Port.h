/*
 * Port_init.h
 *
 *  Created on: Dec 30, 2022
 *      Author: Esraa Abdelnaby
 */

#ifndef PORT_INT_H_
#define PORT_INT_H_


/*
 *
 * #define RCONC(a,b,c,d,e,f,g)		a##b##c##d##e##f
 * #define CONC(a,b,c,d,e,f,g)			RCONC(a,b,c,d,e,f,g)
 *
 * */

typedef enum{
	Port_enuPin_0  ,
	Port_enuPin_1  ,
	Port_enuPin_2  ,
	Port_enuPin_3  ,
	Port_enuPin_4  ,
	Port_enuPin_5  ,
	Port_enuPin_6  ,
	Port_enuPin_7  ,
	Port_enuPin_8  ,
	Port_enuPin_9  ,
	Port_enuPin_10 ,
	Port_enuPin_11 ,
	Port_enuPin_12 ,
	Port_enuPin_13 ,
	Port_enuPin_14 ,
	Port_enuPin_15 ,
	Port_enuPin_16 ,
	Port_enuPin_17 ,
	Port_enuPin_18 ,
	Port_enuPin_19 ,
	Port_enuPin_20 ,
	Port_enuPin_21 ,
	Port_enuPin_22 ,
	Port_enuPin_23 ,
	Port_enuPin_24 ,
	Port_enuPin_25 ,
	Port_enuPin_26 ,
	Port_enuPin_27 ,
	Port_enuPin_28 ,
	Port_enuPin_29 ,
	Port_enuPin_30 ,
	Port_enuPin_31

}Port_tenuPinId;

typedef enum{
	Port_enuOutputLow,
	Port_enuOutputHigh,
	Port_enuInputHighImpedance,
	Port_enuInputPullUp
}Port_tenuPinMode;

typedef enum{
	Port_enuInput,
	Port_enuOutput
}Port_tenuPinDir;

void Port_vid_Init(void);
u8 Port_u8SetPinDir(Port_tenuPinId Copy_enuPinId,  Port_tenuPinDir Copy_enuPinDir);
u8 Port_u8SetPinMode(Port_tenuPinId Copy_enupinId, Port_tenuPinMode Copy_enuPinMode);

#endif /* PORT_INT_H_ */
