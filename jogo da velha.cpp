#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//char quadrado[10] = {'o','1','2','3','4','5','6','7','8','9'};

char nome1[20]={'a','a'};
char nome2[20]={'b','b'};
int ponto1=0;
int ponto2=0;

	
int verificaVitoria();
void tabuleiro();


int verificaVitoria(){
	 if (quadrado[1] == quadrado[2] && quadrado[2] == quadrado[3]){
	 
        ponto1++;
		return 1;
		}
        
    else if (quadrado[4] == quadrado[5] && quadrado[5] == quadrado[6]){
        ponto1++;
		return 1;
		}
        
    else if (quadrado[7] == quadrado[8] && quadrado[8] == quadrado[9]){
        ponto1++;
		return 1;
		}
        
    else if (quadrado[1] == quadrado[4] && quadrado[4] == quadrado[7]){
        ponto1++;
		return 1;
		}
        
    else if (quadrado[2] == quadrado[5] && quadrado[5] == quadrado[8]){
        ponto1++;
		return 1;
		}
        
    else if (quadrado[3] == quadrado[6] && quadrado[6] == quadrado[9]){
        ponto1++;
		return 1;
		}
        
    else if (quadrado[1] == quadrado[5] && quadrado[5] == quadrado[9]){
        ponto1++;
		return 1;
		}
        
    else if (quadrado[3] == quadrado[5] && quadrado[5] == quadrado[7]){
        ponto1++;
		return 1;
		}
        
    else if(quadrado[1] != '1' && quadrado[2] != '2' && quadrado[3] != '3' && quadrado[4] != '4' && quadrado[5] != '5' && quadrado[6] != '6' && quadrado[7] != '7' && quadrado[8] != '8' && quadrado[9] != '9'){
		
		return 0;
		}
		
    else{
    	ponto2++;
        return -1;
		}
}

void tabuleiro(){
	system("cls");
	printf("\n\nJOGO DA VELHA\n\n");
	printf("JOGADOR 1 X  \n\nJOGADOR 2 o\n\n");
	
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n",quadrado[1],quadrado[2],quadrado[3]);

	printf("_____|_____|_____\n");	
	printf("     |     |     \n");
	
	printf("  %c  |  %c  |  %c \n",quadrado[4],quadrado[5],quadrado[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n",quadrado[7],quadrado[8],quadrado[9]);

	printf("     |     |     \n\n");
}


/*char jog1(void){
	printf("DIGITE O SEU NOME :");
	gets(nome1);	
	printf("\n");
	return nome1
}

char jog2(void){
	printf("DIGITE O SEU NOME :");
	gets(nome2);	
	printf("\n");
	return nome2;
}
*/






int main()
{
	char quadrado[10] = {'o','1','2','3','4','5','6','7','8','9'};
	int jogador = 1, i, choice;
	char mark;
	int jogar = 1;

  
  
  while((ponto1!=3)|| (ponto2!=3)){
  
  
  //coemca o jogo
    do
    {
        tabuleiro();
        jogador = (jogador % 2) ? 1 : 2;

        printf("JOGADOR %d, DIGITE UM NUMERO:  \n", jogador);
        scanf("%d", &choice);

        mark = (jogador == 1) ? 'X' : 'O';

        if (choice == 1 && quadrado[1] == '1')
            quadrado[1] = mark;
            
        else if (choice == 2 && quadrado[2] == '2')
            quadrado[2] = mark;
            
        else if (choice == 3 && quadrado[3] == '3')
            quadrado[3] = mark;
            
        else if (choice == 4 && quadrado[4] == '4')
            quadrado[4] = mark;
            
        else if (choice == 5 && quadrado[5] == '5')
            quadrado[5] = mark;
            
        else if (choice == 6 && quadrado[6] == '6')
            quadrado[6] = mark;
            
        else if (choice == 7 && quadrado[7] == '7')
            quadrado[7] = mark;
            
        else if (choice == 8 && quadrado[8] == '8')
            quadrado[8] = mark;
            
        else if (choice == 9 && quadrado[9] == '9')
            quadrado[9] = mark;
            
        else
        {
            printf("Invalido");

            jogador--;
            getch();
        }
        i = verificaVitoria();

        jogador++;
    }while (i ==  - 1);
    

    tabuleiro();
    char quadrado[10] = {'o','1','2','3','4','5','6','7','8','9'};
    
    if (i == 1){
        printf("==>\aJOGADOR  %d VENCEU \n", --jogador);
        if(jogador==1){
        	printf("%s",nome1);
        	ponto1++;
		}
		else{
			printf("%s",nome2);
			ponto2++;
		}
	}
    
	else
        printf("==>\aEMAPATE\n");

    getch();
	system("cls");
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
    return 0;
	
}
    
