#include <p18f4520.h>

void delay()
{
int i;

for (i=0;i<400;i++){}
}

disp1 ()
{
PORTB = 0b11000000;
PORTC = 0b00100000;
delay();
PORTC = 0b00000000;
}

disp2 ()
{
PORTB = 0b11111001;
PORTC = 0b00010000;
delay();
PORTC = 0b00000000;
}

disp3 ()
{
PORTB = 0b10100100;
PORTC = 0b00001000;
delay();
PORTC = 0b00000000;
}

disp4 ()
{
PORTB = 0b10110000;
PORTC = 0b00000100;
delay();
PORTC = 0b00000000;
}

disp5 ()
{
PORTB = 0b10011001;
PORTC = 0b00000010;
delay();
PORTC = 0b00000000;
}

disp6 ()
{
PORTB = 0b10010010;
PORTC = 0b00000001;
delay();
PORTC = 0b00000000;
}

void main ()
{
TRISB = 0b00000000;
TRISC = 0b00000000;

disp1();
disp2();
disp3();
disp4();
disp5();
disp6();
}