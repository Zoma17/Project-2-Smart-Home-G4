#include "led.h"

// pre conditions : port F pin 2 should be connected with the led 

void led_Init()
{
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; 
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; 
	PWM1_3_LOAD_R = 1250 - 1; 
	PWM1_3_CMPA_R = 1248; 
	PWM1_3_CTL_R = PWM_0_CTL_ENABLE;	
	GPIO_PORTF_AFSEL_R |= 0x04;
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R& 0xFFFFF0FF) | (GPIO_PCTL_PF2_M1PWM6);
	GPIO_PORTF_DIR_R |= 0x04;
	GPIO_PORTF_DEN_R |= 0x04;
	PWM1_ENABLE_R = PWM_ENABLE_PWM6EN; 
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