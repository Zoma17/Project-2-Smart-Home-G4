#ifndef __LED_H__
#define __LED_H__

#include "STD_Types.h"
#include "ARM_Tiva-C.h"

void led_Init() ;

void SetDutyCycle(uint8_t on_time) ;

#endif // __LED_H__