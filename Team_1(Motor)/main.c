#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "portInit.h"
#include "timerInit.h"
#include "delay.h"
void SystemInit(){}
	
void rotateCounterClockWise(void)
{
	int i,j=0;
	int temp [] = {0x9, 0x3, 0x6, 0xc};
	for(i=0;i<16;i++)
		{
			GPIO_PORTA_DATA_R = 0x0;
			GPIO_PORTA_DATA_R = temp[j];
			if(j==3)
				j=0;
			else
				j++;
			delay1ms();
		}
}


void rotateClockWise(void)
{
	int i,j=3;
	int temp [] = {0x9, 0x3, 0x6, 0xc};
	for(i=0;i<16;i++)
		{
			GPIO_PORTA_DATA_R = 0x0;
			GPIO_PORTA_DATA_R = temp[j];
			if(j==0)
				j=3;
			else
				j--;
			delay1ms();

		}
}

void rotate(char direction)
{
	switch (direction)
		{
			case 'R':
				rotateClockWise();
				break;
			case 'L':
				rotateCounterClockWise();
				break;
		}

}




