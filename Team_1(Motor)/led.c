#include "led.h"

// pre conditions : port F pin 2 should be connected with the led 

void led_Init()
{
	SYSCTL_RCGCPWM_R |= 0x00000002;
	SYSCTL_RCGCGPIO_R |= 0x00000020;
	SYSCTL_RCC_R |= 0x00100000;
	SYSCTL_RCC_R |= 0x000A0000;
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; 
	PWM1_3_LOAD_R = 1250 - 1; 
	PWM1_3_CMPA_R = 1248; 
	PWM1_3_CTL_R = 0x00000001;
	PORT_F->AFSEL |= 0x04;
	PORT_F->PCTL = ( PORT_F->PCTL & 0xFFFFF0FF) | (0x00000500);
	PORT_F->DIR |= 0x04;
	PORT_F->DEN |= 0x04;
	PWM1_ENABLE_R = 0x00000040;
}


//pre condition : on_time is value from 0 to 10 to control led intensity
void SetDutyCycle(uint8_t on_time){
	if(on_time == 10){
		PWM1_3_CMPA_R = 1;
	} else if(on_time == 0) {
		PWM1_3_CMPA_R = 1248;
	}else {
		PWM1_3_CMPA_R = (uint16_t)(1250 * (1 - ((on_time*10) / 100.0)) - 1);
	}
}