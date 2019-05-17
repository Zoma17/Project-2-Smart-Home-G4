#ifndef _LCD_H_
#define _LCD_H_


void LCD_Init();
void LCDcommand(uint8_t cmd);
void LCDdata(uint8_t data);
static void LCD_excute(uint8_t u8ValueCpy);
void UART_receiveString(uint8_t *Str);

#endif
