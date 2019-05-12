#include "UART.h"

void UART0_Init(uint32 baudrate){
    SETBIT(RCGCUART,0);          //Enable UART0
    SETBIT(RCGCGPIO,0);       //Give Clock to PORT_A
    float64 x;
		x= 16000000.0/(16.0*(float64)baudrate);  //Baud Rate Equation
    PORT_A->LOCK = 0x4C4F434B;       //unlock Port_A to use OCR reg
    PORT_A->OCR    |=0x03;           // allow changes in AFSEL,DEN...
    PORT_A->AFSEL  |=0x3;            // Choose alternative function option in Port_A (UART0 Option)
    PORT_A->DEN    |=0x3;       
    PORT_A->PCTL   =(1 | (1<<4));      // UART0 configuration for PORT_A Pin 0 and 1
    CLRBIT(UART0->CTL,0);              //disable UART0
    UART0->IBRD =(uint32)x;            // INTEGR BAUD RATE 
    x-=(uint64)x;                   //TAKES THE FRACTION ONLY
    UART0->FBRD =(uint16) (x*64 + 0.5);       //Float Baud rate
    UART0->LCRH |=0x00000070;       // LENGTH OF THE SENT WORD IS 8 BIT ,Enable FIFOs
    CLRBIT(UART0->LCRH,3);           // 1 stop bit
    // SETBIT(UART0->CTL,0);
    // SETBIT(UART0->CTL,8);
    // SETBIT(UART0->CTL,9);
    UART0->CC=0x0;                      // Clock source is the default (BRD Equation)
    UART0->CTL |= 0x00000301;         // enable UART0 Receiving and transmitting



}


uint8 UART0_Available(void){
	return ((UART0-> FLAG & 0x00000010) == 0x00000010) ? 0 : 1;
}

uint8 UART0_Read(void){
	while(UART0_Available() != 1);
	return (uint8)(UART0->DATA & 0xFF);
}

void UART0_Write(uint8 data){
	while((UART0-> FLAG & 0x00000020) != 0);
	UART0->DATA = data;
}
