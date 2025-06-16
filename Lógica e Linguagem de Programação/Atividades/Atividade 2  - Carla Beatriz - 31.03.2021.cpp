// Intituto Federal de Educação, Ciência e Tecnologia do Ceará
// Carla Beatriz da Silva Teixeira 
// S1 de Tecnologia em Telemática 

//acompanhe este programa para x=6

#include<stdio.h>
main()
 
{ 
   int x,i=0,fat=1;  //declarando os valores
   printf("Digite um numero inteiro:\n"); //induzindo o que deve aparecer na tela
   scanf("%d",&x);
   do
   
{
	i=i+1;  // declarando os valores das variáveis
	printf("fat=%d e i=%d\n",fat,i);
	fat=fat*i;
   }   
   while(i<x);  //condição da execução
   printf("%d! =  %d\nFim. ",x,fat);
}
