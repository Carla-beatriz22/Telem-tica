// Intituto Federal de Educa��o, Ci�ncia e Tecnologia do Cear�
// Carla Beatriz da Silva Teixeira 
// S1 de Tecnologia em Telem�tica 

//acompanhe este programa para x=6

#include<stdio.h>
main()
 
{ 
   int x,i=0,fat=1;  //declarando os valores
   printf("Digite um numero inteiro:\n"); //induzindo o que deve aparecer na tela
   scanf("%d",&x);
   do
   
{
	i=i+1;  // declarando os valores das vari�veis
	printf("fat=%d e i=%d\n",fat,i);
	fat=fat*i;
   }   
   while(i<x);  //condi��o da execu��o
   printf("%d! =  %d\nFim. ",x,fat);
}
