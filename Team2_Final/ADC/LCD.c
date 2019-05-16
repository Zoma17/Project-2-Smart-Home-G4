
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_Config.h"
	
void LCD_Init()
{
	Delay_Ms(20);
	LCDcommand(0x30);
	Delay_Ms(1);
	LCDcommand(0x38);
	Delay_Ms(1);
	LCDcommand(0x08);
	Delay_Ms(1);
	LCDcommand(0x01);
	Delay_Ms(1);
	LCDcommand(0x06);
	Delay_Ms(1);
	LCDcommand(0x0C);
	Delay_Ms(1);
	
}
void LCDdata(uint8_t data){
	DIO_WritePort(LCD_CONTROL_PINS_PORT,RS,STD_HIGH);
	LCD_excute(data);
}
void LCDcommand(uint8_t cmd){
	DIO_WritePort(LCD_CONTROL_PINS_PORT,RS,STD_LOW);
	LCD_excute(cmd);
}

static void LCD_excute(uint8_t u8ValueCpy){

	/*set RW to low */
	DIO_WritePort(LCD_CONTROL_PINS_PORT,RW,STD_LOW);

	/* set received data to LCD data lines*/
	DIO_WritePort(LCD_PORT,u8ValueCpy,STD_HIGH);
	DIO_WritePort(LCD_PORT,~u8ValueCpy,STD_LOW);
	GPIO_PORTB_DATA_R = u8ValueCpy;

	/* set ENABLE high */
	DIO_WritePort(LCD_CONTROL_PINS_PORT,E,STD_HIGH);;
	/* Delay 1 ms */
	Delay_Ms(1);
	/*set Enable LOW */
	DIO_WritePort(LCD_CONTROL_PINS_PORT,E,STD_LOW);

}