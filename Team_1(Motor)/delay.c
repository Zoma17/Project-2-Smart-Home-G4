#include "stdint.h"
#include "D:/3rd CSE/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "delay.h"
void SystemInit(){}

void delay1ms(void)
{
	NVIC_ST_RELOAD_R = 16000 - 1;
	while((NVIC_ST_CTRL_R) & ((0x00010000) != 1));
}