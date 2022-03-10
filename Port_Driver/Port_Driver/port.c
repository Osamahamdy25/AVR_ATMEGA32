/******************************************************************************
 *
 * Module: Port Driver
 *
 * File Name: port.c
 *
 * Description: Source  file for the AVR Port Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#include "Bit_utils.h"                     /* To use the macros like SET_BIT */
#include"Std_types.h"  /* to use the AVR Data Types Like U8 */
#include "port.h"
#include "avr/io.h"                        /* To use the IO Ports Registers */
#include "Port_prv.h"  /*  to notify number of pins*/
#include "Port_cfg.h"  /* to modify the user configuration */

/*******************************************************************************
 *                              Functions Defintions                         *
 *******************************************************************************/

/*
 * Description :
 * Setup the Initialzation  of the Mode of all the pins .
 * Function Paramters : No parameters required
 * Function Return : No return values
 */
void Port_VidInit(void)
{


	/************* Concatenation  **************************/
	#define conc(b0,b1,b2,b3,b4,b5,b6,b7)              help(b0,b1,b2,b3,b4,b5,b6,b7)
	#define help help(b0,b1,b2,b3,b4,b5,b6,b7)         0b##b0##b1##b2##b3##b4##b5##b6##b7

	/**********  Initialzation of Direction Register ******************/
#undef  DEFAULT
#undef  PIN_INPUT_HIGH_IMPEDENCE
#undef  PIN_INPUT_PULL_UP
#undef  PIN_OUTPUT_HIGH
#undef  PIN_OUTPUT_LOW
#define DEFAULT                          0
#define PIN_INPUT_HIGH_IMPEDENCE 		 0
#define PIN_INPUT_PULL_UP 				 1
#define PIN_OUTPUT_HIGH 				 1
#define PIN_OUTPUT_LOW	 				 0

DDRA=conc(PORTA_PIN0_MODE,PORTA_PIN1_MODE,PORTA_PIN2_MODE,PORTA_PIN3_MODE,PORTA_PIN4_MODE,PORTA_PIN5_MODE,PORTA_PIN6_MODE,PORTA_PIN7_MODE);

DDRB=conc(PORTB_PIN0_MODE,PORTB_PIN1_MODE,PORTB_PIN2_MODE,PORTB_PIN3_MODE,PORTB_PIN4_MODE,PORTB_PIN5_MODE,PORTB_PIN6_MODE,PORTB_PIN7_MODE);

DDRC=conc(PORTC_PIN0_MODE,PORTC_PIN1_MODE,PORTC_PIN2_MODE,PORTC_PIN3_MODE,PORTC_PIN4_MODE,PORTC_PIN5_MODE,PORTC_PIN6_MODE,PORTC_PIN7_MODE);

DDRD=conc(PORTD_PIN0_MODE,PORTD_PIN1_MODE,PORTD_PIN2_MODE,PORTD_PIN3_MODE,PORTD_PIN4_MODE,PORTD_PIN5_MODE,PORTD_PIN6_MODE,PORTD_PIN7_MODE);

/**********  Initialzation of Port Register ******************/
#undef  DEFAULT
#undef  PIN_INPUT_HIGH_IMPEDENCE
#undef  PIN_INPUT_PULL_UP
#undef  PIN_OUTPUT_HIGH
#undef  PIN_OUTPUT_LOW
#define DEFAULT                          1
#define PIN_INPUT_HIGH_IMPEDENCE 		 0
#define PIN_INPUT_PULL_UP 				 1
#define PIN_OUTPUT_HIGH 				 1
#define PIN_OUTPUT_LOW	 				 0

PORTA=conc(PORTA_PIN0_MODE,PORTA_PIN1_MODE,PORTA_PIN2_MODE,PORTA_PIN3_MODE,PORTA_PIN4_MODE,PORTA_PIN5_MODE,PORTA_PIN6_MODE,PORTA_PIN7_MODE);

PORTB=conc(PORTB_PIN0_MODE,PORTB_PIN1_MODE,PORTB_PIN2_MODE,PORTB_PIN3_MODE,PORTB_PIN4_MODE,PORTB_PIN5_MODE,PORTB_PIN6_MODE,PORTB_PIN7_MODE);

PORTC=conc(PORTC_PIN0_MODE,PORTC_PIN1_MODE,PORTC_PIN2_MODE,PORTC_PIN3_MODE,PORTC_PIN4_MODE,PORTC_PIN5_MODE,PORTC_PIN6_MODE,PORTC_PIN7_MODE);

PORTD=conc(PORTD_PIN0_MODE,PORTD_PIN1_MODE,PORTD_PIN2_MODE,PORTD_PIN3_MODE,PORTD_PIN4_MODE,PORTD_PIN5_MODE,PORTD_PIN6_MODE,PORTD_PIN7_MODE);

}
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Pin Number & Pin Direction
 * Function Return : Error Status of Port
 */
Port_tenuErrorState Port_enuSetpinDirection(u8 Copy_u8PinNum,u8 Copy_u8PinDirection)
{

	/* Intialize variabla to save the number of pin */
	u8 LOC_u8PinNum = 0;
	/* Intialize variable to save the number of ports */
	u8 LOC_u8PortNum = 0;
	/* Intialize Variable to return the port status */
	Port_tenuErrorState LOC_enuReturnStatus=Port_enuOk;

	/* check the pin number is not within the range return pin error  */
	if(Copy_u8PinNum > MAX_PINS_NUM)
	{
		LOC_enuReturnStatus = Port_enuPinError;
	}
	/* check the pin Direction number is not within the range return pin Direction error  */
	else if(Copy_u8PinDirection > PIN_OUTPUT)
	{
			LOC_enuReturnStatus =Port_enuDirectionError;
	}
	else
	{
		/* variable to get the value of pin number */
		LOC_u8PinNum  = Copy_u8PinNum%8;
		/* variable to get the value of port number */
		LOC_u8PortNum = Copy_u8PinNum/8;
		switch (LOC_u8PortNum)
		{
		case PORTA_ID:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8PinNum);
			}
			else {
				CLR_BIT(DDRA,Copy_u8PinNum);
			}
			break;

		case PORTB_ID:

			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNum);
			}
			else {

				CLR_BIT(DDRB,Copy_u8PinNum);

			}
			break;
		case PORTD_ID:

				if(Copy_u8PinDirection==PIN_OUTPUT)
				{
					SET_BIT(DDRD,Copy_u8PinNum);
				}
				else {

					CLR_BIT(DDRD,Copy_u8PinNum);

				}
				break;
		case PORTC_ID:

						if(Copy_u8PinDirection==PIN_OUTPUT)
						{
							SET_BIT(DDRC,Copy_u8PinNum);
						}
						else {

							CLR_BIT(DDRC,Copy_u8PinNum);

						}
						break;

	}

}

	return LOC_enuReturnStatus;
}



/*
 * Description :
 * Setup the Mode of the required pin Pull_Up/High_Impedence.
 * If the input port number or pin number are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Pin Number & Pin Mode
 * Function Return : Error Status of Port
 */
Port_tenuErrorState Port_enuSetpinMode(u8 Copy_u8PinNum,u8 Copy_u8PinMode)
{

	/* Intialize variabla to save the number of pin */
	u8 LOC_u8PinNum = 0;
	/* Intialize variable to save the number of ports */
	u8 LOC_u8PortNum = 0;
	/* Intialize Variable to return the port status */
	Port_tenuErrorState LOC_enuReturnStatus;

	if(Copy_u8PinNum > MAX_PINS_NUM)
	{
		LOC_enuReturnStatus = Port_enuOk;
	}
	else if(Copy_u8PinMode >PIN_OUTPUT)
	{
			LOC_enuReturnStatus =port_enuModeError;
	}
	else
	{
		LOC_u8PinNum  = Copy_u8PinNum%8;
		LOC_u8PortNum = Copy_u8PinNum/8;
		switch (LOC_u8PortNum)
		{

		case PORTA_ID:
 	 	 if (Copy_u8PinMode== PIN_INPUT_HIGH_IMPEDENCE)
 	 	 {
 	 		 CLR_BIT(DDRA,LOC_u8PinNum);
 	 		 CLR_BIT(PORTA,LOC_u8PinNum);
 	 	 }
 	 	 else if (Copy_u8PinMode==PIN_INPUT_PULL_UP)
 	 	 {
 	 		 CLR_BIT(DDRA,LOC_u8PinNum);
 	 		 SET_BIT(PORTA,LOC_u8PinNum);
 	 	 }
 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_HIGH)
 	 	 {
 	 		 SET_BIT(DDRA,LOC_u8PinNum);
 	 		 SET_BIT(PORTA,LOC_u8PinNum);
 	 	 }
 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_LOW)
		 {
			 SET_BIT(DDRA,LOC_u8PinNum);
			 CLR_BIT(PORTA,LOC_u8PinNum);
		 }

 	 	 break;
		case PORTB_ID:
		 	 	 if (Copy_u8PinMode== PIN_INPUT_HIGH_IMPEDENCE)
		 	 	 {
		 	 		 CLR_BIT(DDRB,LOC_u8PinNum);
		 	 		 CLR_BIT(PORTB,LOC_u8PinNum);
		 	 	 }
		 	 	 else if (Copy_u8PinMode==PIN_INPUT_PULL_UP)
		 	 	 {
		 	 		 CLR_BIT(DDRB,LOC_u8PinNum);
		 	 		 SET_BIT(PORTB,LOC_u8PinNum);
		 	 	 }
		 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_HIGH)
		 	 	 {
		 	 		 SET_BIT(DDRB,LOC_u8PinNum);
		 	 		 SET_BIT(PORTB,LOC_u8PinNum);
		 	 	 }
		 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_LOW)
				 {
					 SET_BIT(DDRB,LOC_u8PinNum);
					 CLR_BIT(PORTB,LOC_u8PinNum);
				 }

		 	 	 break;
		case PORTC_ID:
		 	 	 if (Copy_u8PinMode== PIN_INPUT_HIGH_IMPEDENCE)
		 	 	 {
		 	 		 CLR_BIT(DDRC,LOC_u8PinNum);
		 	 		 CLR_BIT(PORTC,LOC_u8PinNum);
		 	 	 }
		 	 	 else if (Copy_u8PinMode==PIN_INPUT_PULL_UP)
		 	 	 {
		 	 		 CLR_BIT(DDRC,LOC_u8PinNum);
		 	 		 SET_BIT(PORTC,LOC_u8PinNum);
		 	 	 }
		 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_HIGH)
		 	 	 {
		 	 		 SET_BIT(DDRC,LOC_u8PinNum);
		 	 		 SET_BIT(PORTC,LOC_u8PinNum);
		 	 	 }
		 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_LOW)
				 {
					 SET_BIT(DDRC,LOC_u8PinNum);
					 CLR_BIT(PORTC,LOC_u8PinNum);
				 }

		 	 	 break;
		case PORTD_ID:
		 	 	 if (Copy_u8PinMode== PIN_INPUT_HIGH_IMPEDENCE)
		 	 	 {
		 	 		 CLR_BIT(DDRD,LOC_u8PinNum);
		 	 		 CLR_BIT(PORTD,LOC_u8PinNum);
		 	 	 }
		 	 	 else if (Copy_u8PinMode==PIN_INPUT_PULL_UP)
		 	 	 {
		 	 		 CLR_BIT(DDRD,LOC_u8PinNum);
		 	 		 SET_BIT(PORTD,LOC_u8PinNum);
		 	 	 }
		 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_HIGH)
		 	 	 {
		 	 		 SET_BIT(DDRD,LOC_u8PinNum);
		 	 		 SET_BIT(PORTD,LOC_u8PinNum);
		 	 	 }
		 	 	 else if(Copy_u8PinMode==PIN_OUTPUT_LOW)
				 {
					 SET_BIT(DDRD,LOC_u8PinNum);
					 CLR_BIT(PORTD,LOC_u8PinNum);
				 }

		 	 	 break;



		}

	}
	return LOC_enuReturnStatus;

}



