#include <lpc214x.h>

#define RDR (1<<0) // Receiver Data Ready
#define THRE (1<<5) // Transmit Holding Register Empty
#define MULVAL 15
#define DIVADDVAL 1
#define NEW_LINE 0xA // Character for new line .. analogous to '\n'
#define ENTER 0xD // Ascii code for Enter 

void pll()                  //Fosc=12Mhz,CCLK=60Mhz,PCLK=60MHz
{
    PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
	    PLL0CON=0x03;
	    PLL0FEED=0xaa;
	    PLL0FEED=0x55;
	    VPBDIV=0x01;
}

void InitUART0()
{
  PINSEL0 = 0x5;  /* Select TxD for P0.0 and RxD for P0.1 */ 
  U0LCR	= 3 | (1<<7) ; /* 8 bits, no Parity, 1 Stop bit | DLAB set to 1  */
  U0DLL	= 110;
  U0DLM = 1;	
  U0FDR = (MULVAL<<4) | DIVADDVAL; /* MULVAL=15(bits - 7:4) , DIVADDVAL=0(bits - 3:0)  */
  U0LCR &= 0x0F; // Set DLAB=0 to lock MULVAL and DIVADDVAL
  //BaudRate is now ~9600 and we are ready for UART communication!
 
}

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

char U0Read()
{
     while( !(U0LSR & RDR ) ); // wait till any data arrives into Rx FIFO
     return U0RBR; 
}

void U0Write(char data)
{
     while ( !(U0LSR & THRE ) ); // wait till the THR is empty
     // now we can write to the Tx FIFO
     U0THR = data;
}

int main(void)
{
	pll(); // Set CCLK=60Mhz and PCLK=60Mhz 
	InitUART0();
	PINSEL0 |= 0x05;
	IO1DIR |= 0xFFFFffff;
	
	while(1)		
	{
		char c = U0Read(); // Read Data from Rx
		switch (c) {
		case 'a':
			U0Write(NEW_LINE);
			IOSET1 |= (1<<16);
			delay(100);
			IOCLR1 |= (1<<16);
			break;

		case 'b':
			U0Write(NEW_LINE);
			IOSET1 |= (1<<17);
			delay(100);
			IOCLR1 |= (1<<17);
		
			break;

		case 'c':
			U0Write(NEW_LINE);
			IOSET1 |= (1<<18);
			delay(100);
			IOCLR1 |= (1<<18);
			
			break;

		default:
			 IOCLR1 |= 0xFFFFffff;
		}
	}	
}
