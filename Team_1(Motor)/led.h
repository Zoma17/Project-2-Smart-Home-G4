#ifndef __LED_H__
#define __LED_H__
#include "tm4c123gh6pm.h"
#include "STD_Types.h"

void led_Init() ;

void SetDutyCycle(uint8_t on_time) ;

#endif // __LED_H__