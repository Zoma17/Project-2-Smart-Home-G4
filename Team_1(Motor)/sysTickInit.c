#include "stdint.h"
#include "D:/3rd CSE/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "timerInit.h"

void SystemInit(){}
	
void sysTickInit(void)
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= 0x5;
}