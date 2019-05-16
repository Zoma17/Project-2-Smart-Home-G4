#include "tm4c123gh6pm.h"
#include "UART.h"
#include "Pot_ADC.h"
#include "DIO.h"
#include "Delay.h"

void SW1_Init(void);
void SW2_Init(void);
unsigned char SW1_Input(void);
unsigned char SW2_Input(void);
void read_send2(void);

