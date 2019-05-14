#include "stdint.h"
#include "D:/3rd CSE/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "portInit.h"
#include "timerInit.h"
#include "delay.h"
void SystemInit(){}
	



void rorateClockWise(void)
{
	int i;
	for(i=0;i<4;i++)
		{
			GPIO_PORTA_DATA_R |= 1 << i;
			delay1ms();
		}
}


void rorateCounterClockWise(void)
{
	int i;
	for(i=3;i>=0;i--)
		{
			GPIO_PORTA_DATA_R |= 1 << i;
			delay1ms();
		}
}

void rotate(char direction)
{
	switch (direction)
		{
			case '1': 
				rorateClockWise();
				break;
			case '0':
				rorateCounterClockWise();
				break;
		}
		
}