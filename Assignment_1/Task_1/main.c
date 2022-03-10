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
	signed char i;
	DDRA=0XFF; // all pins of port A are output
	CLR_BIT(DDRB,0);// pin 0 are input
	PORTA=0X00; 	//turn off all leds
	SET_BIT(PORTB,0); // for internal pull up

while(1)
{
if(GIT_BIT(PINB,0)==0)
{
	_delay_ms(300);
	for(i=0;i<=7;i++)
	{

		PORTA|=(1<<i);
		_delay_ms(200);
		PORTA=0X00;
	}

}
else{
	_delay_ms(300);
	for(i=7;i>=0;i--)
		{
			PORTA|=(1<<i);
			_delay_ms(200);
			PORTA=0X00;
		}
}

}

return 0;
}
