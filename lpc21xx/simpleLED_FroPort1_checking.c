#include <lpc214x.h>

void delay(unsigned int z)
{
    T0CTCR=0x0;                 //Select Timer Mode
    T0TCR=0x00;                 //Timer off
    T0PR=59999;                 //Prescaler value for 1ms
    T0TCR=0x02;                 //Timer reset
    T0TCR=0x01;                 //Timer ON
    while(T0TC<z);           
	    T0TCR=0x00;                 //Timer OFF
	    T0TC=0;                     //Clear the TC value. This is Optional.
}

int main()
{
	IO1DIR |= 0xffffFFFF;
	while(1) {
		IOSET1 |= 0xFFFFffff;
		delay(100);
		IOCLR1 |= 0xFFFFffff;
		delay(100);
	}
}
