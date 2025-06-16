//============================================================================
//|	Este programa Sorteia números aleatórios de acordo com o padrão Loteria  |	
//|inglesa plus, que tem seus sorteios as quartas e quintas !!!			     |
//|																             |
//|																			 |
//|	Autor: Jefferson santos do nascimento <jeffersonsantos.99@hotmail.com>   |
//|																			 | 
//|	Data: 01/12/2019														 |
//|																		     |
//============================================================================

//---------------------------------------------------------------------------------
//							BIBLIOTECAS 
//---------------------------------------------------------------------------------

#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>


//----------------------------------------------------------------------------------


//==================================================================================
//			FUNÇÃO DE GERAÇÃO DE NUMERO BÔNUS;
//==================================================================================
//		Esta função permite uma geração de numero aleatório bonus para um jogo.
//----------------------------------------------------------------------------------

int aleat (int A, int B)
{	
	int aux;
	if (B<A)
	{	aux=A;
		A=B;
		B=aux;
	}
	return A+(rand()%(B-A+1));
}

//----------------------------------------------------------------------------------

	int aleat2 (int A, int B)
{
	
	return aleat(A-1,B+1);
	
}
//----------------------------------------------------------------------------------

//==================================================================================
//				FUNÇÃO DE GERAÇÃO DE APRESENTAÇÃO;
//==================================================================================
//		Esta função permite uma geração de uma apresentação para um jogo.
//----------------------------------------------------------------------------------
	void apresent ()
	{
	
	printf("\n\n=======================================================================================\n");
	printf("\n\t\t\t   INSTITUTO FEDERAL DO CEARÁ\n");
	printf("\n=======================================================================================\n");
	printf("\n\n\t\t\t\t !!! OLÁ !!!\n\n");
	printf("---------------------------------------------------------------------------------------");
	printf("\n\n\t   ESTE É UM PROGRAMA QUE SIMULA A LOTERIA INGLESA PLUS !!!!\n");
	printf("---------------------------------------------------------------------------------------\n\n");
	

	}	

//----------------------------------------------------------------------------------

//==================================================================================
//						FUNÇÃO DE GERAÇÃO DE REGRAS;
//==================================================================================
//		Esta função permite uma geração de uma apresentação para um jogo.
//----------------------------------------------------------------------------------

	void regras()
{
	
	printf("\n\tAFINAL, COMO JOGO ISTO?\n\n");
	
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("-> Você dirá quantos jogos irá querer jogar; \n\n-> Será sorteado 6 números aleátórios de 1 a 59 e mais um número bônus;\n\n ");

	printf("\n-> Será gerado um jogo e um número aleatório por fora do seu, simulando o resultado oficial da loteria;\n\n");

	printf("\n-> Sua premiação será de acordo com sua categoria;\n\n");
	
	printf("\n-> As categorias vão de I a VI;\n\n");

	printf("\n-> Sorteado seus números, clique qualquer tecla para finalizar;\n\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("**********************************************************************************************************************\n");
	printf("\nOBS:Você pode checar seu resultado no arquivo - LOTERIAINGLESA_RESULTADO.txt localizado na mesma pasta onde você salvou este programa.\n");
	printf("\n**********************************************************************************************************************\n");
	printf("\nVAMOS LÁ ENTÃO !! Pressione algo e vamos sortear os seus jogos !...\n\n");

}

//---------------------------------------------------------------------------------- 

//==================================================================================
//						FUNÇÃO DE GERAÇÃO DA TABELA DE CATEGORIA;
//==================================================================================
//		Esta função permite uma geração de uma apresentação para um jogo.
//----------------------------------------------------------------------------------

	void tabelacat ()
{
	printf("\n\n========================================================================================================\n\n");
	printf("\t\t\t\tTABELA DE CATEGORIA DE PRÊMIOS\n");
	printf("\n========================================================================================================\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria I (acerto dos 6 numeros principais)= Prêmio máximo (geralmente perto dos R$ 49 milhões.)\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria II (acerto dos 5 numeros principais + n bonus)=\t\t aprox. R$ 4,9 milhões\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria III (acerto dos 5 numeros principais)=\t\t\t aprox. R$ 8,5 mil\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria IV (acerto dos 4 numeros principais)=\t\t\t\t aprox. R$ 687\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria V (acerto dos 3 numeros principais)=\t\t\t\t aprox. R$ 147\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria VI (acerto dos 2 numeros principais)=\t\t\t\t aprox. R$ 9,80\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	
}

//----------------------------------------------------------------------------------

//==================================================================================
//							MÉTODO PRINCIPAL 
//==================================================================================

main()
{  
	int x,s, y,n, i, m, j,l; 
	int flag,qjogos,aux,tabela, o,of;
	
	FILE*arquivo;
	
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	
//-------------------------------------------------------------
//		CHAMANDO APRESENTAÇÕES, REGRAS E CATEGORIAS
//-------------------------------------------------------------
	apresent();
	system("pause");
	system("cls");
	
	regras ();
	system("pause");
	system("cls");
	
	tabelacat();
	system("pause");
	system("cls");
//--------------------------------------------------------------
//			INICIANDO GERAÇÃO E GRAVAÇÃO DE JOGO ALEATÓRIO
//--------------------------------------------------------------

	if((arquivo=fopen("LOTERIAINGLESA_RESULTADO.txt","w"))==NULL)
		printf("ERRO NA CRIAÇÃO DO ARQUIVO\n");
	else
 {

	
	printf("Quantos jogos você deseja sortear?[1-6]\n");
    scanf("%d", &qjogos);
    system("cls");
    
    
    int	lot[qjogos][6];
//------------------------------------------------------------
//		ANULAÇÃO DE POSSÍVEIS JOGOS REPETIDOS
//------------------------------------------------------------
        for(i=0; i<qjogos; i++)
        {	for(m=0;m<6;m++)
        	{   flag=1;
            	while(flag)
            	{   lot[i][m]=1+(rand()%60);
                	for(j=0,flag=0; j<m; j++)
                    	if(lot[i][j]==lot[i][m])
                        	flag=1;
            	}
        	}

			for(j=0; j<6; j++)
            	for(s=j+1; s<6; s++) 
					{	if(lot[i][j]>lot[i][s])
                		{   aux=lot[i][j];
                    	lot[i][j]=lot[i][s];
                    	lot[i][s]=aux;
                		}	
           			}
	
		}

		fprintf(arquivo,"-------------------------------------------------------------------\n");
		fprintf(arquivo,"\t\tSEUS JOGOS GERADOS\n");
		fprintf(arquivo,"-------------------------------------------------------------------\n");

		for(i=0;i<qjogos;i++) 
    		{	for(j=0; j<6; j++)
    			
  
				fprintf(arquivo,"%4d",lot[i][j]);               
    		 	fprintf(arquivo,"\tnumero bônus -> %d\n", aleat2(1,59));
			}

//---------------------------------------------------------------
//			GERAÇÃO DO RESULTADO OFICIAL
//---------------------------------------------------------------

        for(o=0; o<1; o++)
       			{	for(m=0;m<6;m++)
        		 {   flag=1;
            	while(flag)
            		{   lot[o][m]=1+(rand()%60);
                	for(of=0,flag=0; of<m; of++)
                    	if(lot[o][of]==lot[o][m])
                        	flag=1;
            		}
        		 }
			//Ordena o jogo do menor para o maior elemento.	
			for(of=0; of<6; of++)
            	for(s=of+1; s<6; s++) 
						{	if(lot[o][of]>lot[o][s])
                			{   aux=lot[o][of];
                    	lot[o][of]=lot[o][s];
                    	lot[o][s]=aux;
                			}	
           				}

				}


	fprintf(arquivo,"\n\n========================================================================================================\n\n");
	fprintf(arquivo,"\t\t\t\tTABELA DE CATEGORIA DE PRÊMIOS\n");
	fprintf(arquivo,"\n========================================================================================================\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria I (acerto dos 6 numeros principais)= Prêmio máximo (geralmente perto dos R$ 49 milhões.)\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria II (acerto dos 5 numeros principais + n bonus)=\t\t aprox. R$ 4,9 milhões\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria III (acerto dos 5 numeros principais)=\t\t\t aprox. R$ 8,5 mil\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria IV (acerto dos 4 numeros principais)=\t\t\t\t aprox. R$ 687\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria V (acerto dos 3 numeros principais)=\t\t\t\t aprox. R$ 147\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria VI (acerto dos 2 numeros principais)=\t\t\t\t aprox. R$ 9,80\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");





				
				fprintf(arquivo,"\n\t\tRESULTADO OFICIAL !!!\n\n");
				for(o=0;o<1;o++) 
    			{	for(of=0; of<6; of++)

					fprintf(arquivo,"\t%4d", lot[o][of]);               
    		 		fprintf(arquivo,"\tnumero bônus -> %d\n", aleat2(1,59));
				}
			
			
 }
 	fclose(arquivo);
	printf("\n\nJOGOS GERADOS !  CONFIRA JÁ O RESULTADO NO ARQUIVO.TXT (LOTERIAINGLESA_RESULTADO.txt), CONTIDO NA MESMA PASTA ONDE ESTÁ SALVO ESTE PROGRAMA !!\n\n\t\t ATÉ LOGO.");
}

