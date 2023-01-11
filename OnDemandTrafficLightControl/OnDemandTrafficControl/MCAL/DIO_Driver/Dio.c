/*
 * DIO_INT.c
 *
 *  Created on: Dec 30, 2022
 *      Author: Esraa Abdelnaby
 */


#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Maths.h"
#include "../../Lib/ATmega32_Registers.h"
#include "Dio_priv.h"
#include "Dio.h"

u8 Dio_u8SetPinVal(u8 Copy_u8SwPinId, u8 Copy_u8SwPinVal)
{
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	Loc_u8PortId = Copy_u8SwPinId / 8;
	Loc_u8PinId = Copy_u8SwPinId % 8;

	switch(Loc_u8PortId)
	{
	case 0:
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTA.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		else
		{
			CLR_BIT(PORTA.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		break;
	case 1:
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTB.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		else
		{
			CLR_BIT(PORTB.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		break;
	case 2:
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTC.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		else
		{
			CLR_BIT(PORTC.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		break;
	case 3:
		if(Copy_u8SwPinVal == DIO_u8HIGH)
		{
			SET_BIT(PORTD.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		else
		{
			CLR_BIT(PORTD.Byte,Loc_u8PinId);
			return STATE_OK;
		}
		break;

	default:
		return STATE_NOT_OK;
		break;
	}

}

u8 Dio_u8GetPinVal(u8 Copy_u8SwPinId, u8 * Copy_u8PtrSwPinVal)
{
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	u8 Loc_u8FuncReturn = RT_SUCCESS;

	if (Copy_u8SwPinId > 31)
	{
		Loc_u8FuncReturn = RT_ERROR;
	}
	if (RT_SUCCESS == Loc_u8FuncReturn)
	{
		Loc_u8PortId = Copy_u8SwPinId / 8;
		Loc_u8PinId = Copy_u8SwPinId % 8;

		switch(Loc_u8PortId)
		{
		case 0:
			*Copy_u8PtrSwPinVal = GET_BIT(PINA.Byte,Loc_u8PinId);
			break;
		case 1:
			*Copy_u8PtrSwPinVal = GET_BIT(PINB.Byte,Loc_u8PinId);
			break;
		case 2:
			*Copy_u8PtrSwPinVal = GET_BIT(PINC.Byte,Loc_u8PinId);
			break;
		case 3:
			*Copy_u8PtrSwPinVal = GET_BIT(PIND.Byte,Loc_u8PinId);
			break;

		default:
			Loc_u8FuncReturn = RT_ERROR;
			break;
		}
	}

	return Loc_u8FuncReturn;
}

u8 Dio_u8TglPinVal(u8 Copy_u8SwPinId)
{
	u8 Loc_u8PinId;
	u8 Loc_u8PortId;
	u8 Loc_u8PrevState;

	Loc_u8PortId =  Copy_u8SwPinId / 8;
	Loc_u8PinId  =  Copy_u8SwPinId % 8;

	Loc_u8PrevState = Dio_u8GetPinVal(Copy_u8SwPinId);

	switch(Loc_u8PortId)
	{
	case 0:

		if(Loc_u8PrevState == DIO_u8LOW)
		{
			SET_BIT(PORTA.Byte,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTA.Byte,Loc_u8PinId);
		}
//		TGL_BIT(PORTA.Byte,Loc_u8PinId);
		return STATE_OK;
		break;
	case 1:

		TGL_BIT(PORTB.Byte,Loc_u8PinId);
		return STATE_OK;
		break;
	case 2:

		TGL_BIT(PORTC.Byte,Loc_u8PinId);
		return STATE_OK;
		break;
	case 3:

		TGL_BIT(PORTD.Byte,Loc_u8PinId);
		return STATE_OK;
		break;
	default:
		return STATE_NOT_OK;
		break;
	}
}
