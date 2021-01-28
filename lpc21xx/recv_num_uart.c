#include<lpc214x.h>

#define READ 0
#define THRE (1<<5) // Transmit Holding Register Empty
#define RDR (1<<0) // Receiver Data Ready
#define MULVAL 15
#define DIVADDVAL 1
#define NEW_LINE 0xA // Character for new line .. analogus '\n'
#define ENTER 0xD // Ascii code for Enter

void delay(unsigned int z);

void pll()
{
  PLL0CON=0X01;
  PLL0CFG=0X24;
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  while((PLL0STAT&(1<<10))==0);
	  PLL0CON=0X03;
	  PLL0FEED=0XAA;
	  PLL0FEED=0X55;
	  VPBDIV=0x01;             //pclk=60mhz
}

void uart_init()
{
  	PINSEL0 = PINSEL0 | 0x00000005;	/* Enable UART0 Rx0 and Tx0 pins of UART0 */
	U0LCR = 0x83;	 /* DLAB = 1, 1 stop bit, 8-bit character length */
	U0DLM = 0x00;	/* For baud rate of 9600 with Pclk = 15MHz */
	U0DLL = 0x61;		/* We get these values of U0DLL and U0DLM from formula */
	U0LCR = 0x03; 	/* DLAB = 0 */
}

void tx(int c)
{
	U0THR = c;
	while( (U0LSR & 0x40) == 0 );
}

char rx()
{
	while( (U0LSR & 0x01) == 0);	/*Wait till RDR bit becomes 1 which tells that receiver contains valid data */
	return U0RBR;
}

int main(void)
{
  int b;
  IO1DIR |= 0xffffffff;
  pll();
  uart_init();
  while(1) {
    b=rx();
 
	switch (b) {
		case 1:
			IOSET0 = (1<<16);
			delay(100);
			IOCLR0 = (1<<16);
			delay(100);
			tx(b);
			break;

		case 2:
			IOSET0 = (1<<17);
			delay(100);
			IOCLR0 = (1<<17);
			delay(100);
			tx(b);
			break;

		case 3:
			IOSET0 = (1<<18);
			delay(100);
			IOCLR0 = (1<<18);
			delay(100);
			tx(b);
			break;

		case 4:
			IOSET0 = (1<<19);
			delay(100);
			IOCLR0 = (1<<19);
			delay(100);
			tx(b);
			break;
	}
  }
}

void delay(unsigned int z)
{
    T0CTCR=0x0;                                 //Select Timer Mode
    T0TCR=0x00;                 //Timer off
    T0PR=59999;                 //Prescaler value for 1ms
    T0TCR=0x02;                 //Timer reset
    T0TCR=0x01;                 //Timer ON
    while(T0TC<z);           
    T0TCR=0x00;                 //Timer OFF
    T0TC=0;                     //Clear the TC value. This is Optional.
}
