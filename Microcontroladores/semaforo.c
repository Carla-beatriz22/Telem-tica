/* 
 * File:   semaforo.c
 * Author: Usuário
 *
 * Created on 21 de Outubro de 2020, 20:59
 */
/********************************************************************
     Semaforo*/

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
   
   
   
    #define  Vm2    PORTDbits.RD0
    #define  Am2    PORTDbits.RD1
    #define  Vd2    PORTDbits.RD2    
    #define  Vm1    PORTDbits.RD3
    #define  Am1    PORTDbits.RD4
    #define  Vd1    PORTDbits.RD5

    #define  semaforo PORTD

    
      
   void main(void)
   {
      TRISA =  0b00000000;
      TRISB =  0b00000000;
      TRISC =  0b00000000;
      TRISD =  0b00000000;
      TRISE =  0b00000000;
      
      
      semaforo = 0b00000000; 
     
       
      
      while(1)
      {    
           Vd1 = 1;
           Am1 = 0;
           Vm1 = 0;
           Vd2 = 0;
           Am2 = 0;
           Vm2 = 1;
           
      Delay10KTCYx(250);
      Delay10KTCYx(250);
      Delay10KTCYx(250);
      Delay10KTCYx(250);
      Delay10KTCYx(250);
      Delay10KTCYx(250);
      Delay10KTCYx(250);
      Delay10KTCYx(250);

           Vd1 = 0;
           Am1 = 1;
           Vm1 = 0;
           Vd2 = 0;
           Am2 = 0;
           Vm2 = 1;
       Delay10KTCYx(250);
       Delay10KTCYx(250);
       Delay10KTCYx(250);
       Delay10KTCYx(250);

      
           Vd1 = 0;
           Am1 = 0;
           Vm1 = 1;
           Vd2 = 0;
           Am2 = 0;
           Vm2 = 1;
      Delay10KTCYx(200);
      Delay10KTCYx(200);
      
           Vd1 = 0;
           Am1 = 0;
           Vm1 = 1;
           Vd2 = 1;
           Am2 = 0;
           Vm2 = 0;
      Delay10KTCYx(200);
      Delay10KTCYx(200);
      Delay10KTCYx(200);
      Delay10KTCYx(200);
      
           Vd1 = 0;
           Am1 = 0;
           Vm1 = 1;
           Vd2 = 0;
           Am2 = 1;
           Vm2 = 0;
      Delay10KTCYx(200);
      Delay10KTCYx(200);
      
           Vd1 = 0;
           Am1 = 0;
           Vm1 = 1;
           Vd2 = 0;
           Am2 = 0;
           Vm2 = 1;
      Delay10KTCYx(200);
      Delay10KTCYx(200);
         
          }
      
   }
