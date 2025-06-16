#include<P18F4550.h>
#include<delays.h>

#pragma config FOSC    	= HS     // (8 MHz)
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BORV     = 3
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = OFF
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
#pragma config STVREN   = ON
#pragma config LVP      = OFF

#define Out 0
#define In 1

//LCD
#define RS PORTEbits.RE0
#define EN PORTEbits.RE1
#define DISPLAY PORTD

#define RS_DIR DDREbits.RE0
#define EN_DIR DDREbits.RE1
#define DISPLAY_DIR DDRD

//Teclado
#define C0 	PORTBbits.RB0 
#define C1 	PORTBbits.RB1
#define C2 	PORTBbits.RB2
#define C3 	PORTBbits.RB3
#define L3 	PORTBbits.RB7
#define L2 	PORTBbits.RB6
#define L1 	PORTBbits.RB5
#define L0	PORTBbits.RB4

#define C0_DIR	DDRBbits.RB0
#define C1_DIR	DDRBbits.RB1
#define C2_DIR	DDRBbits.RB2
#define C3_DIR	DDRBbits.RB3
#define L0_DIR	DDRBbits.RB4
#define L1_DIR	DDRBbits.RB5
#define L2_DIR	DDRBbits.RB6
#define L3_DIR	DDRBbits.RB7

#define CMD	0
#define DAT 1

void Delay5ms(void);
void Delay100us(void);
void OpenLCD(void);
void ClearLCD(void);
void GotoXYLCD(unsigned char x,unsigned char y);
void WriteLCD(unsigned char data, unsigned char CD);


//envia comandos e dados p/ o LCD
void WriteLCD(unsigned char data, unsigned char CD)
{

	if(CD) 	RS = 1;
	else 	RS = 0;

	DISPLAY = data;
	EN = 1;
	Delay100us();
	EN = 0;
	Delay100us();

}

//posiciona cursor
void GotoXYLCD(unsigned char x,unsigned char y)
{
	if(y == 1)	WriteLCD(0x80 + x,CMD);
	if(y == 2)	WriteLCD(0xC0 + x,CMD);
}

//limpa LCD
void ClearLCD(void)
{
	RS = 0;
	DISPLAY = 0x01;
	EN = 1;
	Delay5ms();
	EN = 0;
	Delay5ms();
	
}

//inicializa o LCD
void OpenLCD(void)
{
	const unsigned char InitSeq[] = {0x33,0x32,0x38,0x0c,0x06,0x01};
	unsigned char i;

	ADCON1 = 0x0F;

//configurações de direção
	RS_DIR = Out;
	EN_DIR = Out;
	if(Out)	DISPLAY_DIR = 0xFF;
	//else	DISPLAY_DIR = 0x00;

//comandos
	RS = 0;		
	for(i=0;i<6;i++){
		DISPLAY = InitSeq[i];
		EN = 1;
		Delay5ms();
		EN = 0;
		Delay5ms();
	}
}

//escreve um caracter no LCD
void PutLCD(char data)

{
	WriteLCD(data,DAT);
}

//escreve uma string no LCD
void PrintLCD( char *Msg)

{
	while(*Msg){
		WriteLCD(*Msg,DAT);
		Msg++;
	}
}

void Delay100us(void)
{
	Delay100TCYx(2);
}

void Delay5ms(void)
{
	Delay10KTCYx(1);
}


void OpenKeyboard(void)
{
	C0_DIR = Out;
	C1_DIR = Out;
	C2_DIR = Out;
	L0_DIR = In;
	L1_DIR = In;
	L2_DIR = In;
	L3_DIR = In;
	EnablePullups();
}

unsigned char GetKey(void)
{
	unsigned char key = '\0';

	//coluna 0
	C0 = 0;
	C1 = 1;
	C2 = 1;
	C3 = 1;

	if(!L0) 	 key = '1';
	else if(!L1) key = '4';
	else if(!L2) key = '7';
	else if(!L3) key = '*';

	//coluna 1
	C0 = 1;
	C1 = 0;
	C2 = 1;
	C3 = 1;

	if(!L0) 	 key = '2';
	else if(!L1) key = '5';
	else if(!L2) key = '8';
	else if(!L3) key = '0';

	//coluna 2
	C0 = 1;
	C1 = 1;
	C2 = 0;
	C3 = 1;

	if(!L0) 	 key = '3';
	else if(!L1) key = '6';
	else if(!L2) key = '9';
	else if(!L3) key = '#';
	
	
	return(key);
}


void main (void)
{
	const char Msg[] = "SENHA";
	char Tecla,Rx;
	

	LATD = 0x00;
	DDRD = 0x00;
	OpenLCD();
	OpenKeyboard();
	GotoXYLCD(6,1);
	PrintLCD(Msg);

	while(1){

		Tecla = GetKey();

		if(Tecla){

			GotoXYLCD(8,2);
			PutLCD(Tecla);
		}
	}






}
