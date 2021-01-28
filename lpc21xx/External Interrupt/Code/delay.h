void delay(int count)
	
{
  int j=0,i=0;
  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}
