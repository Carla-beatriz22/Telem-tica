/********************************************************************
  Se pressionar botão B0 entao Liga Led0, Se B1 entao liga Led1, e se B2 liga 
  Led2*/

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
   #pragma config LVP = OFF   //Desabilita o Low Voltage Program.
   
   #define  B0    PORTBbits.RB0
   #define  B1    PORTBbits.RB1
   #define  B2    PORTBbits.RB2
   
   #define  Led0  PORTDbits.RD0
   #define  Led1  PORTDbits.RD1 
   #define  Led2  PORTDbits.RD2

   //Led0 = 1;   
   //Led1 = 1;
   Led2 = '1';
   #pragma code int_h = 0x08
   #pragma interrupt INT_EXT0 
   
   void INT_EXT0(void)
   { INTCONbits.INT0IF = 0;
      Led0 = ~Led0;     
  }
    
    void main(void)
   { 
      TRISA =  0b00000000;
      TRISB =  0b00000111;
      TRISC =  0b00000000;
      TRISD =  0b00000000;
      TRISE =  0b00000000;
      
      PORTD = 0xFF;
      
      INTCONbits.INT0IE = 1;
      INTCON2bits.INTEDG0 = 1;
      INTCONbits.GIE = 1;
      
      while(1);
      
      
     }
   
   
      
   
   
   
   


