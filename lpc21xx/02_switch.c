#include<lpc214x.h>

void main()
{
    IO0DIR |=0XfffffFFF;                   //Port 0 is now acting as a output pin
    IO1DIR = 0x0;                          //Port 1 is now acting as a input pin
    while(1)
    {
        if((IO1PIN & (1<<16)) ==0)     //Checking 16th pin of Port 1
            IOSET0 |=0XfffffFFF;   //Port 0's all pins are high now (LED is glowing)
        else
            IOCLR0 |=0XFFFfffff;   //Port 0's all pins are low now (LED is OFF)
    }
        
}       
