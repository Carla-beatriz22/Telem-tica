#include <16F874.H>  //Biblioteca do PIC utilizado

#use delay(clock=1000000)
#fuses XT,NOWDT,NOPUT

void main() {
 	enable_interrupts(GLOBAL | INT_RB);
	while(TRUE){
		output_d(0b00001100); //vermelho2, amarelo2, verde2, vermelho1, amarelo1, verde1
         delay_ms(30000);
      output_d(0b000001010); //vermelho2, amarelo2, verde2, vermelho1, amarelo1, verde1
		   delay_ms(4000);
      output_d(0b00100001); //vermelho2, amarelo2, verde2, vermelho1, amarelo1, verde1
		   delay_ms(30000);
      output_d(0b00010001); //vermelho2, amarelo2, verde2, vermelho1, amarelo1, verde1
		   delay_ms(4000);
  }
}
