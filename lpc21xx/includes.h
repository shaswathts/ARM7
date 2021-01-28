#include <lpc214x.h>

//Timer header program
void initTimer0(void)
{
  T0CTCR = 0x0;        //Set Timer Mode
  T0PR = 60-1;  
  
  T0MR0 = 500-1;       //Zero Indexed Count-hence subtracting 1
  T0MCR = (1<<0) | (1<<1);//Set bit0 & bit1 to Interrupt & Reset TC on MR0  
  VICVectAddr4 = (unsigned )timer0ISR; //Pointer Interrupt Function (ISR)
  VICVectCntl4 = (1<<5) | 4;     //(bit 5 = 1)->to enable Vectored IRQ slot                    //bit[4:0]) -> this the source number 
  VICIntEnable = (1<<4);    // Enable timer0 interrupt
  
  T0TCR = (1<<1);         // Reset Timer
}
    

//PLL header program
void initClocks(void)
{
  PLL0CON = 0x01;         //Enable PLL
  PLL0CFG = 0x24;         //Multiplier and divider setup
  PLL0FEED = 0xAA;        //Feed sequence
  PLL0FEED = 0x55;
  
  while(!(PLL0STAT & 0x00000400)); //is locked?
    
  PLL0CON = 0x03;        //Connect PLL after PLL is locked
  PLL0FEED = 0xAA;       //Feed sequence
  PLL0FEED = 0x55;
  VPBDIV = 0x01;         //PCLK is same as CCLK i.e.60 MHz
}

// Intrupt header program
__irq void timer0ISR(void)
{
  long int readVal;
  readVal = T0IR;     // Read current IR value    
  IO0PIN ^= (1<<10);     // Toggle LED at Pin P0.10
  T0IR = readVal;     // Write back to IR to clear Interrupt Flag
  VICVectAddr = 0x0;     // End of interrupt execution
}
