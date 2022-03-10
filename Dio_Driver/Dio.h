/******************************************************************************
 *
 * Module: DIO Driver
 *
 * File Name: Dio.h
 *
 * Description: Header file for the AVR DIO Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#include "Bit_utils.h"  /* To use the macros like SET_BIT */
#include "Std_types.h"   /* to use the AVR Data Types Like U8 */
#ifndef DIO_H_
#define DIO_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define STD_HIGH                         1
#define STD_LOW                          0
/********************* Port **************************************************/
#define NUM_OF_PORTS           		     4
#define NUM_OF_PINS_PER_PORT   		     8
#define PORTA_ID              		     0
#define PORTB_ID             	         1
#define PORTC_ID                         2
#define PORTD_ID                         3
/******************** PINS OF PORTA ***************************************/
#define PORTA_PIN0_ID   				 1
#define PORTA_PIN1_ID					 2
#define PORTA_PIN2_ID					 3
#define PORTA_PIN3_ID					 4
#define PORTA_PIN4_ID				     5
#define PORTA_PIN5_ID				 	 6
#define PORTA_PIN6_ID					 7
#define PORTA_PIN7_ID					 8
 /******************** PINS OF PORTB ***************************************/
#define PORTB_PIN0_ID    			     9
#define PORTB_PIN1_ID					10
#define PORTB_PIN2_ID					11
#define PORTB_PIN3_ID					12
#define PORTB_PIN4_ID					13
#define PORTB_PIN5_ID					14
#define PORTB_PIN6_ID					15
#define PORTB_PIN7_ID					16
 /******************** PINS OF PORTC ***************************************/
#define PORTC_PIN0_ID    				17
#define PORTC_PIN1_ID					18
#define PORTC_PIN2_ID					19
#define PORTC_PIN3_ID					20
#define PORTC_PIN4_ID					21
#define PORTC_PIN5_ID					22
#define PORTC_PIN6_ID				    23
#define PORTC_PIN7_ID					24
 /******************** PINS OF PORTD ***************************************/
#define PORTD_PIN0_ID    			    25
#define PORTD_PIN1_ID					26
#define PORTD_PIN2_ID			     	27
#define PORTD_PIN3_ID					28
#define PORTD_PIN4_ID				    29
#define PORTD_PIN5_ID					30
#define PORTD_PIN6_ID				    31
#define PORTD_PIN7_ID					32
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
		Dio_ChannelError,
		Dio_LevelError,
		Dio_PointerError,
		Dio_enuOk
}Dio_tenuErrorStatus;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * Write the Value level of the required channel pin.
 * If the input ChannelId number or ChannelLevel are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Channel Id & Channel Level
 * Function Return : Error Status of Dio Channel
 *
 */

Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId,u8 Copy_u8ChannelLevel);
/* Description :
* Read the Value level of the required channel pin.
* If the input ChannelId number or The ChannelLevel pointer is equal NULL , The function will not handle the request and will return Error .
* Function Paramters : Channel Id &Address of  Channel Level
* Function Return : Error Status of Dio Channel
*
*/

Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId,pu8 Add_pu8ChannelLevel);


/* Description :
* Toggle  the Value level of the required channel pin.
* If the input ChannelId number or ChannelLevel are not correct , The function will not handle the request and will return Error .
* Function Paramters : Channel Id & Channel Level
* Function Return : Error Status of Dio Channel
*
*/
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId);


/*
 * Description :
 * Write the Value level of the required PORT.
 * If the input PORTId number or ChannelLevel are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Port Id & Port Level
 * Function Return : Error Status of Dio Channel
 *
 */
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PORTId,u8 Copy_u8PortLevel_Value);
/* Description :
* Read the Value level of the required PORT.
* If the input PORTlId number or The ChannelLevel pointer is equal NULL , The function will not handle the request and will return Error .
* Function Paramters : Port Id & Address of  Port Level
* Function Return : Error Status of Dio Channel
*
*/
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId,pu8 Add_pu8PortLevel);

#endif /* DIO_H_ */
