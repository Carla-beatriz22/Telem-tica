//Carla Beatriz da Silva Teixeira
//Instituto Federal do Cear�
//S1 em Telem�tica

#include<stdio.h>

main()
{
    int x, i;
    
    printf("x=?\n");
    scanf("%d",&x);
    
    for(i=1;x>0;x=x-1)
    
    {
       i=i*x;
    }
   
    printf("\nO valor em fatorial ser�: %d",i);
    return 0;
}
