/******************************************************************************
 *
 * Module: Port Driver
 *
 * File Name: port.h
 *
 * Description: Header file for the AVR Port Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/********************PIN Mode ******************************/
#define DEFAULT                          0
#define PIN_INPUT_HIGH_IMPEDENCE 		 0
#define PIN_INPUT_PULL_UP 				 1
#define PIN_OUTPUT_HIGH 				 2
#define PIN_OUTPUT_LOW	 				 3

/*********************PIN Direction *************************/
#define PIN_INPUT 			     0
#define PIN_OUTPUT				 1

/************* Port **************************/
#define NUM_OF_PORTS           		 4
#define NUM_OF_PINS_PER_PORT   		 8
#define PORTA_ID              		 0
#define PORTB_ID             	     1
#define PORTC_ID                     2
#define PORTD_ID                     3

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
		Port_enuPinError,
		Port_enuDirectionError,
		port_enuModeError,
		Port_enuOk
}Port_tenuErrorState;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Pin Number & Pin Direction
 * Function Return : Error Status of Port
 */
Port_tenuErrorState Port_enuSetpinDirection(u8 Copy_u8PinNum,u8 Copy_u8PinDirection);

/*
 * Description :
 * Setup the Mode of the required pin Pull_Up/High_Impedence.
 * If the input port number or pin number are not correct, The function will not handle the request and will return Error .
 * Function Paramters : Pin Number & Pin Mode
 * Function Return : Error Status of Port
 */
Port_tenuErrorState Port_enuSetpinMode(u8 Copy_u8PinNum,u8 Copy_u8PinMode);
#endif /* PORT_H_ */
