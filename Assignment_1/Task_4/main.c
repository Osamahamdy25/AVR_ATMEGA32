/*
 * main.c
 *
 *  Created on: Mar 3, 2022
 *      Author: Osama Mohamed Hamdy
 */

#include <avr/io.h>
#include <util/delay.h>
#define  SET_BIT(REG,BIT) 	REG|=1<<BIT
#define  CLR_BIT(REG,BIT) 	REG&=~(1<<BIT)
#define  GIT_BIT(REG,BIT)	((REG>>BIT)&(1))


int main(void)
{
	/**************** Variable Initialzation ****************************/
	signed char i=0,temp=0,state = 0;
	/******************* Pin Initialization *****************************************/
	DDRA=0XFF; // all pins of port A are output
	CLR_BIT(DDRB,0);// pin 0 are input
	CLR_BIT(DDRB,1);// pin 1 are input
	CLR_BIT(DDRB,2);// pin 2 are input
	SET_BIT(DDRB,3);// pin 3 are output
	PORTA=0X00; 	//turn off all leds
	SET_BIT(PORTB,0); // for internal pull up
	SET_BIT(PORTB,1); // for internal pull up
	SET_BIT(PORTB,2); // for internal pull up
	while(1)
	{
		if(GIT_BIT(PINB,0)==0)
		{
			_delay_ms(200);
			state = 1 ;
		}

		if (state == 0)
		{
			if(GIT_BIT(PINB,1))
			{
				_delay_ms(300);

				SET_BIT(PORTA,i);
				i++;
				if(i>7)
				{
				SET_BIT(PORTB,3);
				_delay_ms(500);
				CLR_BIT(PORTB,3);
				i=7;
				}
			}

			else if (GIT_BIT(PINB,2))
			{
				_delay_ms(200);
				i--;
				CLR_BIT(PORTA,i);
				if(i<0)
				{
					SET_BIT(PORTB,3);
					_delay_ms(500);
					CLR_BIT(PORTB,3);
					i=0;
				}
				}

		}

		else
		{
			temp = PORTA;

			while (state == 1 )
			{
 			PORTA=0;
		   _delay_ms(500);
		   PORTA=temp;
		  _delay_ms(500);
		  if(GIT_BIT(PINB,0)==0)
		  		{
		  			_delay_ms(200);
		  			state = 0 ;
		  		}
			}


		}
	}




	return 0;
}
