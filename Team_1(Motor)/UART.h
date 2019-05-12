#include "ARM_Tiva-C.h"
#include "STD_Types.h"

void UART0_Init(uint32 baudrate);

uint8 UART0_Available(void);

uint8 UART0_Read(void);

void init_UART_Read_Interrupt(void);

void UART0_Write(uint8 data);

void UART0_Handler(void);