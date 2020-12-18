#include "lpc214x.h"

void delay() 
{
	unsigned int i;
	for (i = 0; i < 30000; i++);
}

void main()
{
	IO0DIR |=0xfffffFFF;
	while(1) {
		IOSET0 |=0xffffFFFF;
		delay();
		IOCLR0 |=0xFFFFffff;
		delay();
	}	
}
