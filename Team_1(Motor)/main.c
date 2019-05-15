#include "stdint.h"
#include "D:/3rd CSE/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "portInit.h"
#include "timerInit.h"
#include "delay.h"
void SystemInit(){}
	
void rotateCounterClockWise(void)
{
	int i,j=5;
	for(i=0;i<16;i++)
		{
			GPIO_PORTA_DATA_R |= 1 << j;
			if(j==2)
				j=5;
			else
				j--;
			delay1ms();
		}
}


void rotateClockWise(void)
{
	int i,j=2;
	for(i=0;i<16;i++)
		{
			
			GPIO_PORTA_DATA_R |= 1 << j;
			delay1ms();
			if(j==5)
				j=2;
			else
				j++;
		}
}

void rotate(char direction)
{
	switch (direction)
		{
			case '1':
				rotateClockWise();
				break;
			case '0':
				rotateCounterClockWise();
				break;
		}

}