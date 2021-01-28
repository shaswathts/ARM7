#include <lpc214x.h>
#include "lpc2148_pll.h"
#include "timer.h"

int main (){
	init_PLL0();
	IO0DIR |= 0xFFFFffff;
	while(1){
		IOSET0 |= (1 << 0);
		delayms(10);
		IOCLR0 |= (1 << 0);
		delayms(10);
	} 	
}
