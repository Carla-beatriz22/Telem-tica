//============================================================================
//|	Este programa Sorteia n�meros aleat�rios de acordo com o padr�o Loteria  |	
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
//			FUN��O DE GERA��O DE NUMERO B�NUS;
//==================================================================================
//		Esta fun��o permite uma gera��o de numero aleat�rio bonus para um jogo.
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
//				FUN��O DE GERA��O DE APRESENTA��O;
//==================================================================================
//		Esta fun��o permite uma gera��o de uma apresenta��o para um jogo.
//----------------------------------------------------------------------------------
	void apresent ()
	{
	
	printf("\n\n=======================================================================================\n");
	printf("\n\t\t\t   INSTITUTO FEDERAL DO CEAR�\n");
	printf("\n=======================================================================================\n");
	printf("\n\n\t\t\t\t !!! OL� !!!\n\n");
	printf("---------------------------------------------------------------------------------------");
	printf("\n\n\t   ESTE � UM PROGRAMA QUE SIMULA A LOTERIA INGLESA PLUS !!!!\n");
	printf("---------------------------------------------------------------------------------------\n\n");
	

	}	

//----------------------------------------------------------------------------------

//==================================================================================
//						FUN��O DE GERA��O DE REGRAS;
//==================================================================================
//		Esta fun��o permite uma gera��o de uma apresenta��o para um jogo.
//----------------------------------------------------------------------------------

	void regras()
{
	
	printf("\n\tAFINAL, COMO JOGO ISTO?\n\n");
	
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("-> Voc� dir� quantos jogos ir� querer jogar; \n\n-> Ser� sorteado 6 n�meros ale�t�rios de 1 a 59 e mais um n�mero b�nus;\n\n ");

	printf("\n-> Ser� gerado um jogo e um n�mero aleat�rio por fora do seu, simulando o resultado oficial da loteria;\n\n");

	printf("\n-> Sua premia��o ser� de acordo com sua categoria;\n\n");
	
	printf("\n-> As categorias v�o de I a VI;\n\n");

	printf("\n-> Sorteado seus n�meros, clique qualquer tecla para finalizar;\n\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("**********************************************************************************************************************\n");
	printf("\nOBS:Voc� pode checar seu resultado no arquivo - LOTERIAINGLESA_RESULTADO.txt localizado na mesma pasta onde voc� salvou este programa.\n");
	printf("\n**********************************************************************************************************************\n");
	printf("\nVAMOS L� ENT�O !! Pressione algo e vamos sortear os seus jogos !...\n\n");

}

//---------------------------------------------------------------------------------- 

//==================================================================================
//						FUN��O DE GERA��O DA TABELA DE CATEGORIA;
//==================================================================================
//		Esta fun��o permite uma gera��o de uma apresenta��o para um jogo.
//----------------------------------------------------------------------------------

	void tabelacat ()
{
	printf("\n\n========================================================================================================\n\n");
	printf("\t\t\t\tTABELA DE CATEGORIA DE PR�MIOS\n");
	printf("\n========================================================================================================\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria I (acerto dos 6 numeros principais)= Pr�mio m�ximo (geralmente perto dos R$ 49 milh�es.)\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
	printf("Categoria II (acerto dos 5 numeros principais + n bonus)=\t\t aprox. R$ 4,9 milh�es\n");
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
//							M�TODO PRINCIPAL 
//==================================================================================

main()
{  
	int x,s, y,n, i, m, j,l; 
	int flag,qjogos,aux,tabela, o,of;
	
	FILE*arquivo;
	
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	
//-------------------------------------------------------------
//		CHAMANDO APRESENTA��ES, REGRAS E CATEGORIAS
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
//			INICIANDO GERA��O E GRAVA��O DE JOGO ALEAT�RIO
//--------------------------------------------------------------

	if((arquivo=fopen("LOTERIAINGLESA_RESULTADO.txt","w"))==NULL)
		printf("ERRO NA CRIA��O DO ARQUIVO\n");
	else
 {

	
	printf("Quantos jogos voc� deseja sortear?[1-6]\n");
    scanf("%d", &qjogos);
    system("cls");
    
    
    int	lot[qjogos][6];
//------------------------------------------------------------
//		ANULA��O DE POSS�VEIS JOGOS REPETIDOS
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
    		 	fprintf(arquivo,"\tnumero b�nus -> %d\n", aleat2(1,59));
			}

//---------------------------------------------------------------
//			GERA��O DO RESULTADO OFICIAL
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
	fprintf(arquivo,"\t\t\t\tTABELA DE CATEGORIA DE PR�MIOS\n");
	fprintf(arquivo,"\n========================================================================================================\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria I (acerto dos 6 numeros principais)= Pr�mio m�ximo (geralmente perto dos R$ 49 milh�es.)\n");
	fprintf(arquivo,"--------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo,"Categoria II (acerto dos 5 numeros principais + n bonus)=\t\t aprox. R$ 4,9 milh�es\n");
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
    		 		fprintf(arquivo,"\tnumero b�nus -> %d\n", aleat2(1,59));
				}
			
			
 }
 	fclose(arquivo);
	printf("\n\nJOGOS GERADOS !  CONFIRA J� O RESULTADO NO ARQUIVO.TXT (LOTERIAINGLESA_RESULTADO.txt), CONTIDO NA MESMA PASTA ONDE EST� SALVO ESTE PROGRAMA !!\n\n\t\t AT� LOGO.");
}

