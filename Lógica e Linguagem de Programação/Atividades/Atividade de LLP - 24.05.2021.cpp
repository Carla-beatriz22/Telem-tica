#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	float xa, xb, ya, yb, dist;
	
	printf("Digite a coordenada horizontal de a");
	scanf("%f", &xa);
	
	printf("Digite a coordenada horizontal do ponto B:");
	scanf("%f", &xb);
	
	printf("Digite a ordenada do ponto A:");
	scanf("%f", &ya);

	printf("Digite a coordenada horizontal do ponto B:");
	scanf("%f", &yb);

	dist = sqrt((xa-xb)*2) + ((ya-yb)*2);
	
	
	printf("Distancia sera de %f", dist);
	
	return 0;
}
