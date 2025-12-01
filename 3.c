#include <LPC214x.H>
void init_ext_interrupt(void);
__irq void Ext_ISR(void);
int main (void)
{
init_ext_interrupt();
while (1)
{}
}
void init_ext_interrupt()
{
EXTMODE = 0x4;
EXTPOLAR &= ~(0x4);
PINSEL0 = 0x0000C000;

VICIntSelect &= ~ (1<<16); 
VICVectAddr5 = (unsigned int)Ext_ISR; 
VICVectCntl5 = (1<<5) | 16; 
VICIntEnable = (1<<16); 
EXTINT &= ~(0x4);
}
__irq void Ext_ISR(void) 
{
IO1DIR |=0xFF000000;
IO1PIN ^= 0xFF000000; 
EXTINT |= 0x4;
VICVectAddr = 0; 
}
