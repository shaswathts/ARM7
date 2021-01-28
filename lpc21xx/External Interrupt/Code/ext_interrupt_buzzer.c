//external interrupt

//P0.15 switch is connected
//P0.25 buzzer / led is connected

#include <LPC214x.H>  
#include "interrupt.h"



int main (void) 
{
  init_ext_interrupt();   // initialize the external interrupt
  
  while (1)  
  {        
  }
}

