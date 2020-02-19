#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[5]={1,50,100,3,78};
    int aux = 0;
    
    
    for(int i=0;i<5;i++){
    	for(int j=i;j<5;j++){
    		if(vet[i]>vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			
			}
		}
    	
	}
    
    
    for(int i = 0; i < 5; i++){
        printf("%d ",vet[i]);
    }
}
