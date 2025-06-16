	// Fosc = 20MHz
	// Tciclo = 4/Fosc = 0,2us
	#include <P18F4550.h>
	#include <delays.h>
	// #include <adc.h>
	#pragma config FOSC = HS
	#pragma config CPUDIV = OSC1_PLL2
	#pragma config WDT = OFF //Desabilita o Watchdog Timer (WDT).
	#pragma config PWRT = ON //Habilita o Power-up Timer (PWRT).
	#pragma config BOR = ON  //Brown-out Reset (BOR) habilitado somente no hardware.   
	#pragma config BORV = 1    //Voltagem do BOR é 4,33V.
	#pragma config PBADEN = OFF   //RB0,1,2,3 e 4 configurado como I/O digital.
	#pragma config LVP = OFF   //Desabilita o Low Voltage Program

	#define red2 PORTDbits.RD0
	#define yel2 PORTDbits.RD1
	#define gre2 PORTDbits.RD2
	#define red1 PORTDbits.RD3
	#define yel1 PORTDbits.RD4
	#define gre1 PORTDbits.RD5

	//portas do sinal de pedestre
	#define grep PORTDbits.RD6
	#define redp PORTDbits.RD7

	//porta de entrada do botão do semáforo
	#define bota PORTBbits.RB0

	//tentativa de interrupção
	#pragma code int_hr = 0x08 //vetor de interrupção de alta prioridade
	#pragma interrupt INT_EXT0 /*define a função trata_interrupt como rotina de	 tratamento da interrupção*/
	
	//chamando interrupção
	void INT_EXT0(void) //Função de tratamento da interrupção
	{
	 INTCONbits.INT0IF = 0; //Zera o flag da interrupção
	Delay10KTCYx(150);
	
	 //verde_pedestre(); //O que a interrupção vai fazer 
 	red1 = 0;
	yel1 = 1;
	gre1 = 1;

	red2 = 0;
	yel2 = 1;
	gre2 = 1;
	Delay10KTCYx(100);
	//ligando as luzes dos sinais
	grep = 1;
	redp = 0;
 	Delay10KTCYx(300);
	}



	

void semaEst01() {
	red1 = 1;
	yel1 = 1;
	gre1 = 0;

	red2 = 0;
	yel2 = 1;
	gre2 = 1;

	//ligando as luzes dos sinais
	grep = 0;
	redp = 1;
}

void semaEst02() {
	red1 = 1;
	yel1 = 0;
	gre1 = 1;

	red2 = 0;
	yel2 = 1;
	gre2 = 1;

	//ligando as luzes dos sinais
	grep = 0;
	redp = 1;
}

void semaEst03() {
	red1 = 0;
	yel1 = 1;
	gre1 = 1;

	red2 = 1;
	yel2 = 1;
	gre2 = 0;

	//ligando as luzes dos sinais
	grep = 0;
	redp = 1;
}

void semaEst04() {
	red1 = 0;
	yel1 = 1;
	gre1 = 1;

	red2 = 1;
	yel2 = 0;
	gre2 = 1;

	//ligando as luzes dos sinais
	grep = 0;
	redp = 1;
}

void total() {
	red1 = 0;
	yel1 = 1;
	gre1 = 1;

	red2 = 0;
	yel2 = 1;
	gre2 = 1;

	//ligando as luzes dos sinais
	grep = 0;
	redp = 1;
}

void verde_pedestre() {

	red1 = 0;
	yel1 = 1;
	gre1 = 1;

	red2 = 0;
	yel2 = 1;
	gre2 = 1;

	//ligando as luzes dos sinais
	grep = 0;
	redp = 1;

}



void main() {

	TRISD = 0b00000000;
	TRISBbits.TRISB0 = 1;

	INTCONbits.INT0IE = 1; //Habilita interrupção externa INT0
	INTCON2bits.INTEDG0 = 1; //Habilita interrupção na borda de subida
	INTCONbits.GIE = 1; //Habilita todas as interrupções



	while (1) {
		semaEst01();
		Delay10KTCYx(500);
		semaEst02();
		Delay10KTCYx(200);
		total();
		Delay10KTCYx(100);
		semaEst03();
		Delay10KTCYx(400);
		semaEst04();
		Delay10KTCYx(200);
		total();
		Delay10KTCYx(100);
	}
}
