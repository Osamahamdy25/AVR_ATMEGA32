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
	unsigned char i;
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);
	PORTA=0;
	while(1)
	{
		SET_BIT(PORTA,0);
		CLR_BIT(PORTA,1);
		CLR_BIT(PORTA,2);
		_delay_ms(500);
		SET_BIT(PORTA,1);
	    CLR_BIT(PORTA,0);
		CLR_BIT(PORTA,2);
		_delay_ms(500);
		SET_BIT(PORTA,2);
		CLR_BIT(PORTA,0);
		CLR_BIT(PORTA,1);
		_delay_ms(500);
	}

return 0;
}
