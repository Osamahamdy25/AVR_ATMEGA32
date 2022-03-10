/*
 * main.c
 *
 *  Created on: Mar 2, 2022
 *      Author: Osama Mohamed Hamdy
 */


#include <avr/io.h>
#include <util/delay.h>
#define  SET_BIT(REG,BIT) 	REG|=1<<BIT
#define  CLR_BIT(REG,BIT) 	REG&=~(1<<BIT)
#define  GIT_BIT(REG,BIT)	((REG>>BIT)&(1))


int main(void)
{
	unsigned char i,flag=0;
	DDRA=0XFF; // all pins of port A are output
	CLR_BIT(DDRB,0);// pin 0 are input
	PORTA=0X00; 	//turn off all leds
	SET_BIT(PORTB,0); // for internal pull up
	while(1)
	{

				for(i=0;i<8;i++)
				{
					if(flag == 0)
					{
					if(GIT_BIT(PINB,0)==0)
					{
						_delay_ms(20);
						if(GIT_BIT(PINB,0)==0)
						{
						PORTA=0;
						flag=1;
						while(flag==1)
						{
							PORTA=0;
						    flag=1;
						    _delay_ms(200);
							if(GIT_BIT(PINB,0)==0)
							{
								_delay_ms(20);
								if(GIT_BIT(PINB,0)==0)
								{
								flag=0;
								}
							}
						}
						}
					}
					PORTA|=1<<i;
					_delay_ms(100);
					PORTA=0;
					_delay_ms(50);

					}

				}
		}


	return 0;
	}
