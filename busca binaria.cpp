#include <stdio.h>
#include <stdlib.h>

int buscaBinaria (int *v, int n,int num){
	int i, inicio, meio, final;
	inicio = 0;
	final = n-1;
	while(inicio <=final){
		meio = (inicio + final)/2;
		if(num < v[meio]){
			final = meio-1;
		}
		else{
			if(num >v[meio]){
				inicio = meio+1;
			}
			else{
				return meio;
			}
		}
		
	}
	return -1;
	
}

int main(){
	int v[10] = {1,2,3,4,5,6,7,8,9,10};
	int x = 5;
	if(buscaBinaria(v,10,5) != -1  ){
		printf("Ok\n");
	}
	else{
		printf("Nao\n");
	}
	return 0;
	
}
