#ifndef __UART_H__
#define	__UART_H__

#include "stdint.h"

void UART5_init(void);
void UART0_Init(void);
uint8_t UART0_Read(void);
void UART2_Write(uint8_t data);
uint8_t UART2_Read(void);
void UART0_ReadString(uint8_t *Str);
void UART0_Write(uint8_t data);
void UART0_WriteString(uint8_t ch[]);
void UART0_Interrupt_Init();
#endif // __UART_H__
