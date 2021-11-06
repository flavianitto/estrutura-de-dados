#include<stdio.h>
#include<stdlib.h>

typedef struct noh {
  int num;
  struct noh* esquerda;
  struct noh* direita;
} noh;

//cria um novo nó
noh* novonoh(int num){
  struct noh *novo = (struct noh*)malloc(sizeof(struct noh));
  novo->num = num;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}
//insere um novo nó
noh* inserir(noh **raiz, int num){
  //se vazia
  if (*raiz == NULL)
    return novonoh(num);
  //se não vazia, se aprofundar até encontrar um local para inserir.
  if ((*raiz)->num > num)
    (*raiz)->esquerda = inserir(&(*raiz)->esquerda,num);
  else if ((*raiz)->num <= num)
    (*raiz)->direita = inserir(&(*raiz)->direita,num);
  return *raiz;
}

//encontra um nó
noh* encontrar(noh **raiz, int num){
  //se a raiz estiver vazia, ou se a pesquisa quiser encontrar a raiz.
  if (*raiz == NULL || (*raiz)->num == num)
    return *raiz;
  
  //se o numero for maior que a raiz, vai para a direita
  if ((*raiz)->num < num){
    //se não tiver filhos a direita, então o numero não se encontra na arvore.
    if((*raiz)->direita==NULL){
      printf("Numero nao encontrado.\n");
      return NULL;
    }
    else
      return encontrar(&(*raiz)->direita,num);
  }

  //se não, vai para a esquerda.
  //se não tiver filhos a esquerda, então o numero não se encontra na arvore.
  if((*raiz)->esquerda==NULL){
    printf("Numero nao encontrado.\n");
    return NULL;
  }
  else
    return encontrar(&(*raiz)->esquerda,num);
}

//retorna o menor nó da arvore.
noh* menorNoh(noh **auxnoh){
  noh *atual = *auxnoh;
  while (atual && atual->esquerda != NULL)
    atual = atual->esquerda;
  return atual;
}

//remove um nó
noh* remover(noh **raiz,int num){
  //se a arvore estiver vazia
  if (*raiz == NULL)
    return *raiz;

  //se for menor que a raiz, então está à esquerda.
  if (num < (*raiz)->num)
    (*raiz)->esquerda = remover(&(*raiz)->esquerda,num);

  //se for maior que a raiz, então está à direita.
  else if (num > (*raiz)->num)
    (*raiz)->direita = remover(&(*raiz)->direita,num);

  //ao encontrar o nó
  else {
    //se o nó só tiver um filho ou nenhum.
    if ((*raiz)->esquerda == NULL) {
      noh *aux = (*raiz)->direita;
      free(*raiz);
      return aux;
    }
    else if ((*raiz)->direita == NULL) {
      noh *aux = (*raiz)->esquerda;
      free(*raiz);
      return aux;
    }
    //se tiver dois flhos, pega o menor da subarvore a direita.
    noh *aux = menorNoh(&(*raiz)->direita);

    //copie o menor
    (*raiz)->num = aux->num;

    //remova o menor
    (*raiz)->direita = remover(&(*raiz)->direita, aux->num);
  }
  return *raiz;
}



//printa a arvore em ordem
void em_ordem(noh **raiz){
  if (*raiz != NULL) {
    em_ordem(&(*raiz)->esquerda);
    printf("%d\n",(*raiz)->num);
    em_ordem(&(*raiz)->direita);
  }
}

//printa em pós_ordem
void pos_ordem(noh **raiz){
  if (*raiz == NULL)
    return;

  //primeiro fazer recursão no lado esquerdo
  pos_ordem(&(*raiz)->esquerda);

  //depois no direito
  pos_ordem(&(*raiz)->direita);

  printf("%d\n", (*raiz)->num);
}

//printa em pré_ordem
void pre_ordem(noh **raiz)
{
  if (*raiz == NULL)
    return;

  //primeiro printar o numero
  printf("%d\n", (*raiz)->num);

  //depois aplicar recursão à esquerda.
  pre_ordem(&(*raiz)->esquerda);

  //depois à direita.
  pre_ordem(&(*raiz)->direita);
}

//para se esvaziar, utiliza-se a pós-ordem.
void esvaziar(noh **raiz){
  if (*raiz == NULL)
    return;

  //primeiro fazer recursão no lado esquerdo
  esvaziar(&(*raiz)->esquerda);

  //depois no direito
  esvaziar(&(*raiz)->direita);

  printf("%d apagado.\n", (*raiz)->num);
  *raiz=NULL;
  free(*raiz);
}


void main(){
  noh *raiz = NULL;

  raiz = inserir(&raiz, 35);
  inserir(&raiz, 48);
  inserir(&raiz, 12);
  inserir(&raiz, 83);
  inserir(&raiz, 17);
  inserir(&raiz, 60);
  inserir(&raiz, 12);
  inserir(&raiz, 90);
  inserir(&raiz, 48);
  inserir(&raiz, 11);
  // em_ordem(&raiz);
  // printf("/----/\n");
  // raiz=remover(&raiz,6);
  
  em_ordem(&raiz);
  printf("/-------/\n");
  pos_ordem(&raiz);
  printf("/--------/\n");
  pre_ordem(&raiz);
  printf("/------/\n");
  esvaziar(&raiz);

  // noh *achado=encontrar(&raiz,6);
  // if(achado!=NULL)
  //   printf("Achado: %d\n",achado->num);
}