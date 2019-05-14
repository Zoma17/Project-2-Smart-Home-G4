
#include "STD_Types.h"
#include "temp_sensor.h"


void adc_init(){
	volatile uint8 delay = 0;
	SYSCTL_RCGCADC_R|= 0x00000001; //enable the ADC0 clock
	SYSCTL_RCGCGPIO_R |= 0x00000010;
	delay = delay +1;
	ADC0_SSPRI_R |= 0x00000123;
	ADC0_SSPRI_R &= 0x1111CDE1;
	ADC0_ACTSS_R &= 0x11111110;
	ADC0_EMUX_R &= 0x11110111;
	ADC0_EMUX_R |= 0x0000F000;
	ADC0_SSMUX3_R &= 0x11111110;
	ADC0_SSCTL3_R |= 0x00000006;
	ADC0_ACTSS_R |= 0x00000008;
	PORT_E->DIR &= 0x11111117;
	PORT_E->AFSEL |= 0x00000008;
	PORT_E->DEN &= 0x11111117;
	PORT_E->AMSEL |= 0x00000008;
}	


uint8 temp_reading(void){
	uint8 ADC0_output = 0;
	uint8 temp_c = 0;
	ADC0_PSSI_R |= 0x8;
	while( (ADC0_RIS_R & 0x8)!= 0x8);
	ADC0_output = ADC0_SSFIFO3_R & 0xFFF;
	temp_c = 147.5 - ( (247.5*ADC0_output)/4096);
	return temp_c;
}	