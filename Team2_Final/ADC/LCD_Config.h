

#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_
#include "tm4c123gh6pm.h"
#include "Delay.h"

/* Port To put D0 -> D7 */

#define LCD_PORT									GPIO_PORTB

/* Port To put RS , RW , E */

#define LCD_CONTROL_PINS_PORT			GPIO_PORTA

/* Pins For RS , RW , E */

#define RS										PIN_2
#define RW										PIN_3
#define E											PIN_4





#endif