/******************************************************************************
 *
 * Module: Port Driver
 *
 * File Name: port_prv.h
 *
 * Description: Header file for the AVR Port Driver
 *
 * Author: Osama Hamdy
 *
 *******************************************************************************/
#ifndef PORT_PRV_H_
#define PORT_PRV_H_
/**************************  PIN_NUMBERS ***************************************/
#define MAX_PINS_NUM 				31
/********************************************************************************/

/***************************************Function Prototype********************************/
/*
 * Description :
 * Setup the Initialzation  of the Mode of all the pins .
 * Function Paramters : No parameters required
 * Function Return : No return values
 */

void Port_VidInit(void);

/*****************************************************************************************/
#endif /* PORT_PRV_H_ */
