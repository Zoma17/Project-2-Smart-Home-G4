#include "PORT.h"
#include "ARM_Tiva-C.h"

void Port_Init(Port_Name n){
	uint8 x;
	volatile GPIO_Type *tempPort;		//hold the address of the port
	switch(n){
		case 0: tempPort = PORT_A;	RCGCGPIO |= (uint32)0X01;	 	break;		//with enbaling the clock on the whole port
		case 1: tempPort = PORT_B;	RCGCGPIO |= (uint32)0X02;	 	break;
		case 2: tempPort = PORT_C;	RCGCGPIO |= (uint32)0X04;	 	break;
		case 3: tempPort = PORT_D;	RCGCGPIO |= (uint32)0X08;	 	break;
		case 4: tempPort = PORT_E;	RCGCGPIO |= (uint32)0X10;	 	break;
		case 5: tempPort = PORT_F;	RCGCGPIO |= (uint32)0x20;	 	break;
	}
	// Here get the data from datasheet to initialize the port
	
		 x = 5;
		while(x--);
	if(n != 2){ // for hardware protections	
		 
		(tempPort -> LOCK) 	= (uint32)0x4C4F434B;
		(tempPort ->OCR) = (uint32) 0XFFFFFFFF;
		 
		(tempPort -> DEN)	|= (uint32)0X000F;		//only digital enable for all pins
		(tempPort -> AMSEL) &= (uint32)0X0000;		// disable the analog function
		(tempPort -> AFSEL) &= (uint32)0X0000;		// disable the alternative functions
		(tempPort -> PCTL) 	&= (uint32)0X0000;		// there are no alternative functions
		
	}
}




