#include <lpc21xx.h>
#include"header.h"
#define LED1 (1<<0)

void EXT__INT (void) __irq
{
 IO0DIR |= LED1;
 IO0CLR |= LED1;
 delay_sec(3,1);
 IO0SET|=LED1;	
 EXTINT |= 0x4;  
 VICVectAddr = 0;
}

void config_vic (void)
{
  EXTMODE = 0x4;
  EXTPOLAR &= ~(0x4);
  PINSEL0 = 0x80000000;
  
  VICIntSelect &= ~ (1<<16);            // EINT2 selected as IRQ 16
  VICVectAddr5 = (unsigned int)EXT__INT;
  VICVectCntl5 = (1<<5) | 16;
  VICIntEnable = (1<<16);
  EXTINT &= ~(0x4);
}
