#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int num;
    struct node *esq;
    struct node *dir;
}NO;
//criando um novo no na arvore
NO *novoNo(int num) {
    NO *novo = (NO*)malloc(sizeof(NO));
    novo->num=num;
    novo->esq=NULL;
    novo->dir=NULL;
    return novo;
}
//imprime a arvore em ordem
void emOrdem(NO *raiz) {
    if(raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d -> ", raiz->num);
        emOrdem(raiz->dir);
    }
}
//inserindo novo no na arvore
NO *insereNo(NO *novo, int num) {
    //se a arvore esta vazia cria um novo no
    if(novo == NULL)
        return novoNo(num);
    if(num < novo->num)
        novo->esq=insereNo(novo->esq, num);
    else    
        novo->dir = insereNo(novo->dir, num);
    return novo;
}
//busca pela folha mais a esquerda (menor)
NO *encontraMenor(NO *no) {
    NO *atual = no;
    while(atual && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}
//buscando no pela direita e pela esquerda
NO *buscaNo(NO *raiz, int num) {
    if(raiz == NULL || raiz->num==num)
        return raiz;
    //verifica se o elemento buscado e maior que a raiz (direita)
    if(raiz->num < num) {
        if(raiz->dir == NULL) {
            printf("\nNao foi possivel encontrar o elemento [%d].", num);
            return NULL;
        }
        else {
            return buscaNo(raiz->dir, num);
        }
    }
    //verificando o lado esquerdo
    if(raiz->esq == NULL) {
        printf("\nNao foi possivel encontrar o elemento [%d].", num);
        return NULL;    
    }
    else {
        return buscaNo(raiz->esq, num);
    }
}
//deletando o no da arvore
NO *deletaNo(NO *raiz, int num) {
    //verifica se a arvore esta vazia
    if(raiz == NULL) 
        return raiz;
    //encontrou o no 
    if(num < raiz->num)
        raiz->esq = deletaNo(raiz->esq, num);
    else if(num > raiz->num)
        raiz->dir = deletaNo(raiz->dir, num);
    else {
        //se nao tem filho ou apenas um
        if(raiz->esq == NULL) {
            NO *aux = raiz->dir;
            free(raiz);
            return aux;
        }
        else if(raiz->dir == NULL) {
            NO *aux = raiz->esq;
            free(raiz);
            return aux;
        }
        //se tem dois filhos
        NO *aux = encontraMenor(raiz->dir);
        raiz->num = aux->num;
        raiz->dir = deletaNo(raiz->dir, aux->num);
    }
    return raiz;
}
int main() {
    int op=-1;
    int elem;
    //inicializa a arvore vazia e adiciona os nos
    NO *raiz=NULL;
    raiz=insereNo(raiz, 50);
    insereNo(raiz, 17);
    insereNo(raiz, 12);
    insereNo(raiz, 14);
    insereNo(raiz, 23);
    insereNo(raiz, 19);
    insereNo(raiz, 72);    
    insereNo(raiz, 76);
    insereNo(raiz, 54);
    insereNo(raiz, 67);
    insereNo(raiz, 9);

    //laço para o menu
    do {
        printf("\n\n---MENU DE OPCOES---");
        printf("\n1) Inserir novo elemento");
        printf("\n2) Deletar elemento");
        printf("\n3) Buscar elemento");
        printf("\n4) Imprime arvore em ordem");
        printf("\n0) Sair\nOpcao: ");
        scanf("%d", &op);
        switch(op){
            case 1: {
                printf("\n-Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                insereNo(raiz, elem);     
                printf("\nElemento [%d] inserido!\n", elem);
                emOrdem(raiz);
            }break;
            case 2: {
                printf("\n-Digite o elemento a ser deletado: ");
                scanf("%d", &elem);
                deletaNo(raiz, elem);
                printf("\nElemento [%d] removido!\n", elem);
                emOrdem(raiz);
            }break;
            case 3: {
                printf("\n-Digite o elemento a ser buscado: ");
                scanf("%d", &elem);
                printf("\n");
                emOrdem(raiz);
                NO *busca = buscaNo(raiz, elem);
                if(busca != NULL)
                    printf("\nElemento [%d] encontrado!", busca->num);
            }break;
            case 4: {
                printf("\n-Imprimindo em ordem-\n");
                emOrdem(raiz);
            }break;
            case 0: printf("\nSaindo do sistema..."); break;
            default: printf("\nAVISO: Opcao invalida!"); break;
        }
    }while(op!=0);
}