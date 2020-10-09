//Gustavo Cardoso da Conceicao - Estrutura de dados 1
//Programa para um carrinho de compras, registra nome e quantidade,busca pelo nome, deleta alguma posicao


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BUFFER 64




typedef struct lista {
    char *nome;
    int qtd;
    struct lista *proximo;
}Carrinho;

Carrinho *inicia_carrinho  (char *nome, int qtd);
Carrinho *insere_carrinho  (Carrinho *carrinho, char *nome, int qtd);
Carrinho *delbusca_carrinho(Carrinho *carrinho, char *chave);
Carrinho *deleta_carrinho  (Carrinho *carrinho, int nTipo);
int   checa_vazio    (Carrinho *carrinho); 
void  exibe_carrinho    (Carrinho *carrinho);
void  busca_carrinho    (Carrinho *carrinho, char *chave);
void criavazia(void);    
void insereinicio(void); 
void inserefim(void);   
void listavazia(void); 
void exibe(void);       
void delbusca(void);
void busca(void);

Carrinho *principal = NULL;

void criavazia(void){
    char *nome;
    int qtd;
    nome = (char *)malloc(BUFFER);
    fprintf(stdout, "\n\nDigite o Nome do produto:\n");
    scanf("%s", nome);
    fprintf(stdout, "\n");
    fprintf(stdout, "Digite a quantidade:\n");
    scanf("%d", &qtd);
    fprintf(stdout, "\n");
    free(principal);
    principal = inicia_carrinho(nome, qtd);
}
 

Carrinho *inicia_carrinho(char *nome, int qtd) {
    Carrinho *novo;
    novo = (Carrinho *)malloc(sizeof(Carrinho));
    
    novo->nome = (char *)malloc(strlen(nome)+1);
    strncpy(novo->nome, nome, strlen(nome)+1);
    novo->qtd = qtd;
    novo->proximo = NULL;
    return novo;
}

void insereinicio(void){
    char *nome;
    int qtd;

    nome = (char *)malloc(BUFFER);
    
    fprintf(stdout, "\n\nDigite o Nome do produto: \n");
    scanf("%s", nome);
    fprintf(stdout, "\n");
    fprintf(stdout, "Digite a quantidade: \n");
    scanf("%d", &qtd);
    fprintf(stdout, "\n");
    principal = insere_carrinho(principal, nome, qtd);
}
 
Carrinho *insere_carrinho(Carrinho *carrinho, char *nome, int qtd) {
    Carrinho *inicio;
    inicio = (Carrinho *)malloc(sizeof(Carrinho));
    inicio->nome = (char *)malloc(strlen(nome)+1);
    strncpy(inicio->nome, nome, strlen(nome)+1);
    inicio->qtd = qtd;
    inicio->proximo = carrinho;
    return inicio;
}

void inserefim(void) {
    char *nome;
    int qtd;
    nome = (char *)malloc(BUFFER);
    fprintf(stdout, "\n\nDigite o Nome do produto: \n");
    scanf("%s", nome);
    fprintf(stdout, "\n");

    fprintf(stdout, "Digite a quantidade: \n");
    scanf("%d", &qtd);
    fprintf(stdout, "\n");    
    Carrinho *final,*aux;
    final = (Carrinho *)malloc(sizeof(Carrinho));
    final->nome = (char *)malloc(strlen(nome)+1);
    strncpy(final->nome, nome, strlen(nome)+1);
    final->qtd = qtd;
    final->proximo=NULL;
    aux=principal;
    while(aux->proximo!=NULL){
        aux=aux->proximo;
    }

    aux->proximo=NULL;
    aux->proximo=final;
}

void listavazia(void){
    if (principal == NULL) 
        fprintf(stdout, "\n\nCarrinho vazio\n\n ");
    else
        fprintf(stdout, "\n\nCarrinho nao esta vazio!\n\n ");
    getchar();
}

void exibe(void) {
    if (!checa_vazio(principal))
        exibe_carrinho(principal);
}
 
void exibe_carrinho(Carrinho *carrinho) {
    fprintf(stdout, "Carrinho de compra:\n\n");
    for (; carrinho != NULL; carrinho = carrinho->proximo) {
        fprintf(stdout, "Nome do produto: %s\n", carrinho->nome);
        fprintf(stdout, "Quantidade: %d\n\n", carrinho->qtd);
    }
    getchar();
}

void delbusca(void) {
    char *chave;
    if (!checa_vazio(principal)) {
        chave = (char *)malloc(BUFFER);
        fprintf(stdout, "Nome do produto para apagar:\n");
        scanf("%s", chave);

        principal = delbusca_carrinho(principal, chave);
    }
}
 

Carrinho *delbusca_carrinho(Carrinho *carrinho, char *chave) {
    int achou=0,cont=0;
    Carrinho *juntou, *aux, *nova=carrinho;        
 
    for (; nova != NULL; nova = nova->proximo) {
        if (strcmp(chave, nova->nome) == 0) {
            achou=1;
            cont++;
        }
    }
 

    if(achou==1){
        int ind=0;
        for(ind=0;ind<cont;ind++){
            if(strcmp(chave,carrinho->nome)==0){
                aux=carrinho;
                carrinho=carrinho->proximo;
                free(aux);
            }
            else{
                aux=carrinho;

                while(strcmp(chave,aux->nome)!=0){
                    aux=aux->proximo;
                }
 
                juntou=carrinho;
                while(juntou->proximo!=aux){
                    juntou=juntou->proximo;
                }
                juntou->proximo=aux->proximo;
 
                free(aux);
            }
        }
        fprintf(stdout, "Excluido\n");
    }
    else
        fprintf(stdout, "Nao existe\n");
 
    getchar();
    return carrinho;
}

void busca(void) {
    char *chave;
    if (!checa_vazio(principal)) {
        chave = (char *)malloc(BUFFER);
        fprintf(stdout, "\nNome para buscar: \n");
        scanf("%s", chave);
        busca_carrinho(principal, chave);
    }
}
 
void busca_carrinho(Carrinho *carrinho, char *chave) {
    int achou = 0;
    fprintf(stdout, "\nCarrinho:\n\n");
    for (; carrinho != NULL; carrinho = carrinho->proximo) {
        if (strcmp(chave, carrinho->nome) == 0) {
            fprintf(stdout, "Nome do produto: %s\n", carrinho->nome);
            fprintf(stdout, "Quantidade: %d\n\n", carrinho->qtd);
            achou++;
        }
    }
 
    if (achou == 0)
        fprintf(stdout, "Nao existe\n");
    getchar();
} 

int checa_vazio(Carrinho *carrinho) {
    if (carrinho == NULL) {
            fprintf(stdout, "Lista vazia!\n");
            getchar();
            return 1;
    } else
            return 0;
}

 
int main(void) {
    char escolha;
    int chave=0;
    do {
        system("cls");
        fprintf(stdout, "\n\tCarrinho de Compra\n\n");
        fprintf(stdout, "Escolha uma opcao: \n");
        fprintf(stdout, "1 - Criar novo carrinho\n");
        
        if(chave==1){
            fprintf(stdout, "2 - Inserir no comeco\n");
            fprintf(stdout, "3 - Inserir no final\n");
        } 
        if(chave==1){
            fprintf(stdout, "4 - Exibir todos os valores da Lista\n");
            fprintf(stdout, "5 - Eliminar elemento buscado\n");
            fprintf(stdout, "6 - Busca carrinho\n");
        }
        fprintf(stdout, "s - Sair\n\n");
        fprintf(stdout, "Resposta: ");
        scanf("%c", &escolha);
        if((chave==0)&&((escolha!='1')&&(escolha!='s')))
            escolha='z';
 
        switch(escolha) {
            case '1':
                chave=1;
                criavazia(); 
                break;      
            case '2':
                insereinicio();
                break;                   
            case '3':     
                if(principal!=NULL){
                    inserefim();
                }              
                else{
                    insereinicio();
                }
                break;
            case '4':
                exibe();
                break;
            case '5':
                delbusca();
                break;                
            case '6':
                busca();
                break;
            case 's':
                exit(0);
                break;
            default:
                fprintf(stderr,"Opcao invalida !\n");
                getchar();
                break;
        }
        getchar();
    }
    while (escolha > 0);
    return 0;
}
