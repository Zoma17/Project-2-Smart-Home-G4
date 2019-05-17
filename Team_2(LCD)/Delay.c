
#include "stdint.h"
#include "Delay.h"

void Delay_Ms(uint32_t Num)
{
	int i,j;
	for(i=0;i<Num;i++)
		for(j=0;j<3190;j++)
		{}
	
}



void Delay_Us(uint32_t Num)
{
	int i,j;
	for(i=0;i<Num;i++)
		for(j=0;j<3;j++)
		{}
	
	
}