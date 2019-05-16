
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"
#define GPIO_PCTL_PORTA  (GPIO_PCTL_PA7_M | GPIO_PCTL_PA6_M | GPIO_PCTL_PA5_M | GPIO_PCTL_PA4_M | GPIO_PCTL_PA3_M | GPIO_PCTL_PA2_M)
#define GPIO_PCTL_PORTB  (GPIO_PCTL_PB7_M | GPIO_PCTL_PB6_M | GPIO_PCTL_PB5_M | GPIO_PCTL_PB4_M | GPIO_PCTL_PB3_M | GPIO_PCTL_PB2_M | GPIO_PCTL_PB1_M | GPIO_PCTL_PB0_M)
#define GPIO_PCTL_PORTC  (GPIO_PCTL_PC7_M | GPIO_PCTL_PC6_M | GPIO_PCTL_PC5_M | GPIO_PCTL_PC4_M)
#define GPIO_PCTL_PORTD  (GPIO_PCTL_PD7_M | GPIO_PCTL_PD6_M | GPIO_PCTL_PD5_M | GPIO_PCTL_PD4_M | GPIO_PCTL_PD3_M | GPIO_PCTL_PD2_M | GPIO_PCTL_PD1_M | GPIO_PCTL_PD0_M)
#define GPIO_PCTL_PORTE  (GPIO_PCTL_PE5_M | GPIO_PCTL_PE4_M | GPIO_PCTL_PE3_M | GPIO_PCTL_PE2_M | GPIO_PCTL_PE1_M)
#define GPIO_PCTL_PORTF  (GPIO_PCTL_PF4_M | GPIO_PCTL_PF3_M | GPIO_PCTL_PF2_M | GPIO_PCTL_PF1_M | GPIO_PCTL_PF0_M)

void PortInit(uint8_t port_index ){
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= port_index;     
  delay = SYSCTL_RCGC2_R;           
	switch(port_index)
	{
		
		case GPIO_PORTA :
		  GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
			GPIO_PORTA_CR_R |= 0XFC; 
			GPIO_PORTA_AMSEL_R &= ~0x00;     
			GPIO_PORTA_PCTL_R &= ~GPIO_PCTL_PORTA;
			GPIO_PORTA_AFSEL_R &= ~0x00;
			GPIO_PORTA_DEN_R |=0XFC;
			break;
		case GPIO_PORTB :
			GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
			GPIO_PORTB_CR_R |= 0XFF; 
			GPIO_PORTB_AMSEL_R = 0x00;     
			GPIO_PORTB_PCTL_R &= ~GPIO_PCTL_PORTB;
			GPIO_PORTB_AFSEL_R = 0x00;
			GPIO_PORTB_DEN_R |=0XFF;
			break;
		case GPIO_PORTC :
			GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
			GPIO_PORTC_CR_R |= 0XF0; 
			GPIO_PORTC_AMSEL_R = 0x00;     
			GPIO_PORTB_PCTL_R &= ~GPIO_PCTL_PORTC;
			GPIO_PORTC_AFSEL_R = 0x00;
			GPIO_PORTC_DEN_R |=0XF0;
			break;
		case GPIO_PORTD :
			GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
			GPIO_PORTD_CR_R |= 0XFF; 
			GPIO_PORTD_AMSEL_R = 0x00;     
			GPIO_PORTB_PCTL_R &= ~GPIO_PCTL_PORTD;
			GPIO_PORTD_AFSEL_R = 0x00;
			GPIO_PORTD_DEN_R |=0XFF;
			break;
		case GPIO_PORTE :
			GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
			GPIO_PORTE_CR_R |= 0X3F; 
			GPIO_PORTE_AMSEL_R = 0x00;     
			GPIO_PORTB_PCTL_R &= ~GPIO_PCTL_PORTE;
			GPIO_PORTE_AFSEL_R = 0x00;
			GPIO_PORTE_DEN_R |=0X3F;
			break;
		case GPIO_PORTF :   
			GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
			GPIO_PORTF_CR_R |= 0X1F; 
			GPIO_PORTF_AMSEL_R = 0x00;     
			GPIO_PORTB_PCTL_R &= ~GPIO_PCTL_PORTF;
			GPIO_PORTF_AFSEL_R = 0x00;
			GPIO_PORTF_DEN_R |=0X1F;
			break;
	}			
}



void Port_SetPinDirection(uint8_t port_index, uint8_t pins_mask, Port_PinDirectionType pins_direction)
{

	switch (port_index)
	{

	case GPIO_PORTA:

		if (pins_direction == PORT_PIN_OUT)
		{
			GPIO_PORTA_DIR_R |= pins_mask;
		}
		else if (pins_direction == PORT_PIN_IN)
		{
			GPIO_PORTA_DIR_R &= ~pins_mask;
		}

		break;

	case GPIO_PORTB:

		if (pins_direction == PORT_PIN_OUT)
		{
			GPIO_PORTB_DIR_R |= pins_mask;
		}
		else if (pins_direction == PORT_PIN_IN)
		{
			GPIO_PORTB_DIR_R &= ~pins_mask;
		}

		break;

	case GPIO_PORTC:

		if (pins_direction == PORT_PIN_OUT)
		{
			GPIO_PORTC_DIR_R |= pins_mask;
		}
		else if (pins_direction == PORT_PIN_IN)
		{
			GPIO_PORTC_DIR_R &= ~pins_mask;
		}

		break;

	case GPIO_PORTD:

		if (pins_direction == PORT_PIN_OUT)
		{
			GPIO_PORTD_DIR_R |= pins_mask;
		}
		else if (pins_direction == PORT_PIN_IN)
		{
			GPIO_PORTD_DIR_R &= ~pins_mask;
		}

		break;

	case GPIO_PORTE:

		if (pins_direction == PORT_PIN_OUT)
		{
			GPIO_PORTE_DIR_R |= pins_mask;
		}
		else if (pins_direction == PORT_PIN_IN)
		{
			GPIO_PORTE_DIR_R &= ~pins_mask;
		}

		break;

	case GPIO_PORTF:

		if (pins_direction == PORT_PIN_OUT)
		{
			GPIO_PORTF_DIR_R |= pins_mask;
		}
		else if (pins_direction == PORT_PIN_IN)
		{
			GPIO_PORTF_DIR_R &= ~pins_mask;
		}

		break;
	}
}


void Port_SetPinPullUp(uint8_t port_index , uint8_t pins_mask , uint8_t enable){
	switch(port_index)
	{
		case GPIO_PORTA:
			if(enable)
				GPIO_PORTA_PUR_R |= pins_mask;
			else 
				GPIO_PORTA_PUR_R &= ~pins_mask;
			break;
		case GPIO_PORTB:
			if(enable)
				GPIO_PORTB_PUR_R |= pins_mask;
			else 
				GPIO_PORTB_PUR_R &= ~pins_mask;
			break;
		case GPIO_PORTC:
			if(enable)
				GPIO_PORTC_PUR_R |= pins_mask;
			else 
				GPIO_PORTC_PUR_R &= ~pins_mask;
			break;		
		case GPIO_PORTD:
			if(enable)
				GPIO_PORTD_PUR_R |= pins_mask;
			else 
				GPIO_PORTD_PUR_R &= ~pins_mask;
			break;		
		case GPIO_PORTE:
			if(enable)
				GPIO_PORTE_PUR_R |= pins_mask;
			else 
				GPIO_PORTE_PUR_R &= ~pins_mask;
			break;		
		case GPIO_PORTF:
			if(enable)
				GPIO_PORTF_PUR_R |= pins_mask;
			else 
				GPIO_PORTF_PUR_R &= ~pins_mask;
			break;		
	} 
}



void Port_SetPinPullDown ( uint8_t port_index , uint8_t pins_mask , uint8_t enable )
{
	switch(port_index)
	{
	case GPIO_PORTA:
	(enable==0)? GPIO_PORTA_PDR_R &= ~pins_mask : (GPIO_PORTA_PDR_R |= pins_mask);
	break;
	
	case GPIO_PORTB:
	(enable==0)? GPIO_PORTB_PDR_R &= ~pins_mask : (GPIO_PORTB_PDR_R |= pins_mask);
	break;
	
	case GPIO_PORTC:
	(enable==0)? GPIO_PORTC_PDR_R &= ~pins_mask : (GPIO_PORTC_PDR_R |= pins_mask);
	break;
	
	case GPIO_PORTD:
	(enable==0)? GPIO_PORTD_PDR_R &= ~pins_mask : (GPIO_PORTD_PDR_R |= pins_mask);
	break;
	
	case GPIO_PORTE:
	(enable==0)? GPIO_PORTE_PDR_R &= ~pins_mask : (GPIO_PORTE_PDR_R |= pins_mask);
	break;
	
	case GPIO_PORTF:
	(enable==0)? GPIO_PORTF_PDR_R &= ~pins_mask : (GPIO_PORTF_PDR_R |= pins_mask);
	break;
	}	
}


uint8_t DIO_ReadPort(uint8_t port_index,uint8_t pins_mask){
switch(port_index)
 {
	case GPIO_PORTA :
	             return GPIO_PORTA_DATA_R & pins_mask ;
	             break;
	case  GPIO_PORTB :
	        	
	        	  return GPIO_PORTB_DATA_R & pins_mask ;
	        	  break;
	case  GPIO_PORTC :
	        	
				  return GPIO_PORTC_DATA_R & pins_mask ;
	        	break;
	case  GPIO_PORTD :
	        	
	        	 return GPIO_PORTD_DATA_R & pins_mask ;
	        	break;
	case  GPIO_PORTE :
	        	
	        	 return GPIO_PORTE_DATA_R & pins_mask;
	        	break;					
	case  GPIO_PORTF :
	        	
	        	 return GPIO_PORTF_DATA_R & pins_mask;
	        	break;					
 }
}


void DIO_WritePort(uint8_t port_index,uint8_t pins_mask, Dio_LevelType pins_level)
{
	
	switch(port_index)
	{
		
		case GPIO_PORTA:
			
			if (pins_level == STD_HIGH)
				{
					GPIO_PORTA_DATA_R |= pins_mask;
				}
			else if (pins_level == STD_LOW)
				{
					GPIO_PORTA_DATA_R &= ~pins_mask;
				}
	
					break;		
						
		case GPIO_PORTB:
			
			if (pins_level == STD_HIGH)
				{
					GPIO_PORTB_DATA_R |= pins_mask;
				}
			else if (pins_level == STD_LOW)
				{
					GPIO_PORTB_DATA_R &= ~pins_mask;
				}
	
					break;
							
		case GPIO_PORTC:
			
			if (pins_level == STD_HIGH)
				{
					GPIO_PORTC_DATA_R |= pins_mask;
				}
			else if (pins_level == STD_LOW)
				{
					GPIO_PORTC_DATA_R &= ~pins_mask;
				}
	
					break;
						
		case GPIO_PORTD:
			
			if (pins_level == STD_HIGH)
				{
					GPIO_PORTD_DATA_R |= pins_mask;
				}
			else if (pins_level == STD_LOW)
				{
					GPIO_PORTD_DATA_R &= ~pins_mask;
				}
	
					break;
						
		case GPIO_PORTE:
			
			if (pins_level == STD_HIGH)
				{
					GPIO_PORTE_DATA_R |= pins_mask;
				}
			else if (pins_level == STD_LOW)
				{
					GPIO_PORTE_DATA_R &= ~pins_mask;
				}
	
					break;
				
		case GPIO_PORTF:
			
			if (pins_level == STD_HIGH)
				{
					GPIO_PORTF_DATA_R |= pins_mask;
				}
			else if (pins_level == STD_LOW)
				{
					GPIO_PORTF_DATA_R &= ~pins_mask;
				}
	
					break;
	}
}



void DIO_FlipPort ( uint8_t port_index , uint8_t pins_mask )
{
	switch(port_index)
	{
		case GPIO_PORTA:
		GPIO_PORTA_DATA_R ^= pins_mask;
		break;
		case GPIO_PORTB:
		GPIO_PORTB_DATA_R ^= pins_mask;
		break;
		case GPIO_PORTC:
		GPIO_PORTC_DATA_R ^= pins_mask;
		break;
		case GPIO_PORTD:
		GPIO_PORTD_DATA_R ^= pins_mask;
		break;
		case GPIO_PORTE:
		GPIO_PORTE_DATA_R ^= pins_mask;
		break;
		case GPIO_PORTF:
		GPIO_PORTF_DATA_R ^= pins_mask;
		break;
	}
}



