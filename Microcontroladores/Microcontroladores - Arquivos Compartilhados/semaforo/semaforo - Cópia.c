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
	#define grep PORTDbits.RD6
	#define redp PORTDbits.RD7


void semaEst01() {
	red1 = 1;
	yel1 = 1;
	gre1 = 0;

	red2 = 0;
	yel2 = 1;
	gre2 = 1;

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

	grep = 0;
	redp = 1;
}

void main() {

	TRISD = 0b00000000;

	/* int vm_total = 0b00001001;

	int est_1 = 0b00100001;
	int est_2 = 0b00010001;
	int est_3 = 0b00001100;
	int est_4 = 0b00001010; */

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
