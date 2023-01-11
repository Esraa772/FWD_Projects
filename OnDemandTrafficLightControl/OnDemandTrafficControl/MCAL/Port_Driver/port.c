/*
 * port.c
 *
 *  Created on: Dec 30, 2022
 *      Author: Esraa Abdelnaby
 */
#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Maths.h"
#include "../../Lib/ATmega32_Registers.h"
#include "../../Lib/Status.h"
#include "Port_cfg.h"
#include "Port_Priv.h"
#include "Port.h"


void Port_vid_Init(void)
{
#if PORT_u8PIN_0_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_0_DEF_DIR
#undef PORT_u8PIN_0_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_0_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_0_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_0_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_0_DEF_DIR
#undef PORT_u8PIN_0_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_0_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_0_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_0_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_0_DEF_DIR
#undef PORT_u8PIN_0_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_0_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_0_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_0_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_0_DEF_DIR
#undef PORT_u8PIN_0_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_0_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_0_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number0
#if PORT_u8PIN_1_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_1_DEF_DIR
#undef PORT_u8PIN_1_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_1_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_1_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_1_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_1_DEF_DIR
#undef PORT_u8PIN_1_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_1_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_1_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_1_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_1_DEF_DIR
#undef PORT_u8PIN_1_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_1_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_1_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_1_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_1_DEF_DIR
#undef PORT_u8PIN_1_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_1_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_1_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number1
#if PORT_u8PIN_2_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_2_DEF_DIR
#undef PORT_u8PIN_2_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_2_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_2_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_2_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_2_DEF_DIR
#undef PORT_u8PIN_2_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_2_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_2_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_2_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_2_DEF_DIR
#undef PORT_u8PIN_2_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_2_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_2_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_2_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_2_DEF_DIR
#undef PORT_u8PIN_2_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_2_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_2_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number2
#if PORT_u8PIN_3_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_3_DEF_DIR
#undef PORT_u8PIN_3_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_3_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_3_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_3_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_3_DEF_DIR
#undef PORT_u8PIN_3_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_3_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_3_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_3_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_3_DEF_DIR
#undef PORT_u8PIN_3_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_3_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_3_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_3_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_3_DEF_DIR
#undef PORT_u8PIN_3_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_3_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_3_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number3
#if PORT_u8PIN_4_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_4_DEF_DIR
#undef PORT_u8PIN_4_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_4_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_4_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_4_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_4_DEF_DIR
#undef PORT_u8PIN_4_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_4_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_4_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_4_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_4_DEF_DIR
#undef PORT_u8PIN_4_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_4_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_4_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_4_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_4_DEF_DIR
#undef PORT_u8PIN_4_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_4_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_4_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number4
#if PORT_u8PIN_5_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_5_DEF_DIR
#undef PORT_u8PIN_5_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_5_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_5_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_5_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_5_DEF_DIR
#undef PORT_u8PIN_5_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_5_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_5_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_5_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_5_DEF_DIR
#undef PORT_u8PIN_5_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_5_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_5_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_5_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_5_DEF_DIR
#undef PORT_u8PIN_5_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_5_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_5_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number5
#if PORT_u8PIN_6_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_6_DEF_DIR
#undef PORT_u8PIN_6_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_6_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_6_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_6_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_6_DEF_DIR
#undef PORT_u8PIN_6_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_6_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_6_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_6_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_6_DEF_DIR
#undef PORT_u8PIN_6_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_6_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_6_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_6_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_6_DEF_DIR
#undef PORT_u8PIN_6_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_6_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_6_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number6
#if PORT_u8PIN_7_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_7_DEF_DIR
#undef PORT_u8PIN_7_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_7_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_7_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_7_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_7_DEF_DIR
#undef PORT_u8PIN_7_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_7_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_7_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_7_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_7_DEF_DIR
#undef PORT_u8PIN_7_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_7_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_7_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_7_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_7_DEF_DIR
#undef PORT_u8PIN_7_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_7_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_7_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number7
#if PORT_u8PIN_8_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_8_DEF_DIR
#undef PORT_u8PIN_8_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_8_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_8_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_8_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_8_DEF_DIR
#undef PORT_u8PIN_8_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_8_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_8_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_8_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_8_DEF_DIR
#undef PORT_u8PIN_8_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_8_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_8_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_8_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_8_DEF_DIR
#undef PORT_u8PIN_8_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_8_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_8_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number8
#if PORT_u8PIN_9_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_9_DEF_DIR
#undef PORT_u8PIN_9_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_9_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_9_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_9_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_9_DEF_DIR
#undef PORT_u8PIN_9_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_9_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_9_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_9_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_9_DEF_DIR
#undef PORT_u8PIN_9_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_9_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_9_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_9_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_9_DEF_DIR
#undef PORT_u8PIN_9_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_9_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_9_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number9
#if PORT_u8PIN_10_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_10_DEF_DIR
#undef PORT_u8PIN_10_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_10_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_10_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_10_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_10_DEF_DIR
#undef PORT_u8PIN_10_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_10_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_10_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_10_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_10_DEF_DIR
#undef PORT_u8PIN_10_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_10_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_10_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_10_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_10_DEF_DIR
#undef PORT_u8PIN_10_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_10_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_10_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number10
#if PORT_u8PIN_11_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_11_DEF_DIR
#undef PORT_u8PIN_11_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_11_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_11_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_11_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_11_DEF_DIR
#undef PORT_u8PIN_11_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_11_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_11_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_11_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_11_DEF_DIR
#undef PORT_u8PIN_11_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_11_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_11_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_11_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_11_DEF_DIR
#undef PORT_u8PIN_11_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_11_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_11_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number11
#if PORT_u8PIN_12_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_12_DEF_DIR
#undef PORT_u8PIN_12_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_12_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_12_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_12_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_12_DEF_DIR
#undef PORT_u8PIN_12_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_12_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_12_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_12_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_12_DEF_DIR
#undef PORT_u8PIN_12_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_12_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_12_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_12_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_12_DEF_DIR
#undef PORT_u8PIN_12_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_12_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_12_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number12
#if PORT_u8PIN_13_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_13_DEF_DIR
#undef PORT_u8PIN_13_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_13_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_13_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_13_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_13_DEF_DIR
#undef PORT_u8PIN_13_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_13_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_13_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_13_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_13_DEF_DIR
#undef PORT_u8PIN_13_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_13_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_13_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_13_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_13_DEF_DIR
#undef PORT_u8PIN_13_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_13_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_13_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number13
#if PORT_u8PIN_14_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_14_DEF_DIR
#undef PORT_u8PIN_14_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_14_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_14_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_14_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_14_DEF_DIR
#undef PORT_u8PIN_14_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_14_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_14_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_14_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_14_DEF_DIR
#undef PORT_u8PIN_14_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_14_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_14_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_14_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_14_DEF_DIR
#undef PORT_u8PIN_14_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_14_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_14_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number14
#if PORT_u8PIN_15_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_15_DEF_DIR
#undef PORT_u8PIN_15_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_15_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_15_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_15_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_15_DEF_DIR
#undef PORT_u8PIN_15_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_15_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_15_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_15_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_15_DEF_DIR
#undef PORT_u8PIN_15_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_15_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_15_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_15_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_15_DEF_DIR
#undef PORT_u8PIN_15_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_15_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_15_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number15
#if PORT_u8PIN_16_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_16_DEF_DIR
#undef PORT_u8PIN_16_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_16_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_16_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_16_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_16_DEF_DIR
#undef PORT_u8PIN_16_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_16_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_16_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_16_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_16_DEF_DIR
#undef PORT_u8PIN_16_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_16_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_16_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_16_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_16_DEF_DIR
#undef PORT_u8PIN_16_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_16_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_16_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number16
#if PORT_u8PIN_17_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_17_DEF_DIR
#undef PORT_u8PIN_17_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_17_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_17_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_17_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_17_DEF_DIR
#undef PORT_u8PIN_17_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_17_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_17_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_17_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_17_DEF_DIR
#undef PORT_u8PIN_17_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_17_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_17_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_17_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_17_DEF_DIR
#undef PORT_u8PIN_17_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_17_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_17_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number17
#if PORT_u8PIN_18_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_18_DEF_DIR
#undef PORT_u8PIN_18_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_18_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_18_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_18_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_18_DEF_DIR
#undef PORT_u8PIN_18_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_18_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_18_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_18_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_18_DEF_DIR
#undef PORT_u8PIN_18_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_18_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_18_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_18_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_18_DEF_DIR
#undef PORT_u8PIN_18_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_18_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_18_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number18
#if PORT_u8PIN_19_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_19_DEF_DIR
#undef PORT_u8PIN_19_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_19_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_19_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_19_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_19_DEF_DIR
#undef PORT_u8PIN_19_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_19_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_19_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_19_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_19_DEF_DIR
#undef PORT_u8PIN_19_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_19_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_19_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_19_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_19_DEF_DIR
#undef PORT_u8PIN_19_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_19_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_19_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number19
#if PORT_u8PIN_20_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_20_DEF_DIR
#undef PORT_u8PIN_20_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_20_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_20_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_20_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_20_DEF_DIR
#undef PORT_u8PIN_20_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_20_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_20_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_20_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_20_DEF_DIR
#undef PORT_u8PIN_20_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_20_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_20_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_20_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_20_DEF_DIR
#undef PORT_u8PIN_20_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_20_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_20_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number20
#if PORT_u8PIN_21_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_21_DEF_DIR
#undef PORT_u8PIN_21_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_21_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_21_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_21_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_21_DEF_DIR
#undef PORT_u8PIN_21_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_21_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_21_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_21_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_21_DEF_DIR
#undef PORT_u8PIN_21_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_21_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_21_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_21_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_21_DEF_DIR
#undef PORT_u8PIN_21_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_21_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_21_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number21
#if PORT_u8PIN_22_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_22_DEF_DIR
#undef PORT_u8PIN_22_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_22_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_22_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_22_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_22_DEF_DIR
#undef PORT_u8PIN_22_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_22_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_22_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_22_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_22_DEF_DIR
#undef PORT_u8PIN_22_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_22_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_22_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_22_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_22_DEF_DIR
#undef PORT_u8PIN_22_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_22_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_22_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number22
#if PORT_u8PIN_23_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_23_DEF_DIR
#undef PORT_u8PIN_23_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_23_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_23_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_23_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_23_DEF_DIR
#undef PORT_u8PIN_23_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_23_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_23_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_23_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_23_DEF_DIR
#undef PORT_u8PIN_23_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_23_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_23_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_23_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_23_DEF_DIR
#undef PORT_u8PIN_23_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_23_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_23_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number23
#if PORT_u8PIN_24_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_24_DEF_DIR
#undef PORT_u8PIN_24_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_24_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_24_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_24_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_24_DEF_DIR
#undef PORT_u8PIN_24_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_24_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_24_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_24_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_24_DEF_DIR
#undef PORT_u8PIN_24_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_24_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_24_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_24_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_24_DEF_DIR
#undef PORT_u8PIN_24_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_24_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_24_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number24
#if PORT_u8PIN_25_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_25_DEF_DIR
#undef PORT_u8PIN_25_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_25_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_25_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_25_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_25_DEF_DIR
#undef PORT_u8PIN_25_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_25_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_25_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_25_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_25_DEF_DIR
#undef PORT_u8PIN_25_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_25_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_25_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_25_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_25_DEF_DIR
#undef PORT_u8PIN_25_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_25_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_25_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number25
#if PORT_u8PIN_26_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_26_DEF_DIR
#undef PORT_u8PIN_26_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_26_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_26_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_26_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_26_DEF_DIR
#undef PORT_u8PIN_26_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_26_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_26_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_26_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_26_DEF_DIR
#undef PORT_u8PIN_26_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_26_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_26_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_26_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_26_DEF_DIR
#undef PORT_u8PIN_26_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_26_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_26_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number26
#if PORT_u8PIN_27_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_27_DEF_DIR
#undef PORT_u8PIN_27_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_27_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_27_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_27_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_27_DEF_DIR
#undef PORT_u8PIN_27_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_27_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_27_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_27_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_27_DEF_DIR
#undef PORT_u8PIN_27_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_27_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_27_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_27_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_27_DEF_DIR
#undef PORT_u8PIN_27_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_27_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_27_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number27
#if PORT_u8PIN_28_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_28_DEF_DIR
#undef PORT_u8PIN_28_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_28_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_28_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_28_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_28_DEF_DIR
#undef PORT_u8PIN_28_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_28_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_28_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_28_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_28_DEF_DIR
#undef PORT_u8PIN_28_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_28_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_28_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_28_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_28_DEF_DIR
#undef PORT_u8PIN_28_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_28_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_28_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number28
#if PORT_u8PIN_29_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_29_DEF_DIR
#undef PORT_u8PIN_29_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_29_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_29_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_29_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_29_DEF_DIR
#undef PORT_u8PIN_29_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_29_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_29_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_29_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_29_DEF_DIR
#undef PORT_u8PIN_29_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_29_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_29_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_29_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_29_DEF_DIR
#undef PORT_u8PIN_29_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_29_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_29_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number29
#if PORT_u8PIN_30_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_30_DEF_DIR
#undef PORT_u8PIN_30_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_30_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_30_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_30_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_30_DEF_DIR
#undef PORT_u8PIN_30_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_30_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_30_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_30_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_30_DEF_DIR
#undef PORT_u8PIN_30_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_30_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_30_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_30_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_30_DEF_DIR
#undef PORT_u8PIN_30_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_30_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_30_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif


	//This is the checking condition for pin number30
#if PORT_u8PIN_31_INIT_MODE == PORT_u8OUTPUT_LOW
	//clear previous definition
#undef PORT_u8PIN_31_DEF_DIR
#undef PORT_u8PIN_31_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_31_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_31_DEF_VAL   PORT_u8LOW


#elif PORT_u8PIN_31_INIT_MODE == PORT_u8OUTPUT_HIGH
	//clear previous definition
#undef PORT_u8PIN_31_DEF_DIR
#undef PORT_u8PIN_31_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_31_DEF_DIR   PORT_u8OUTPUT
#define PORT_u8PIN_31_DEF_VAL   PORT_u8HIGH


#elif PORT_u8PIN_31_INIT_MODE == PORT_u8INPUT_PULL_UP
	//clear previous definition
#undef PORT_u8PIN_31_DEF_DIR
#undef PORT_u8PIN_31_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_31_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_31_DEF_VAL   PORT_u8HIGH

	// In case not input pull up (this is equivalent to pull down in other ucs)
#elif PORT_u8PIN_31_INIT_MODE == PORT_u8INPUT_HIGH_IMP
#undef PORT_u8PIN_31_DEF_DIR
#undef PORT_u8PIN_31_DEF_VAL
	// Redefinition of the pin direction and value
#define PORT_u8PIN_31_DEF_DIR   PORT_u8INPUT
#define PORT_u8PIN_31_DEF_VAL   PORT_u8LOW


#else
#warning "Take care, This pin is not configured"

#endif

	DDRA.Byte = CONC(PORT_u8PIN_7_DEF_DIR,
			PORT_u8PIN_6_DEF_DIR,
			PORT_u8PIN_5_DEF_DIR,
			PORT_u8PIN_4_DEF_DIR,
			PORT_u8PIN_3_DEF_DIR,
			PORT_u8PIN_2_DEF_DIR,
			PORT_u8PIN_1_DEF_DIR,
			PORT_u8PIN_0_DEF_DIR);

	DDRB.Byte= CONC(PORT_u8PIN_15_DEF_DIR,
			PORT_u8PIN_14_DEF_DIR,
			PORT_u8PIN_13_DEF_DIR,
			PORT_u8PIN_12_DEF_DIR,
			PORT_u8PIN_11_DEF_DIR,
			PORT_u8PIN_10_DEF_DIR,
			PORT_u8PIN_9_DEF_DIR,
			PORT_u8PIN_8_DEF_DIR);

	DDRC.Byte = CONC(PORT_u8PIN_23_DEF_DIR,
			PORT_u8PIN_22_DEF_DIR,
			PORT_u8PIN_21_DEF_DIR,
			PORT_u8PIN_20_DEF_DIR,
			PORT_u8PIN_19_DEF_DIR,
			PORT_u8PIN_18_DEF_DIR,
			PORT_u8PIN_17_DEF_DIR,
			PORT_u8PIN_16_DEF_DIR);

	DDRD.Byte = CONC(PORT_u8PIN_31_DEF_DIR,
			PORT_u8PIN_30_DEF_DIR,
			PORT_u8PIN_29_DEF_DIR,
			PORT_u8PIN_28_DEF_DIR,
			PORT_u8PIN_27_DEF_DIR,
			PORT_u8PIN_26_DEF_DIR,
			PORT_u8PIN_25_DEF_DIR,
			PORT_u8PIN_24_DEF_DIR);

	PORTA.Byte = CONC(PORT_u8PIN_7_DEF_VAL,
			PORT_u8PIN_6_DEF_VAL,
			PORT_u8PIN_5_DEF_VAL,
			PORT_u8PIN_4_DEF_VAL,
			PORT_u8PIN_3_DEF_VAL,
			PORT_u8PIN_2_DEF_VAL,
			PORT_u8PIN_1_DEF_VAL,
			PORT_u8PIN_0_DEF_VAL);

	PORTB.Byte = CONC(PORT_u8PIN_15_DEF_VAL,
			PORT_u8PIN_14_DEF_VAL,
			PORT_u8PIN_13_DEF_VAL,
			PORT_u8PIN_12_DEF_VAL,
			PORT_u8PIN_11_DEF_VAL,
			PORT_u8PIN_10_DEF_VAL,
			PORT_u8PIN_9_DEF_VAL,
			PORT_u8PIN_8_DEF_VAL);

	PORTC.Byte = CONC(PORT_u8PIN_23_DEF_VAL,
			PORT_u8PIN_22_DEF_VAL,
			PORT_u8PIN_21_DEF_VAL,
			PORT_u8PIN_20_DEF_VAL,
			PORT_u8PIN_19_DEF_VAL,
			PORT_u8PIN_18_DEF_VAL,
			PORT_u8PIN_17_DEF_VAL,
			PORT_u8PIN_16_DEF_VAL);

	PORTD.Byte = CONC(PORT_u8PIN_31_DEF_VAL,
			PORT_u8PIN_30_DEF_VAL,
			PORT_u8PIN_29_DEF_VAL,
			PORT_u8PIN_28_DEF_VAL,
			PORT_u8PIN_27_DEF_VAL,
			PORT_u8PIN_26_DEF_VAL,
			PORT_u8PIN_25_DEF_VAL,
			PORT_u8PIN_24_DEF_VAL);
}


u8 Port_u8SetPinDir(Port_tenuPinId Copy_enupinId, Port_tenuPinDir Copy_enuPinDir)
{
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;
	status_RT Loc_u8FuncReturn = RT_SUCCESS;

	if(Copy_enuPinDir != Port_enuOutput && Copy_enuPinDir != Port_enuInput)
	{
		Loc_u8FuncReturn = RT_PARAM;
	}
	else if (Copy_enupinId > 31)
	{
		Loc_u8FuncReturn = RT_ERROR;
	}
	if (Loc_u8FuncReturn == RT_SUCCESS)
	{
		Loc_u8PortId =(u8) Copy_enupinId / (u8) 8;
		Loc_u8PinId = (u8) Copy_enupinId % (u8) 8;
		switch(Loc_u8PortId)
		{
		case 0:
			if(Copy_enuPinDir == Port_enuOutput)
			{
				SET_BIT(DDRA.Byte,Loc_u8PinId);
			}
			else
			{
				CLR_BIT(DDRA.Byte,Loc_u8PinId);
			}
			break;
		case 1:
			if(Copy_enuPinDir == Port_enuOutput)
			{
				SET_BIT(DDRB.Byte,Loc_u8PinId);
			}
			else
			{
				CLR_BIT(DDRB.Byte,Loc_u8PinId);
			}
			break;
		case 2:
			if(Copy_enuPinDir == Port_enuOutput)
			{
				SET_BIT(DDRC.Byte,Loc_u8PinId);
			}
			else
			{
				CLR_BIT(DDRC.Byte,Loc_u8PinId);
			}
			break;
		case 3:
			if(Copy_enuPinDir == Port_enuOutput)
			{
				SET_BIT(DDRD.Byte,Loc_u8PinId);
			}
			else
			{
				CLR_BIT(DDRD.Byte,Loc_u8PinId);
			}
			break;
		default:
			Loc_u8FuncReturn = RT_PARAM;
			break;
		}
	}
	return Loc_u8FuncReturn;
}


u8 Port_u8SetPinMode(Port_tenuPinId Copy_enupinId, Port_tenuPinMode Copy_enuPinMode)
{
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;
	u8 Loc_u8FuncReturn = RT_SUCCESS;

	if(Copy_enuPinMode > Port_enuInputPullUp)
	{
		Loc_u8FuncReturn = RT_PARAM;
	}
	else if (Copy_enupinId > 31)
	{
		Loc_u8FuncReturn = RT_ERROR;
	}
	if (RT_SUCCESS == Loc_u8FuncReturn)
	{
		Loc_u8PortId = (u8) Copy_enupinId / (u8) 8;
		Loc_u8PinId =  (u8) Copy_enupinId % (u8) 8;
		switch(Loc_u8PortId)
		{
		case 0:
			if( Copy_enuPinMode == Port_enuOutputLow)
			{
				SET_BIT(DDRA.Byte,Loc_u8PinId );
				CLR_BIT(PORTA.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuOutputHigh)
			{
				SET_BIT(DDRA.Byte,Loc_u8PinId );
				SET_BIT(PORTA.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputHighImpedance)
			{
				CLR_BIT(DDRA.Byte,Loc_u8PinId );
				CLR_BIT(PORTA.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputPullUp)
			{
				CLR_BIT(DDRA.Byte,Loc_u8PinId );
				SET_BIT(PORTA.Byte,Loc_u8PinId);
			}
			break;
		case 1:
			if( Copy_enuPinMode == Port_enuOutputLow)
			{
				SET_BIT(DDRB.Byte,Loc_u8PinId );
				CLR_BIT(PORTB.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuOutputHigh)
			{
				SET_BIT(DDRB.Byte,Loc_u8PinId );
				SET_BIT(PORTB.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputHighImpedance)
			{
				CLR_BIT(DDRB.Byte,Loc_u8PinId );
				CLR_BIT(PORTB.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputPullUp)
			{
				CLR_BIT(DDRB.Byte,Loc_u8PinId );
				SET_BIT(PORTB.Byte,Loc_u8PinId);
			}
			break;
		case 2:
			if( Copy_enuPinMode == Port_enuOutputLow)
			{
				SET_BIT(DDRC.Byte,Loc_u8PinId );
				CLR_BIT(PORTC.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuOutputHigh)
			{
				SET_BIT(DDRC.Byte,Loc_u8PinId );
				SET_BIT(PORTC.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputHighImpedance)
			{
				CLR_BIT(DDRC.Byte,Loc_u8PinId );
				CLR_BIT(PORTC.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputPullUp)
			{
				CLR_BIT(DDRC.Byte,Loc_u8PinId );
				SET_BIT(PORTC.Byte,Loc_u8PinId);
			}
			break;
		case 3:
			if( Copy_enuPinMode == Port_enuOutputLow)
			{
				SET_BIT(DDRD.Byte,Loc_u8PinId );
				CLR_BIT(PORTD.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuOutputHigh)
			{
				SET_BIT(DDRD.Byte,Loc_u8PinId );
				SET_BIT(PORTD.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputHighImpedance)
			{
				CLR_BIT(DDRD.Byte,Loc_u8PinId );
				CLR_BIT(PORTD.Byte,Loc_u8PinId);
			}
			else if( Copy_enuPinMode == Port_enuInputPullUp)
			{
				CLR_BIT(DDRD.Byte,Loc_u8PinId );
				SET_BIT(PORTD.Byte,Loc_u8PinId);
			}
			break;

		default:
			break;
		}
	}
	return Loc_u8FuncReturn;
}
