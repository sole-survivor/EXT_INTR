#include<lpc21xx.h>
#include"header.h"
#define LED1 (1<<0)
int main()
{
	config_vic();
	IODIR0=LED1;
	IOSET0=LED1;
	while (1)
	{
	}
}
