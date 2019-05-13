
#include "STD_Types.h"
#include "temp_sensor.h"


void adc_init(){
	volatile uint8 delay = 0;
	SYSCTL_RCGC0_R|=0x00010000; //enable the ADC0
	delay = delay +1;
	SYSCTL_RCGC0_R &= ~0x00000300;    //configre the sampling rate by the deafult value of 125k
	ADC0_SSPRI_R &= ~0xF000;           //set piriority of sequencer 3 as the highest
	ADC0_ACTSS_R &= ~0x8;				//disable sequencer 3 during configration
	ADC0_EMUX_R &= ~0xF000; 			//make sequencer 3 triggered
	ADC0_SSMUX3_R = 0x0;				//get input from channel 0
	ADC0_SSCTL3_R |= 0x0E;				//enable temprature measurement
	ADC0_ACTSS_R |= 0x8;				//enable ADC0 sequencer 3	
}	


uint8 temp_reading(void){
	uint8 ADC0_output = 0;
	uint8 temp_c = 0;
	ADC0_PSSI_R |= 0x8;
	while( (ADC0_RIS_R & 0x8)==0);
	ADC0_output = ADC0_SSFIFO3_R & 0xFFF;
	temp_c = 147.5 - ( (247.5*ADC0_output)/4096);
	return temp_c;
}	

