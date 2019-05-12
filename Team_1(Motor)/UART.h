#include "ARM_Tiva-C.h"
#include "STD_Types.h"
//#include "stdint.h"
//#include "tm4c123gh6pm.h"

void UART0_Init(uint32 baudrate);

uint8 UART0_Available(void);

uint8 UART0_Read(void);

void UART0_Write(uint8 data);
