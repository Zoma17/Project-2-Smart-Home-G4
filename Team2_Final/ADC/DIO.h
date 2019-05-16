#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "stdint.h"
typedef enum
{
	
PORT_PIN_IN=0,
	
PORT_PIN_OUT

}Port_PinDirectionType;

typedef enum 
{
STD_LOW=0,
STD_HIGH

}Dio_LevelType;


#define PIN_0			0x01
#define PIN_1			0x02
#define PIN_2			0x04
#define PIN_3			0x08
#define PIN_4			0x10
#define PIN_5			0x20
#define PIN_6			0x40
#define PIN_7			0x80


#define GPIO_PORTA			0x01
#define GPIO_PORTB			0x02
#define GPIO_PORTC			0x04
#define GPIO_PORTD			0x08
#define GPIO_PORTE			0x10
#define GPIO_PORTF			0x20

void PortInit(uint8_t port_index );
void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, Port_PinDirectionType pins_direction);
void Port_SetPinPullUp(uint8_t port_index , uint8_t pins_mask , uint8_t enable);
void Port_SetPinPullDown ( uint8_t port_index , uint8_t pins_mask , uint8_t enable );
void DIO_WritePort(uint8_t port_index,uint8_t pins_mask, Dio_LevelType pins_level);
uint8_t DIO_ReadPort(uint8_t port_index,uint8_t pins_mask);
void DIO_FlipPort ( uint8_t port_index , uint8_t pins_mask );

#endif /* DIO_INT_H_ */