#include <stdlib.h>
#include <stdio.h>


int bubble(int *vet, int n){
	
	int  aux,i , j;	    
		
	for(i=0;i<5;i++){
    	for(j=i;j<5;j++){
    		
			if(vet[i]>vet[j]){
				
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			
			}
		}	
	}
	return 1;
	
}

int main(){
	int vet[]={5,3,2,4,1}, n,i;
	
	printf("tamanho do vetor");
	scanf("%d",&n)	;
	
	bubble(vet,n);
	
	for(i = 0; i < n; i++){
        printf("%d ",vet[i]);
	}
}
