#include <LPC214X.h>
char *msg="\n\r hELLO wORLD\n\r";
int main()
{
PINSEL0=0X5;
U0LCR=0X83;
U0DLM=0X00;
U0DLL=0X61;
U0LCR=0X03;
while(*msg != 0x00)
{
while(!(U0LSR & 0X20));
U0THR=*msg;
msg++;
}
}