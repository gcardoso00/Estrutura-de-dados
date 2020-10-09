#include <stdlib.h>
#include <stdio.h>

void incluir(void);
void listar();
int buscaBinaria (int cod[], int n,int x);
void selesction(int cod[], int preco[], int qtd[], int y);
void consultar();
void alterar();


int i = 0, cod[100], cpf[100], valor[100], y, j=1;



void incluir()
{	int h = 0;
	int verifica;
	system ("cls");
	printf("\n*****************************\n");

	printf("\nCADASTRO DE EVENTO(0-SAIR) \n");

	printf("\nNUMERO DO EVENTO: ");
	scanf("%d", &verifica);
	printf("\n");


	while((verifica != 0) && (i < 100))
	{
		
		for(h=0; h<j; h++) {
			if(cod[h]==verifica){
			printf("\nCODIGO JA CADASTRADO(0-SAIR)\nDIGITE OUTO CODIGO: ");
			h++;
			scanf("%d", &verifica);
	   	   	printf("\n");
			}
		}

		cod[i] = verifica;

		printf( "CPF DO CLIENTE: ");
		scanf("%d", &cpf[i]);
		//printf("\n");

		printf("\nVALOR TOTAL DO EVENTO: ");
		scanf("%d", &valor[i]);
		printf("\n");
		
		i++ ;
		j=i;
		
		system ("cls");
		
		printf("\n*****************************");

		printf("\nCADASTRO DE EVENTO\n");

		printf("\nNUMERO DO EVENTO(0-SAIR) :");
		scanf("%d", &verifica);
		printf("\n");
		
		
		
		

	}

}


void listar()
{	
	selesction(cod,cpf,valor,i);
	
	int x;
	system ("cls");
	printf("\n*****************************\n");
	printf("\nEVENTOS");

	printf("\nNUMERO \tCPF \tVALOR \n");

	printf("\n");
	for(x = 0; x < i; x++)
	{
		if(cod[x] != NULL)
		{
			printf("\n%d \t%d \t%d\n", cod[x], cpf[x], valor[x]);
		}
	}
	printf("\n\n");
	system("pause");
}



int buscaBinaria (int cod[], int n, int x)
{

	int e = -1, d = n;

	while(e < d - 1)
	{
		int m = (e + d) / 2;
		if(cod[m] < x) e = m;
		else
			d = m;
	}
	if (d == n)	return -1;
	else  return d ;
}


void selesction(int cod[], int preco[], int qtd[], int n)
{
	int menor, aux1, aux2, aux3, i , j ;

	for (i = 0; i < n - 1; i++)
	{
		menor = i;
		for(j = i + 1; j < n; j++)
		{
			if(cod[j] < cod[menor])
				menor = j;
		}
		if(i != menor)
		{
			aux1 = cod[i];
			cod[i] = cod[menor];
			cod[menor] = aux1;

			aux2 = preco[i];
			preco[i] = preco[j];
			preco[j] = aux2;

			aux3 = qtd[i];
			qtd[i] = qtd[j];
			qtd[j] = aux3;

		}
	}
}





void consultar ()
{

	system ("cls");
	int eve;

	printf( "\n*******************\n\n");
	printf( "\nNUMERO DO EVENTO: ");
	scanf("%d", &eve);
	printf( "\n");
	
	int b = buscaBinaria(cod, i, eve);
	system ("cls");
	while (eve != 0)
	{
	//	printf("B = %d\n",b);
		if(b == -1) printf("\nEVENTO NAO CADASTRADO\n");
		else printf("\n********************************\nCODIGO \tCPF \t PRECO  \n%d\t %d\t %d\n", cod[b], cpf[b] , valor[b]);
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		
		printf( "\nNUMERO DO EVENTO: ");
		scanf("%d", &eve);
		b = buscaBinaria(cod, i, eve);
		
		printf("\n");
	}
}

void alterar()
{
	int alt;
	system ("cls");
	listar();
	printf( "\nALATERACAO DE DADOS \n" );





	while (alt != 0)
	{
		printf("\nNUMERO DO EVENTO: ");
		scanf("%d", &alt);
		printf("\n");
		
		int b = buscaBinaria(cod, i, alt);
		if (b != -1)
		{

			system ("cls");
			printf("\nCPF: ");
			scanf("%d", &cpf[b]);
			printf("\n");
			printf("Valor: ");
			scanf("%d", &valor[b]);
			printf("\n");

			system ("cls");

			printf("\nALATERACAO DE DADOS\n");
			printf("\n*****************************\n");

			printf("\nNUMERO DO EVENTO: ");
			scanf("%d", &alt);
			printf("\n");

		}
		else
		{
			printf("\nEVENTO NAO CADASTRADO\n");
			system ("cls");
		}
	}
}



void apagar(int cod[], int i)
{
	int q, posicao ;

	for(q = 0; q < i; q++)
	{
		printf("\nPOSICAO = %d\tN EVENTO: %d\tCPF: %d\tvalor: %d\n", q + 1 , cod[q] , cpf[q], valor[q]);
	}



	printf("\nPOSICAO PARA DELETAR(0-sair): \n");
	scanf("%d", &posicao);
	while(posicao != 0)
	{	
		system ("cls");
		cod[posicao - 1] = NULL;
		cpf[posicao - 1] = NULL;
		valor[posicao - 1] = NULL;

		for(q = 0; q < i; q++)
		{
			if(cod[q] != NULL)
				printf("\n POSICAO = %d \tCODIGO = %d\tCPF: %d \tVALOR: %d\n", q + 1 , cod[q] , cpf[q], valor[q]);

		}
		
		printf("\nPOSICAO PARA DELETAR(0-sair): \n");
		scanf("%d", &posicao);

	}




}




int main()
{
	
	int opcao;
	while (opcao != 0)
	{
		system("cls");
		printf("\n**********************************************\n");
		printf("* ***********   *******  ***   *   ***   **  *\n");
        printf("* ***  **  **   **       ** *  *   ***   **  *\n");
	   	printf("* ***  **  **   *******  **  * *   ***   **  *\n");
	   	printf("* ***  **  **   **       **   **   ***   **  *\n");
	   	printf("* ***  **  **   *******  **    *   ********  *\n");
		printf("**********************************************\n");
		printf("\n");
		printf("0 - SAIR\n");
		printf("1 - CADASTRAR EVENTO\n");
		printf("2 - MOSTRAR\n");
		printf("3 - CONSULTAR\n");
		printf("4 - ALTERAR\n");
		printf("5 - APAGAR\n");

		printf("\n");
		printf("ECOLHA UMA OPCAO: ");

		scanf("%d", &opcao);
		system ("cls");


		switch (opcao)
		{
		case 0:
			system("exit");
			break;

		case 1:
			incluir();
			break;

		case  2:
			listar();
			break;

		case  3:
			consultar();
			break;


		case  4:
			alterar();
			break;

		case  5:
			apagar(cod, i);

		}

	}
	return 0;
	system("pause");
}
