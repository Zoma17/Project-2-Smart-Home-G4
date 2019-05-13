#pragma once

#include "STD_Types.h"

#define SETBIT(REG,BIT)         ((REG)|= 1<<(BIT))
#define CLRBIT(REG,BIT)         ((REG)&= ~(1<<(BIT)))
#define TOGGLEBIT(REG,BIT)      ((REG)^= 1<<(BIT))

// THIS FILE IS NOT COMPLETED YET, ONLY NECESSARY CODES FOR THE COUNTER PROJECT ARE WRITTEN ; IT SHOULD BE VERY HUGE IN A WHILE



typedef struct
{
    // here is what i don't understand , in all drivers they made the DATA register starts in offser 0x3FC instead of 0x000
    // in other words , an unused reserved memory of [255] uint32 type is used before the DATA register

     uint32 reserved_donotuse[255];

    volatile uint32 DATA;
    volatile uint32 DIR;
    volatile uint32 IS; 
    volatile uint32 IBE;
    volatile uint32 IEV;
    volatile uint32 IM;
    volatile uint32 RIS; 
    volatile uint32 MIS;
    volatile uint32 ICR;
    volatile uint32 AFSEL;
    //     
    uint32 reserved_donotuse1[55];
    //

    volatile uint32 DR2R;
    volatile uint32 DR4R;
    volatile uint32 DR8R;
    volatile uint32 ODR;
    volatile uint32 PUR;
    volatile uint32 PDR;
    volatile uint32 SLR;
    volatile uint32 DEN;
    volatile uint32 LOCK;
    volatile uint32 OCR;
    volatile uint32 AMSEL;
    volatile uint32 PCTL;
    volatile uint32 ADCCTL;
    volatile uint32 DMACTL;
    //    
    uint32 reserved_donotuse2[679];
    //

    volatile uint32 PeriphID4;
    volatile uint32 PeriphID5;
    volatile uint32 PeriphID6;
    volatile uint32 PeriphID7;
    volatile uint32 PeriphID0;        
    volatile uint32 PeriphID1;
    volatile uint32 PeriphID2;
    volatile uint32 PeriphID3;
    volatile uint32 PCellID0;
    volatile uint32 PCellID1;
    volatile uint32 PCellID2;
    volatile uint32 PCellID3;

}GPIO_Type;

typedef struct {

volatile uint32 DATA;
volatile uint32 RS_EC;
 //     
    uint32 reserved_donotuse1[4];
 //
volatile uint32 FLAG;
//
uint32 reserved_donotuse2;
//
volatile uint32 ILP;
volatile uint32 IBRD;
volatile uint32 FBRD;
volatile uint32 LCRH;
volatile uint32 CTL;
volatile uint32 IFLS;
volatile uint32 IM;
volatile uint32 RIS;
volatile uint32 MIS;
volatile uint32 ICR;
volatile uint32 DMACTL;
//     
    uint32 reserved_donotuse3[52];
//
volatile uint32 UART9BITADDR;
volatile uint32 UART9BITAMASK;
volatile uint32 PP;
volatile uint32 CC;
volatile uint32 PeriphID4;
volatile uint32 PeriphID5;
volatile uint32 PeriphID6;
volatile uint32 PeriphID7;
volatile uint32 PeriphID0;
volatile uint32 PeriphID1;
volatile uint32 PeriphID2;
volatile uint32 PeriphID3;
volatile uint32 PCellID0;
volatile uint32 PCellID1;
volatile uint32 PCellID2;
volatile uint32 PCellID3;

}UART_Type;

/*=====   PORTS  ====*/

 // Default is APB Arpeture 

#define PORT_A      		(((volatile GPIO_Type * ) 0x40004000))
#define PORT_B      		(((volatile GPIO_Type * ) 0x40005000))
#define PORT_C      		(((volatile GPIO_Type * ) 0x40006000))
#define PORT_D      		(((volatile GPIO_Type * ) 0x40007000))
#define PORT_E      		(((volatile GPIO_Type * ) 0x40024000))
#define PORT_F      		(((volatile GPIO_Type * ) 0x40025000))


#define PORT_AHB_A      (((volatile GPIO_Type * ) 0x40058000))
#define PORT_AHB_B      (((volatile GPIO_Type * ) 0x40059000))
#define PORT_AHB_C      (((volatile GPIO_Type * ) 0x4005A000))
#define PORT_AHB_D      (((volatile GPIO_Type * ) 0x4005B000))
#define PORT_AHB_E      (((volatile GPIO_Type * ) 0x4005C000))
#define PORT_AHB_F      (((volatile GPIO_Type * ) 0x4005D000))


/* =============================*/



/*==========  SYSTEM CONTROL REGISTERS  ============*/
#define GPIOHBCTL        (*((volatile uint32 *)0x400FE06C)) //to choose wether APB or AHB, 0 for APB which is the default
#define RCGCGPIO         (*((volatile uint32 *)0x400FE608)) //to enable the clock for the ports , default is 0 to be disabled; 1 to enable
#define RCGCUART         (*((volatile uint32 *)0x400FE618)) //to enable the UARTs clock
#define RCGCADC          (*((volatile unsigned long *)0x400FE638))
#define SYSCTL_RCGC0_R   (*((volatile unsigned long *)0x400FE100)) //to enable the ADC0
#define SYSCTL_RCGCPWM_R        (*((volatile unsigned long *)0x400FE640))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_RCC_R            (*((volatile unsigned long *)0x400FE060))

/* ============ UART REGISTERS ========== */

#define UART0  (((volatile UART_Type * ) 0x4000C000))
#define UART1  (((volatile UART_Type * ) 0x4000D000))
#define UART2  (((volatile UART_Type * ) 0x4000E000))
#define UART3  (((volatile UART_Type * ) 0x4000F000))
#define UART4  (((volatile UART_Type * ) 0x40010000))
#define UART5  (((volatile UART_Type * ) 0x40011000))
#define UART6  (((volatile UART_Type * ) 0x40012000))
#define UART7  (((volatile UART_Type * ) 0x40013000))


/* ============ ADC0 REGISTERS ========== */
#define ADC0_SSPRI_R            (*((volatile unsigned long *)0x40038020))
#define ADC0_ACTSS_R            (*((volatile unsigned long *)0x40038000))
#define ADC0_EMUX_R             (*((volatile unsigned long *)0x40038014))
#define ADC0_SSMUX3_R           (*((volatile unsigned long *)0x400380A0))
#define ADC0_SSCTL3_R           (*((volatile unsigned long *)0x400380A4))	
#define ADC0_ISC_R              (*((volatile unsigned long *)0x4003800C))
#define ADC0_PSSI_R             (*((volatile unsigned long *)0x40038028))
#define ADC0_RIS_R              (*((volatile unsigned long *)0x40038004))
#define ADC0_SSFIFO3_R          (*((volatile unsigned long *)0x400380A8))	

/*==========PWM registers=========*/
#define PWM1_3_CTL_R            (*((volatile unsigned long *)0x40029100))
#define PWM1_3_CMPA_R           (*((volatile unsigned long *)0x40029118))
#define PWM1_3_CMPB_R           (*((volatile unsigned long *)0x4002911C))
#define PWM1_3_GENA_R           (*((volatile unsigned long *)0x40029120))
#define PWM1_3_LOAD_R           (*((volatile unsigned long *)0x40029110))
#define PWM1_ENABLE_R           (*((volatile unsigned long *)0x40029008))

