/********************************************************************
                             LCD
********************************************************************/

   // Fosc = 4MHz
   // Tciclo = 4/Fosc = 1us
   #include <P18F4550.h>
   #include <delays.h>

   #pragma config FOSC = HS
   #pragma config PWRT = ON
   #pragma config BOR = OFF
   #pragma config WDT = OFF
   #pragma config MCLRE = OFF
   #pragma config PBADEN=OFF
   #pragma config LVP = OFF
   
      
   #define  lcd    LATD
   #define  rs     LATEbits.LATE0
   #define  enable LATEbits.LATE1
   #define  rw     LATEbits.LATE2  
   #define  tempo  1  
 
  //Teclado
  #define C0 	PORTBbits.RB0 
  #define C1 	PORTBbits.RB1
  #define C2 	PORTBbits.RB2
  #define C3 	PORTBbits.RB3
  #define L3 	PORTBbits.RB7
  #define L2 	PORTBbits.RB6
  #define L1 	PORTBbits.RB5
  #define L0	PORTBbits.RB4
/*
  #define C0_DIR	DDRBbits.RB0
  #define C1_DIR	DDRBbits.RB1
  #define C2_DIR	DDRBbits.RB2
  #define C3_DIR	DDRBbits.RB3
  #define L0_DIR	DDRBbits.RB4
  #define L1_DIR	DDRBbits.RB5
  #define L2_DIR	DDRBbits.RB6
  #define L3_DIR	DDRBbits.RB7
*/   
   void comando_lcd(void);
   void dado_lcd(void);
   
/**********************************************************************
        Seleciona comando para LCD
***********************************************************************/
   void  comando_lcd(void)
   {  rs = 0;
      enable = 1;
      Delay10TCYx(1);
      enable = 0;
     // Delay10TCYx(8);
   }
/***********************************************************************
         seleciona dado para LCD
 **********************************************************************/
   void  dado_lcd(void)
   {  rs = 1;
      enable = 1;
      Delay10TCYx(1);
      enable = 0;
     // Delay10TCYx(8);
   }
/***********************************************************************
         Envia comando para LCD
 **********************************************************************/
   void envia_comando( char dado)
   {
     lcd = dado;
     comando_lcd() ;
                 }
/***********************************************************************
         Envia dado para LCD
 **********************************************************************/

 void envia_dado( char dado)
   {
     lcd = dado;
     dado_lcd() ;
                 }
                 
/*********************************************************************
           Configura LCD
*********************************************************************/
  void  config_lcd(void)
      {
      lcd=0;
      Delay10KTCYx(3); //30ms - ok 
      envia_comando(0x30);
      Delay1KTCYx(8); //8ms - ok
      envia_comando(0x30);
      Delay1KTCYx(1);  //1ms - ok
      envia_comando(0x30);
      Delay10KTCYx(1); //10ms 
      //envia_comando(0x02);
      //Delay1KTCYx(2);
      envia_comando(0x38); // usar LDC configurado para barramento de 8 bits
      Delay10KTCYx(1); //10ms
      envia_comando(0x06); //desloca cursor p  direita a cada caracter
      Delay10KTCYx(1);//10ms
      envia_comando(0x0C); // Display ligado sem cursor
      Delay10KTCYx(1); //10ms
      //envia_comando(0x01);
      //Delay10KTCYx(2); //20ms
      }
	  //exemplo de digito
	  void digitos (void){
	  rw = 0; 
      config_lcd();			//chama o comando para preperar o lcd
      envia_comando(0xc3);	//envia o endereço onde o lcd vai começar ativo
      Delay10KTCYx(tempo);	//250ms
      envia_dado('x');		//dado em ascii que vai ser enviado
      Delay10KTCYx(tempo);	//delay posterior


}
/*****************************************************************************
           Modelo de chamada dos números
*****************************************************************************/
void digito1 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('1');
      Delay10KTCYx(tempo);
}
void digito2 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('2');
      Delay10KTCYx(tempo);
}
void digito3 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('3');
      Delay10KTCYx(tempo);
}
void digito4 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('4');
      Delay10KTCYx(tempo);
}
void digito5 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('5');
      Delay10KTCYx(tempo);
}
void digito6 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('6');
      Delay10KTCYx(tempo);
}
void digito7 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('7');
      Delay10KTCYx(tempo);
}
void digito8 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('8');
      Delay10KTCYx(tempo);
}
void digito9 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('9');
      Delay10KTCYx(tempo);
}
void digito0 (void){
rw = 0; 
      config_lcd();
      envia_comando(0xc3);
      Delay10KTCYx(tempo);//250ms
      envia_dado('0');
      Delay10KTCYx(tempo);
}
void digitoAs (void){
rw = 0; 
      config_lcd();
      envia_comando(0x01);
      Delay10KTCYx(tempo);//250ms
}
void digitoJV (void){
rw = 0; 
      config_lcd();
      envia_comando(0x18);
      Delay10KTCYx(tempo);//250ms
      envia_dado(' ');
      Delay10KTCYx(tempo);
}
   void main(void)
   {
      TRISA =  0b00000000;
      TRISB =  0b11111111;
      TRISC =  0b00000000;
      TRISD =  0b00000000;
      TRISE =  0b00000000;
      
      rw = 0; 
      config_lcd();
      envia_comando(0x83);
      Delay10KTCYx(tempo);//250ms
      envia_dado('D');
      Delay10KTCYx(tempo);
	  envia_dado('i');
      Delay10KTCYx(tempo); 
	  envia_dado('g');
      Delay10KTCYx(tempo);
	  envia_dado('i');
      Delay10KTCYx(tempo);
	  envia_dado('t');
      Delay10KTCYx(tempo);
	  envia_dado('e');
      Delay10KTCYx(tempo);  

digito9();
 

//if


   
         while(1){
            if(C0=='1' && L0 =='1'){
				digito9();
			}
		    if(C1=='1' && L0 =='1'){
				digito8();
			}
            if(C2=='1' && L0 =='1'){
				digito7();
			}
            if(C0=='1' && L1 =='1'){
				digito6();
			}
            if(C1=='1' && L1 =='1'){
				digito5();
			}
            if(C2=='1' && L1 =='1'){
				digito4();
			}
            if(C0=='1' && L2 =='1'){
				digito3();
			}
            if(C1=='1' && L2 =='1'){
				digito2();
			}
            if(C2=='1' && L2 =='1'){
				digito1();
			}
            if(C0=='1' && L3 =='1'){
				digito0();
			}
            if(C1=='1' && L3 =='1'){
				digitoAs();
			}
            if(C2=='1' && L3 =='1'){
				digitoJV();
			}      
      
   }
   
   
}