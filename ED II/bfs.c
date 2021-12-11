#include<stdio.h>
#include<stdlib.h>
#define N 40

struct Fila {
  int itens[N];
  int inicio;
  int fim;
};

struct No {
  int v;
  struct No* prox;
};

struct Grafo {
  int numV;
  struct No** listaAdj;
  int* visitado;
};

//criando novo no
struct No* criaNo(int vertice) {
  struct No* novo = malloc(sizeof(struct No));
  novo->v = vertice;
  novo->prox = NULL;
  return novo;
}
//criando grafo
struct Grafo* criaGrafo(int numVertices) {
  struct Grafo* novoG = malloc(sizeof(struct Grafo));
  novoG->numV = numVertices;
  novoG->listaAdj = malloc(numVertices*sizeof(struct No*));
  novoG->visitado = malloc(numVertices*sizeof(int));

  //preenchendo com zeros
  int i;
  for(i=0; i<numVertices; i++) {
    novoG->listaAdj[i]=NULL;
    novoG->visitado[i]=0;
  }
  return novoG;
}
//adicionando nova aresta
void addAresta(struct Grafo* G, int inicio, int fim) {
  //adiciona do inicio para o fim
  struct No* novo = criaNo(fim);
  novo->prox = G->listaAdj[inicio];
  G->listaAdj[inicio] = novo;

  //adiciona do fim para o inicio
  novo = criaNo(inicio);
  novo->prox = G->listaAdj[fim];
  G->listaAdj[fim] = novo;
}
//criando a fila
struct Fila* criaFila() {
  struct Fila* q = malloc(sizeof(struct Fila));
  q->inicio = -1;
  q->fim = -1;
  return q;
}
//verificacao se a fila esta vazia
int isEmpty(struct Fila* q) {
  if(q->fim == -1)
    return 1;
  else
    return 0;
}
//adicionando elementos na fila
void enfileira(struct Fila* q, int valor) {
  if(q->fim == N - 1)
    printf("\nAVISO: Fila esta cheia!");
  else {
     if(q->inicio == -1)
        q->inicio = 0;
    q->fim++;
    q->itens[q->fim] = valor;
  }
}
//removendo elementos da fila
int desenfileira(struct Fila* q) {
  int item;
  if(isEmpty(q)) {
    printf("\nAviso: Fila vazia");
    item = -1;
  }
  else {
    item = q->itens[q->inicio];
    q->inicio++;
    if(q->inicio > q->fim) {
      printf("\nResetando fila");
      q->inicio = q->fim = -1;
    }
  }
  return item;
}
//imprimindo a fila
void imprime(struct Fila* q) {
  int i = q->inicio;
  if(isEmpty(q)) 
    printf("\nAVISO: Fila vazia");
  else {
    printf("\n---Imprimindo fila--- \n");
    for(i = q->inicio; i < q->fim + 1; i++) {
      printf("[%d] => ", q->itens[i]);
    }
  }
}
//busca bfs
void bfs(struct Grafo* G, int inicialV) {
  struct Fila* q = criaFila();
  G->visitado[inicialV] = 1;
  enfileira(q, inicialV);

  while(!isEmpty(q)) {
    imprime(q);
    int atual = desenfileira(q);
    printf("\n[%d] foi visitado\n", atual);

    struct No* aux = G->listaAdj[atual];
    while(aux) {
      int adjV = aux->v;
      if(G->visitado[adjV]==0) {
        G->visitado[adjV] = 1;
        enfileira(q, adjV);
      }
      aux = aux->prox;
    }
  }
}
//main
int main() {
  int qtdV, op=-1;
  printf("\nInsira a quantidade de vertices do grafo: ");
  scanf("%d", &qtdV);
  struct Grafo* grafo = criaGrafo(qtdV);
  printf("Grafo criado!\n");

  while(op!=0) {
    printf("\n---MENU DE OPCOES---");
    printf("\n1) Adicionar arestas");
    printf("\n2) Realizar busca BFS");
    printf("\n0)Sair\nOpcao: ");
    scanf("%d", &op);
    switch(op) {
      case 1:
      {
        int i;
        int inicio, fim;
        printf("\nAdicionando [%d] arestas...\n", qtdV);
        for(i=0; i<qtdV; i++) {
          printf("Inicio [%d]: ", i+1);
          scanf("%d", &inicio);
          printf("Destino [%d]: ", i+1);
          scanf("%d", &fim);      
          addAresta(grafo, inicio, fim);     
          printf("Aresta (%d, %d) criada!\n", inicio, fim);
        }
      }break;
      case 2:
      {
        int vertice;
        printf("\nInsira o vertice a ser buscado: ");
        scanf("%d", &vertice);
        bfs(grafo, vertice);     
      }break;
      case 0: printf("\nSaindo do sistema..."); break;
      default: printf("\nAVISO: Opcao invalida!"); break;
    }
  }
  return 0;  
}