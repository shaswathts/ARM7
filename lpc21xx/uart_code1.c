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
	IO1DIR |= 0xFFFFffff;
	
	while(1)		
	{
		char c = U0Read(); // Read Data from Rx
		/*if( c == ENTER ) // Check if user pressed Enter key
		{
			U0Write(NEW_LINE); // Send New Line ASCII code change line
		}
		else
		{
			U0Write(c); // Write it to Tx to send it back
		}*/
		switch (c) {
		case '1':
		if( c == ENTER ) // Check if user pressed Enter key
		{
			U0Write(NEW_LINE); // Send New Line ASCII code change line
			IOSET1 |= 0xFFFFffff;
		}
		else
		{
			U0Write(c); // Write it to Tx to send it back
			IOSET1 |= 0xFFFFffff;
		}
			//U0Write(NEW_LINE);
			//IOSET1 |= 0xFFFFffff;
			break;

		case '2':
			U0Write(NEW_LINE);
			IOCLR1 |= 0xFFFFffff;
			break;
		}
	}
	return 0;
}
