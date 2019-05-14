#include "stdint.h"
#include "D:/3rd CSE/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "portInit.h"
void SystemInit(){}
	
void portAInit(void)
{
	int dummy;
	SYSCTL_RCGCGPIO_R |= 0x01;
	dummy = 1;
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0x0f;
	GPIO_PORTA_DIR_R &= 0xf0;
	GPIO_PORTA_AFSEL_R &= 0xf0;
	GPIO_PORTA_DEN_R |= 0x0f;
}