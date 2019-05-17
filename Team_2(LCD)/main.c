#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "DIO.h"
#include "LCD.h"
#include "Delay.h"
#include "UART.h"
#include "Pot_ADC.h"
#include "Switch.h"
//#include "PORT.h"
#include "STD_Types.h"
#include "ARM_Tiva-C.h" 
void led_Init()
{
	SYSCTL_RCGCPWM_R |= 0x00000002;	
	SYSCTL_RCGCGPIO_R |= 0x00000020;	
	SYSCTL_RCC_R |= 0x00100000;	
	SYSCTL_RCC_R |= 0x000A0000;	
	PWM1_3_CTL_R = 0x00000000;	
	PWM1_3_GENA_R = 0x0000008C; 	
	PWM1_3_LOAD_R = 1250 - 1; 	
	PWM1_3_CMPA_R = 1248; 	PWM1_3_CTL_R = 
	0x00000001;	PORT_F->AFSEL |= 0x04;	
	PORT_F->PCTL = ( PORT_F->PCTL & 
	0xFFFFF0FF) | (0x00000500);	PORT_F->DIR |= 
	0x04;	PORT_F->DEN |= 0x04;	PWM1_ENABLE_R = 0x00000040;
	} 
	//pre condition : on_time is value from 0 to 10 to control led intensity

void SetDutyCycle(char on_time)
{
	if(on_time == 10)
	{	
		PWM1_3_CMPA_R = 1;	
		}
		 else if(on_time == 0)
		  {	
		  	PWM1_3_CMPA_R = 1248;	
		  	}
		  	else 
		  	{		int x = 1250*on_time/10;		PWM1_3_CMPA_R = (uint16)(1250 - x - 1);	
		  	}
		  
	} 
	void SystemInit(void)
	{		
	PortInit(GPIO_PORTA);	
	PortInit(GPIO_PORTB);
	PortInit(GPIO_PORTE);	
	Port_SetPinDirection(GPIO_PORTB,0xFF,PORT_PIN_OUT);	
	Port_SetPinDirection(GPIO_PORTA,0x1C,PORT_PIN_OUT);	
	Port_SetPinDirection(GPIO_PORTE,0x0E,PORT_PIN_IN);	
	Port_SetPinPullUp (GPIO_PORTB,0xFF,STD_HIGH);	
	Port_SetPinPullUp	(GPIO_PORTA,0x1C,STD_HIGH);	
	Port_SetPinPullUp (GPIO_PORTE,0x0E,STD_HIGH);	
	PLL_Init();	
	Init_ADC();	
	SW1_Init();	
	SW2_Init();	
	led_Init();	
	UART5_init();	
	UART0_Init();	
	LCD_Init();	
	}	
	


int main(void)
{	
uint8_t x;
uint8_t in,in2;	
uint8_t instr[50];	
uint8_t out;		
//PLL_Init();			
//UART0_WriteString("Write ON GREEN or ON RED or ON BLUE : \n");	

while(1)		
{				
char Pot_sample = SendSample();		
char Last_pot_sample;		
UART0_Write(Pot_sample);			
UART2_Write(Pot_sample-'0');			
//SetDutyCycle(Pot_sample%10);		
if(Pot_sample != Last_pot_sample)			
{				
//SetDutyCycle(Pot_sample%10);				
UART0_Write(Pot_sample);				
//this send the state of Switches				
UART2_Write(Pot_sample-'0');				
Last_pot_sample = Pot_sample;			
} 		
read_send2();						
/*				
UART_receiveString(instr);	
LCDcommand(0x01);		
Delay_Ms(5);		
LCDdata('T');		
LCDdata('e');		
LCDdata('m');		
LCDdata('p');		
LCDdata('e');		
LCDdata('r');		
LCDdata('a');		
LCDdata('t');		
LCDdata('u');		
LCDdata('r');		
LCDdata('e');		
LCDdata('=');		
LCDdata(' ');		
LCDdata(instr[0]); 		
LCDdata(instr[1]);		*/	
}
}

