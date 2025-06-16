/********************************************************************
  Chave controla leds*/

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
   
   
   
   #define  chave PORTBbits.RB0

   #define  Led0  PORTDbits.RD0
   #define  Led1  PORTDbits.RD1 
   #define  Led2  PORTDbits.RD2
  
   
   void liga_led(int n); 
   
  
  
 int testa_bot(int cont)
   {
   if(chave)return cont;
   Delay1KTCYx(10);
   if(chave)return cont;
   Delay1KTCYx(10);
   while(!chave);
   cont++ ;
   return cont;
    }
   
   
   void liga_led(int n)
   {
   switch(n)
      {
            case  0: PORTD = 0b00000000; break;
            case  1: PORTD = 0b00000001; break;
            case  2: PORTD = 0b00000010; break;
            case  3: PORTD = 0b00000100; break;
             default:  PORTD = 0;

      }

    }
   

      
   void main(void)
   {  
      int n;
      n = 0;
      TRISA =  0b00000000;
      TRISB =  0b00000001;
      TRISC =  0b00000000;
      TRISD =  0b00000000;
      TRISE =  0b00000000;
      
     PORTD = 0; 
      
      
      //Conversor AD
      
     // OpenADC(0x00, 0x00; ADC_0ANA);
    //  closeADC();
              
      while(1)
      {  while(chave);
         Delay1KTCYx(10);
        n = testa_bot(n);
        liga_led(n);
         if(n==4)n=0;
      }
      
   }