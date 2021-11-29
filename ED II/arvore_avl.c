#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int num;
    int alt;
    struct node *esq;
    struct node *dir;
}NO;
//imprime a arvore em ordem
void emOrdem(NO *raiz) {
    if(raiz == NULL) {
        return;
    }
    else {
        printf("%d -> ", raiz->num);
        emOrdem(raiz->esq);
        emOrdem(raiz->dir);
    }
}
//criando um novo no na arvore
NO *novoNo(int num) {
    NO *novo = malloc(sizeof(NO));
    novo->num = num;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->alt = 1;
    return novo;
}
//calcula altura que o no esta
int calculaAltura(NO *node) {
    if(node == NULL)
        return 0;
    return node->alt;
}
//calculo do maior elemento
int calculaMaior(int x, int y) {
    if(x > y)
        return x;
    return y;
}
//balanceando o no
int balanceamento(NO *node) {
    int aux;
    if(node == NULL) 
        return 0;
    aux=calculaAltura(node->esq)-calculaAltura(node->dir);
    return aux;
}
//rotacionamento a esquerda
NO *rotacionaEsquerda(NO *X) {
    NO *Y = X->dir; //Y recebe o filho da direita de x
    NO *T2 = Y->esq; //T2 recebe o filho da direita de Y

    Y->esq = X;
    X->dir = T2;

    //atualizando as alturas
    int xe = calculaAltura(X->esq);
    int xd = calculaAltura(X->dir);
    int ye = calculaAltura(Y->esq);
    int yd = calculaAltura(Y->dir);
    X->alt = calculaMaior(xe, xd)+1;
    Y->alt = calculaMaior(ye, yd)+1;

    return Y;
}
//rotacionamento a direita
NO *rotacionaDireita(NO *Y) {
    NO *X = Y->esq; //X recebe o filho da esquerda de Y
    NO *T2 = X->dir; //T2 recebe o filho da direita de X

    X->dir = Y;
    Y->esq = T2;

    //atualizando as alturas
    int xe = calculaAltura(X->esq);
    int xd = calculaAltura(X->dir);
    int ye = calculaAltura(Y->esq);
    int yd = calculaAltura(Y->dir);
    X->alt = calculaMaior(xe, xd) + 1;
    Y->alt = calculaMaior(ye, yd) + 1;    

    return X;
}
//inserindo novo no na arvore
NO *insereNo(NO *node, int num) {
    //cria novo no se a arvore esta vazia
    if(node == NULL)
        return(novoNo(num));

    //verificacao para inserir o no corretamente
    if(num < node->num)
        node->esq=insereNo(node->esq, num);
    else if(num > node->num)
        node->dir=insereNo(node->dir, num);
    else
        return node;
    
    //atualizando a altura do no
    int altE = calculaAltura(node->esq);
    int altD = calculaAltura(node->dir);
    node->alt = calculaMaior(altE, altD) + 1;
    
    //balanceando a arvore
    int aux = balanceamento(node);
    //rotaciona a direita se o aux for menor que o filho da esquerda
    if(aux>1 && num<node->esq->num)
        return(rotacionaDireita(node));
    
    //rotaciona a esquerda se o aux for maior que o filho da direita
    if(aux<-1 && num>node->dir->num)
        return(rotacionaEsquerda(node));

    //aux > 1 o filho da esquerda rotaciona para a esquerda
    if(aux>1 && num>node->esq->num) {
        node->esq=rotacionaEsquerda(node->esq);
        return rotacionaDireita(node);
    }

    //aux < -1 o filho da direita rotaciona para a direita
    if(aux<-1 && num<node->dir->num) {
        node->dir=rotacionaDireita(node->dir);
        return rotacionaEsquerda(node);
    }
    return node;
}
int main() {
    //inicializa a arvore vazia e adiciona os nos
    NO *raiz = NULL;
    raiz = insereNo(raiz, 50);
    raiz = insereNo(raiz, 17);
    raiz = insereNo(raiz, 76);
    raiz = insereNo(raiz, 9);
    raiz = insereNo(raiz, 23);
    raiz = insereNo(raiz, 54);
    raiz = insereNo(raiz, 14);
    raiz = insereNo(raiz, 19);
    raiz = insereNo(raiz, 72);
    raiz = insereNo(raiz, 12);
    raiz = insereNo(raiz, 67);
    printf("\nImprimindo a arvore em ordem: \n");
    emOrdem(raiz);
    return 0;
}