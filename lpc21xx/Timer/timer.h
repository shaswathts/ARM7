#include <lpc214x.h>

void delayms (unsigned int milliseconds){
	
	T0CTCR = 0x00;
	T0PR = 6000-1;
	T0TC = 0;
	T0TCR = 0x01;

	while (T0TC < milliseconds);
	T0TCR = 0x00;
}
