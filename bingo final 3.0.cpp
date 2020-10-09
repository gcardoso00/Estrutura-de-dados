#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);//valores aleatorios no j em relacao a i
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}

int main() {
	
printf("*******************************************************************************\n\n");
printf("===============================================================================\n\n");
printf("*******************************************************************************\n\n");
printf("                                                                               \n\n");
printf("  _______________   _   _          _   ____________________     _______________\n");
printf(" |_  ___________ | |_| | \\        | | |   ______________   |  |               |\n");
printf("   | |         | |  _  | |\\       | | |  |              |__|  |    _______    |\n");
printf("   | |         | | | | | | \\      | | |  |                    |   |       |   |\n");
printf("   | |_________| | | | | |  \\     | | |  |       ___________  |   |       |   |\n");
printf("   |  _________  | | | | |   \\    | | |  |      |_________  | |   |       |   |\n");
printf("   | |         | | | | | |    \\   | | |  |                | | |   |       |   |\n");
printf("   | |         | | | | | |     \\  | | |  |                | | |   |_______|   |\n");
printf(" __| |_________| | | | | |      \\ | | |  |________________| | |               |\n");
printf("|________________| |_| |_|       \\|_| |_____________________| |_______________|\n");
printf("                                                                               \n\n");
printf("*******************************************************************************\n\n");
printf("===============================================================================\n\n");
printf("*******************************************************************************\n\n");

system ("pause");
	printf("\n");
    srand(time(NULL));//numero aleatorio
    int p1 = 0;
    int p2 = 0; 
    int c1[4][4], c2[4][4];//cartelas
    int numbers[50];//vetor dos numeros sorteados
    printf("\n\nJOGADOR 1 \n\n");
	for (int i = 0; i < 50; i++) numbers[i] = i + 1;//numero aleatorio na cartela 
    shuffle(numbers, 50);//embaralha numeros 
    for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
             c1[i][j] = numbers[i * 4 + j];//, gera e nao repete valores
             printf("%i\t", c1[i][j]);
         }
         printf("\n");
    }
    printf("\n");
    printf("\n\nJOGADOR 2\n\n");
    shuffle(numbers, 50);
    for (int i = 0; i < 4; i++) {// gera e nao repete valores
         for (int j = 0; j < 4; j++) {
             c2[i][j] = numbers[i * 4 + j];
             printf("%i\t", c2[i][j]);
         }
         printf("\n");
    }
    printf("\n");
    printf("NUMEROS SORTEADOS = ");
    shuffle(numbers, 50);// embaralha numero ate 50
    for (int k = 0; k < 50 && (p1 <= 16 || p2 <= 16); k++) {//condicao do sroteio ,menor q 50; p1 ou p2 menor igual 16
        int sorteio = numbers[k];//vetor numeros recebe numero sorteado
        printf ("%i ", sorteio);
        _sleep(1000);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c1[i][j] == sorteio) p1++;// gera ponto para numero da cartela igual ao sorteio
                if (c2[i][j] == sorteio) p2++;
            }
        }
    }
    if (p1 == 16) printf("\nBingo!\n\nJogador 1 ganhou\n\n");//condicao de vitoria
    else if (p2 == 16) printf("\nBingo!\n\nJogador 2 ganhou\n\n");
    else printf("\nempate");
system("pause");
}
