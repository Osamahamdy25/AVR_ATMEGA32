/******************************************************************************
 *
 * Module: Dio Driver
 *
 * File Name: Dio.c
 *
 * Description: Source  file for the AVR DIO Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/

#include "Dio.h"
#include "avr/io.h"                        /* To use the IO  Registers */

/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/

/*
 * Description :
 * Write the Value level of the required channel pin.
 * If the input ChannelId number or ChannelLevel are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Channel Id & Channel Level
 * Function Return : Error Status of Dio Channel
 *
 */

Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId,u8 Copy_u8ChannelLevel)
{
	/* Intialize variabla to save the number of pin */
		u8 LOC_u8PinNum = 0;
		/* Intialize variable to save the number of ports */
		u8 LOC_u8PortNum = 0;
		/* Intialize Variable to return the Dio Error status */
		Dio_tenuErrorStatus LOC_enuReturnStatus=Dio_enuOk;
		if(Copy_u8ChannelId>PORTD_PIN0_ID||Copy_u8ChannelId<PORTA_PIN0_ID)
		{
			/* Return Error of channel number*/
			LOC_enuReturnStatus=Dio_ChannelError;
		}
		else if(Copy_u8ChannelLevel>STD_HIGH||Copy_u8ChannelLevel<STD_LOW)
		{
			/* return error of level number */
			LOC_enuReturnStatus=Dio_LevelError;
		}
		/* switch case to know the port_id and pin_id */
		else{
			/* variable to save the pin number */
			u8 LOC_u8PinNum = Copy_u8ChannelId/NUM_OF_PINS_PER_PORT;
			/* variable to save the port number */
			u8 LOC_u8PortNum = Copy_u8ChannelId%NUM_OF_PINS_PER_PORT;
			switch(LOC_u8PortNum)
			{
			case PORTA_ID:
				SET_BIT(PORTA,LOC_u8PinNum);
				break;
			case PORTB_ID:
				SET_BIT(PORTB,LOC_u8PinNum);
				break;
			case PORTC_ID:
				SET_BIT(PORTC,LOC_u8PinNum);
				break;
			case PORTD_ID:
				SET_BIT(PORTD,LOC_u8PinNum);
				break;
			}

		}

		return LOC_enuReturnStatus;
}
/* Description :
* Read the Value level of the required channel pin.
* If the input ChannelId number or The ChannelLevel pointer is equal NULL , The function will not handle the request and will return Error .
* Function Paramters : Channel Id &Address of  Channel Level
* Function Return : Error Status of Dio Channel
*
*/

Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId,pu8 Add_pu8ChannelLevel)
{
	/* Intialize variabla to save the number of pin */
			u8 LOC_u8PinNum = 0;
			/* Intialize variable to save the number of ports */
			u8 LOC_u8PortNum = 0;
			/* Intialize Variable to return the Dio Error status */
			Dio_tenuErrorStatus LOC_enuReturnStatus=Dio_enuOk;

			/* Check for the validity of channel Id */
			if(Copy_u8ChannelId>PORTD_PIN0_ID||Copy_u8ChannelId<PORTA_PIN0_ID)
			{
				/* Return Error of channel number*/
				LOC_enuReturnStatus=Dio_ChannelError;
			}

			/* check the null pointer error */
			else if (Add_pu8ChannelLevel==NULL_PTR)
			{
				/* Return Error of NULL Pointer*/
				LOC_enuReturnStatus=Dio_PointerError;
			}
			/* switch case to know the port_id and pin_id */
			else{
				/* variable to save the pin number */
				u8 LOC_u8PinNum = Copy_u8ChannelId/NUM_OF_PINS_PER_PORT;
				/* variable to save the port number */
				u8 LOC_u8PortNum = Copy_u8ChannelId%NUM_OF_PINS_PER_PORT;
				switch(LOC_u8PortNum)
				{
				case PORTA_ID:
					Add_pu8ChannelLevel=GET_BIT(PINA,Copy_u8ChannelId);
					break;
				case PORTB_ID:
					Add_pu8ChannelLevel=GET_BIT(PINB,Copy_u8ChannelId);
					break;
				case PORTC_ID:
					Add_pu8ChannelLevel=GET_BIT(PINC,Copy_u8ChannelId);
					break;
				case PORTD_ID:
					Add_pu8ChannelLevel=GET_BIT(PIND,Copy_u8ChannelId);
					break;
				}

			}

			return LOC_enuReturnStatus;

}
/* Description :
* Toggle  the Value level of the required channel pin.
* If the input ChannelId number or ChannelLevel are not correct , The function will not handle the request and will return Error .
* Function Paramters : Channel Id & Channel Level
* Function Return : Error Status of Dio Channel
*
*/
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId)
{
	/* Intialize variabla to save the number of pin */
			u8 LOC_u8PinNum = 0;
			/* Intialize variable to save the number of ports */
			u8 LOC_u8PortNum = 0;
			/* Intialize Variable to return the Dio Error status */
			Dio_tenuErrorStatus LOC_enuReturnStatus=Dio_enuOk;
			if(Copy_u8ChannelId>PORTD_PIN0_ID||Copy_u8ChannelId<PORTA_PIN0_ID)
			{
				/* Return Error of channel number*/
				LOC_enuReturnStatus=Dio_ChannelError;
			}

			/* switch case to know the port_id and pin_id */
			else{
				/* variable to save the pin number */
				u8 LOC_u8PinNum = Copy_u8ChannelId/NUM_OF_PINS_PER_PORT;
				/* variable to save the port number */
				u8 LOC_u8PortNum = Copy_u8ChannelId%NUM_OF_PINS_PER_PORT;
				switch(LOC_u8PortNum)
				{
				case PORTA_ID:
					TGL_BIT(PORTA,LOC_u8PinNum);
					break;
				case PORTB_ID:
					TGL_BIT(PORTA,LOC_u8PinNum);
					break;
				case PORTC_ID:
					TGL_BIT(PORTA,LOC_u8PinNum);
					break;
				case PORTD_ID:
					TGL_BIT(PORTA,LOC_u8PinNum);
					break;
				}

			}

			return LOC_enuReturnStatus;

}
/*
 * Description :
 * Write the Value level of the required PORT.
 * If the input PORTId number or ChannelLevel are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Port Id & Port Level
 * Function Return : Error Status of Dio Channel
 *
 */
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId,u8 Copy_u8PortLevel_Value)
{
	/* Intialize Variable to return the Dio Error status */
	Dio_tenuErrorStatus LOC_enuReturnStatus=Dio_enuOk;
	/* checking the validity of the number of port */
	if(Copy_u8PortId>NUM_OF_PORTS)
	{
		LOC_enuReturnStatus=Dio_ChannelError;
	}
	else
	{
		switch(Copy_u8PortId)
		{
		case PORTA_ID:
			   PORTA=Copy_u8PortLevel_Value;
			   break;
		case PORTB_ID:
				PORTA=Copy_u8PortLevel_Value;
				break;
		case PORTC_ID:
				PORTA=Copy_u8PortLevel_Value;
				break;
		case PORTD_ID:
				PORTA=Copy_u8PortLevel_Value;
				break;

		}
	}
	return LOC_enuReturnStatus;
}
/* Description :
* Read the Value level of the required PORT.
* If the input PORTlId number or The ChannelLevel pointer is equal NULL , The function will not handle the request and will return Error .
* Function Paramters : Port Id & Address of  Port Level
* Function Return : Error Status of Dio Channel
*
*/
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId,pu8 Add_pu8PortLevel)
{
	Dio_tenuErrorStatus LOC_enuReturnStatus=Dio_enuOk;

			/* Check for the validity of channel Id */
			if(Copy_u8PortId>NUM_OF_PORTS)
			{
				/* Return Error of channel number*/
				LOC_enuReturnStatus=Dio_ChannelError;
			}

			/* check the null pointer error */
			else if (Add_pu8PortLevel==NULL_PTR)
			{
				/* Return Error of NULL Pointer*/
				LOC_enuReturnStatus=Dio_PointerError;
			}
			else
			{
				switch(Copy_u8PortId)
				{
				case PORTA_ID:
					  Add_pu8PortLevel=PINA;
					   break;
				case PORTB_ID:
					  Add_pu8PortLevel=PINB;
						break;
				case PORTC_ID:
					  Add_pu8PortLevel=PINC;
						break;
				case PORTD_ID:
					  Add_pu8PortLevel=PIND;
						break;

				}
			}
			return LOC_enuReturnStatus;

}
