//Carla Beatriz da Silva Teixeira
// S1 em Telemática - IFCE


#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
int primofib (int z)
{	int a=1,b=0,c, cont,i;
	do
	{	c=a+b;
		a=b;
		b=c;
		cont=0;
		if(c==z)
		{	for(i=z;i>0;i--)
				if(z%i==0)
					cont++;
		}
	}while(c<z);
	if(cont==2)
		return 1;
	else
		return 0;
}
void divide(int z[], int vfib[], int vnfib[], int m, int *n, int *y)
{	int i; 
	*n=0; 
	*y=0;
	for(i=0;i<m;i++)
		if(primofib(z[i]))
		{	vfib[*n]=z[i];
			*n=(*n+1);
		}
		else
		{	vnfib[*y=z[i]];
			*y=(*y+1);
		}
}
void s(int vfib[], int n)
{	int i, aux, j, p;
    for(j=0;j<n-1;j++)
    {  p=j;
	   for(i=j+1;i<n;i++)
	   {	if(vfib[p]>vfib[i])
		   	{	p=i;
		    }
	   }
	   aux=vfib[j];
	   vfib[j]=vfib[p];
	   vfib[p]=aux;
    }
}
main()
{	srand(time(NULL));
	int m, i, n, y;
	setlocale(LC_ALL,"Portuguese");
	printf("Vetor de quantos elementos?\n");
	scanf("%d",&m);
	int z[m], vfib[m], vnfib[m];
	for(i=0;i<m;i++)
		z[i]=rand()%41234+4;
	printf("\nO vetor aplicado é:\n");
	for(i=0;i<m;i++)
		printf("V[%d]=%d\n",i,z[i]);
	divide(z, vfib, vnfib, m, &n, &y);
	printf("\nO vetor de elementos Primos de Fibonacci é:\n");
	for(i=0;i<n;i++)
		printf("V[%d]=%d\n",i,vfib[i]);
	s(vfib, n);
	printf("\nO vetor de elementos Primos de Fibonacci em ordem crescente é:\n");
	for(i=0;i<n;i++)
		printf("V[%d]=%d\n",i,vfib[i]);
	printf("\nO vetor dos demais elementos são:\n");
	for(i=0;i<y;i++)
		printf("V[%d]=%d\n",i,vnfib[i]);
}
