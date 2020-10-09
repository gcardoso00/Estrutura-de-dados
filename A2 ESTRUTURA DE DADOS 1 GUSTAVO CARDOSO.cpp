//GUSTAVO CARDOSO DA CONCEICAO

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct dataNode{
	int id, mat;
	char nome[30];	
	
}DataNode;



typedef struct node{
	DataNode data;
	struct node* next;
	
} Node;


typedef struct list
{
	int size;
	Node* head;
		
} List;

List* createList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);
Node* atPos(List* list, int index);
int indexOf(List* list, Node* node);
void xchgNodes(List* list, Node* nodeA, Node* nodeB);
Node* max(List* lista, int index);
void decSort(List* list);
void alt(List* list, int pos);
void dados(List* list, DataNode data);


List* createList(){
	List* list = (List*) malloc(sizeof(List));
	
	list->size =0;
	list->head = NULL;
	
	return list;
	
}

void push(List* list, dataNode data){
	Node* node =(Node*) malloc(sizeof(Node));
	
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
			
}

void printList(List* list){
	system("cls");
	if(isEmpty(list)){
	   	printf("lista vazia\n");
	   	system("pause");
	   	return;
	}
	
	Node* pointer= list->head;
	
	while(pointer != NULL)
	{	
	
		printf("\n***********************\n\tLista\n");
		fprintf(stdout,"nome :%s \nmatricula :%d\nidade :%d\n\n", pointer->data.nome , pointer->data.mat, pointer->data.id);
		pointer = pointer->next;	  
				
	}
	system("pause");
}


bool isEmpty(List* list){
	return (list->size == 0);	
}

void pop(List* list){
	if (!isEmpty(list)){
		Node* pointer = list->head;
		list->head = pointer->next;
		free(pointer);
		list->size--;
		printf("\nPosicao deletada!\n\n");
		system("pause");
	}
	
}


Node* atPos(List* list, int index){
	if(index >=0 && index < list->size){
		Node* node = list->head;
		
		for(int i=0; i< index; i++)
			node = node->next;
		
		return node;
	}
		
		printf("indice invalido");
		return NULL;
	
}

int indexOf(List* list, Node* node){
	
	if(node != NULL){
		Node* pointer = list->head;
		
		int index =0;
		while(pointer != node && pointer != NULL){
			pointer = pointer->next;
			index++;
			
			
		}
		if(pointer != NULL)
  			return index;
	}
	
	printf("no nao pertence a lista\n");
	return -1;
}


void xchgNodes(List* list, Node* nodeA, Node* nodeB){
	if(nodeA == nodeB)
		return;
		
	int indexA = indexOf(list, nodeA);
	int indexB = indexOf(list, nodeB);
	
	if(indexA == -1 || indexB == -1)
		return;
	
	if(indexA > indexB){
		nodeA = nodeB;
		nodeB = atPos(list, indexA);
		
		indexA = indexB;
		indexB = indexOf(list, nodeB);
	
	}
	Node* pb = atPos(list, indexB -1);
	
	if(nodeA == list->head){
		list->head = nodeB;
	}
	else{
		Node* pa = atPos(list, indexA - 1);
		pa->next = nodeB;
	}
	
	pb->next = nodeA;
	
	Node* pointer = nodeA->next;
	nodeA->next = nodeB->next;
	nodeB->next = pointer;
	
}




Node* max(List* list, int index){
	Node* pointer = atPos(list, index);
	if(pointer != NULL){
		Node* maxNode = pointer;
		
		while(pointer != NULL)
		{
			if(pointer->data.id > maxNode->data.id)
				maxNode = pointer;
			
			pointer = pointer->next;
			
		}
		
		return maxNode;
	}
	return NULL;
}


void decSort(List* list){
	int i;
	
	for(i=0;i<list->size -1; i++){
		xchgNodes(list, atPos(list,i),max(list,i));
	}	
	
}

void alt(List* list, int pos){
	
	if(atPos(list,pos) != NULL ){
	
	Node* p = atPos(list, pos); 
	
	fprintf(stdout, "\nDigite o Nome: ");
    scanf("%s", p->data.nome);
	
	
	printf("\nidade: ");
	scanf("%d",&p->data.id);
	printf("\n");
	
	decSort(list);
}else
	printf("\nposicao nao encontrada");	
	system("pause");
}

void dados(List* list, DataNode data){
	system("cls");
	fprintf(stdout, "\nDigite o Nome: ");
    scanf("%s", data.nome);
    
	printf("\nmatricula :");
	scanf("%d",&data.mat);

	printf("\nidade :");
	scanf("%d",&data.id);
	printf("\n");
	push(list, data);
	decSort(list);

	system("pause");

}




int main()
{

	List* l = createList();
	DataNode data;
	int posicao;	
	int esc ;
	
	do{	
		system("cls");
		printf("\n0 - Sair");
		printf("\n1 - Incluir");
		printf("\n2 - Mostrar lista");
		printf("\n3 - Alterar");
		printf("\n4 - Deletar");
		printf("\nOpcao : ");
		scanf("%d", &esc);
		
		switch(esc){
			case 1:
				dados(l, data);
				break;
				
			case 2:
				printList(l);
				break;
				
			case 3:	
					system("cls");
					printf("\nPosicao : ");
					scanf("%d",&posicao);
					alt(l, posicao);	
				break;
				
			case 4:
				pop(l);
				break;
			
		}	
		
	}while(esc != 0);	
	
	system("pause");
	return 0;
}













