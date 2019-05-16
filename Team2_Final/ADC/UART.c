#include "tm4c123gh6pm.h"
#include "stdint.h"

#define GPIO_PA10_M 0x03


void UART5_init (void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
	
	UART1_CTL_R &= ~UART_CTL_UARTEN;
	UART1_IBRD_R = 520;    
  UART1_FBRD_R = 53;
	UART1_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART1_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTB_AFSEL_R |= GPIO_PA10_M;
	GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	GPIO_PORTB_DEN_R |= GPIO_PA10_M;
}


void UART2_Write(char x){
	while((UART1_FR_R &0x20) !=0);
	UART1_DR_R = x;
}



uint8_t UART2_Read(void){
	while((UART1_FR_R&UART_FR_RXFE) != 0);
	return (uint8_t)(UART1_DR_R&0xFF);
}




/*char UART0_Read(_Bool waitUntilAvailable){
	char c;
	if(waitUntilAvailable)
	{
		while((UART5_FR_R & 0x10) != 0);  //wait until the buffer is not empty 
		c = UART5_DR_R; 								  //read the received data 

	}
	else if((UART5_FR_R & 0x10) != 0)
		c = UART5_DR_R;
	else
		c = '0'; //no data read
	
	return c;  //and return it 
}
*/

void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART2_Read();
	
	while(Str[i] != '#')
	{
		
		i++;
		Str[i] = UART2_Read();
	}
	Str[i] = '\0';
}





void UART0_Init(void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	
	UART0_CTL_R &= ~UART_CTL_UARTEN;
	UART0_IBRD_R = 520;    
  UART0_FBRD_R = 53;
	UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	GPIO_PORTA_DEN_R |= GPIO_PA10_M;
	GPIO_PORTA_AMSEL_R &= ~GPIO_PA10_M;
}


uint8_t UART0_Read(void){
	while((UART0_FR_R&UART_FR_RXFE) != 0);
	return (uint8_t)(UART0_DR_R&0xFF);
}
/*void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART0_Read();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART0_Read();
	}
	Str[i] = '\0';
}
*/

void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
void UART0_ReadString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART0_Read();
	while(Str[i] != '\r')
	{
		i++;
		Str[i] = UART0_Read();
	}
	Str[i] = '\0';
}

void UART0_WriteString(uint8_t ch[]){
	volatile int i=0;
    while(ch[i] != 0)
    {
        UART0_Write(ch[i]);
        i++;
     
    }
		
	}
		
		
		
/*void UART0_Interrupt_Init(){
	//U5RX is PE4 and U5TX is PE5
	//int delay = 0;
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	//delay--;
	//delay--;		
	UART0_CTL_R &= ~UART_CTL_UARTEN;
	UART0_IBRD_R = 520;    
  UART0_FBRD_R = 53;
	UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	
	UART0_IM_R |= 0x01 << 4;
	NVIC_EN0_R |= 0x01 << 5;
	
	UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	
	//GPIO_PORTE_DEN_R |= 0x30; //put PD4 and PD5 as digital i/o
	//GPIO_PORTE_AFSEL_R  |= 0x30; //set alternate function PD4 and PD5
	//GPIO_PORTE_PCTL_R |= 0x000110000; //set PD4 and PD5 alternate function as UART
	 					/* enable UART5, TXE, RXE */
	//UART5_IM_R |= 0x0010; 				/* enable RX interrupt */
	//NVIC_EN1_R |= 0x20;			//enable interrupt request number 77th in Enable register
//}



