//tabela hash
/*
Faça a implementação dos algoritmos de inserção - busca - remoção e ordenação para uma Tabela Hash com 4 posições para receber um conjunto de 9 chaves reais K.
O algoritmo deverá exibir para o usuário a opção de tratamento de colisão por encadeamento. Apresentar o nível de complexidade.
*/
#include<stdio.h>
#include<stdlib.h>
#define K 9
#define TAMANHO 4

typedef struct no {
    double item;
    struct no *prox;
}NO;

int funcao(double chave) 
{
    return abs(chave) % 4;
}
void insercaoLista(double item, NO **tabela)
{
    int pos;
    pos = funcao(item);
    NO **lista = &tabela[pos];
    if(*lista == NULL) {
        *lista = (NO*)malloc(sizeof(NO));
        if(*lista == NULL) {
            printf("\nAVISO: ocorreu um erro!");
            exit(1);
        }
        (*lista)->item=item;
        (*lista)->prox=NULL;
        printf("-Inserido em [%d]\n", pos);
    }
    else
    {
        int op=-1;
        printf("-Ocorreu uma colisao, deseja tratar com lista encadeada?\n1)Sim\n0)Nao\nOpcao: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: {
                NO *aux=tabela[pos];
                while((*lista)->prox != NULL)
                    *lista=(*lista)->prox;
                (*lista)->prox=(NO*)malloc(sizeof(NO));
                if((*lista)->prox == NULL) {
                    printf("\nAVISO: ocorreu um erro!");
                    exit(1);
                }
                *lista=(*lista)->prox;
                (*lista)->item=item;
                (*lista)->prox=NULL;
                
                tabela[pos]=aux;
                printf("\nElemento inserido na lista encadeada!");
            }break;
            case 0: {
                printf("\nAVISO: estouro da memoria, elemento nao foi inserido");
            }break;
            default: printf("\nOpcao invalida!"); break;
        }
    }
}
int busca(double chave, NO **tabela)
{
    int pos=funcao(chave);
    NO *lista=tabela[pos];
    while(lista!=NULL) {
        //retorna 1 se a chave foi encontrada
        if(chave == lista->item)
            return 1;
        lista = lista->prox;
    }
    return 0;
}
void insercao(double item, NO **tabela)
{
    int pos;
    pos = funcao(item);
    if(tabela[pos]!=NULL) {
        if(busca(item, tabela)) {
            printf("\nAVISO: ja existe um item %.lf na tabela!", item);
            return;
        }
    }
    insercaoLista(item, tabela);
}
void imprime(NO **tabela) 
{
    int i;
    printf("\nImprimindo tabela hash");
    for(i=0; i<TAMANHO; i++) {
        printf("\nHASH[%d]: ", i);
        NO *lista = tabela[i];
        while(lista != NULL) {
            printf(" %.2lf =>", lista->item);
            lista=lista->prox;
        }
        printf(" NULL");
    }
}
void libera(NO **tabela) 
{
    int i;
    NO *aux;
    for(i=0; i<TAMANHO; i++) {
        NO **lista = &tabela[i];
        //liberando a memoria
        while(*lista != NULL) {
            aux = (*lista)->prox;
            free(*lista);
            *lista = aux;
        }
    }
    free(aux);
}
void deleta(double chave, NO **tabela)
{
    int pos = funcao(chave);
    if(!busca(chave, tabela)) {
        printf("\nAVISO: item nao foi encontrado!");
        return;
    }
    NO **lista = &tabela[pos];
    NO *previo = *lista;
    NO *proximo = (*lista)->prox;
    NO *aux = tabela[pos]; //guarda a posicao do ponteiro
    while(*lista != NULL) {
        if((*lista)->item == chave) { //verifica se encontrou
            if(*lista == previo) { //item esta no inicio da lista
                if((*lista)->prox == NULL) { //lista so tem um item
                    free(*lista);
                    tabela[pos]=NULL;
                }
                else {
                    (*lista)->prox=proximo->prox;
                    (*lista)->item=proximo->item;
                    tabela[pos]=aux;
                }
            }
            else { //item nao esta no inicio
                previo->prox=proximo;
                free(*lista);
                tabela[pos]=aux;
            }
            return;
        }
        previo=*lista;
        *lista=(*lista)->prox;
        proximo=(*lista)->prox;
    }
    tabela[pos]=aux;
    free(previo);
    free(proximo);
    free(aux);
}
int main() 
{
    //declaracao de variaveis
    int i;
    double item;
    NO *tabela[TAMANHO];
    //inicializando tabela hash
    for(i=0; i<TAMANHO; i++)
    tabela[i]=NULL;
    //menu inicial
    printf("\n\n---TABELA HASH 9 CHAVES---");
    printf("\nInicializando a tabela...");
    for(i=0; i<K; i++) {
        printf("\nElemento [%d]: ", i+1);
        scanf("%lf", &item);
        insercao(item, tabela);
    }
    imprime(tabela);

    printf("\nDeletando elementos da tabela...");
    while(1) {
        printf("\nDigite o item a ser deletado (0 para sair): ");
        scanf("%lf", &item);
        if(item == 0)
            break;
        deleta(item, tabela);
        imprime(tabela);                    
    }                

    libera(tabela);
    return 0;
}