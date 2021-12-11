#include<stdio.h>
#include<stdlib.h>

struct No {
  int v;
  struct No* prox;
};
struct Grafo {
  int numV;
  int* visitados;
  struct No** listaAdj;
};

//criando novo no
struct No* criaNo(int vertices) {
  struct No* novo = malloc(sizeof(struct No));
  novo->v = vertices;
  novo->prox = NULL;
  return novo;
}

//criando grafo
struct Grafo *criaGrafo(int vertices) {
  struct Grafo* novo = malloc(sizeof(struct Grafo));
  novo->numV = vertices;
  novo->listaAdj = malloc(vertices*sizeof(struct No*));
  novo->visitados = malloc(vertices*sizeof(int));
  
  //preenchendo os vetores
  int i;
  for(i=0; i<vertices; i++) {
    novo->listaAdj[i] = NULL;
    novo->visitados[i] = 0;
  }
  return novo;
}

//criando aresta
void criaAresta(struct Grafo* grafo, int inicio, int fim) {
  //adiciona do inicio para o fim
  struct No* novo = criaNo(fim);
  novo->prox = grafo->listaAdj[inicio];
  grafo->listaAdj[inicio] = novo;

  //adiciona do fim para o inicio
  novo = criaNo(inicio);
  novo->prox = grafo->listaAdj[fim];
  grafo->listaAdj[fim] = novo;
}

//imprimindo grafo
void imprime(struct Grafo* grafo) {
  int i;
  for(i=0; i<grafo->numV; i++) {
    struct No* aux = grafo->listaAdj[i];
    printf("\nLista de Adjacencia do vertice [%d]:\n", i);
    while(aux) {
      printf("[%d] => ", aux->v);
      aux = aux->prox;
    }
    printf("\n");
  }
}

//busca dfs
void dfs(struct Grafo* grafo, int v) {
  struct No* lista = grafo->listaAdj[v];
  struct No* aux = lista;
  grafo->visitados[v] = 1;
  printf("[%d] visitado.\n", v);
  while(aux != NULL) {
    int conectado = aux->v;
    if(grafo->visitados[conectado]==0) {
      dfs(grafo, conectado);
    }
    aux = aux->prox;
  }
}

int main() {
  int qtdV, op=-1;
  printf("\nInsira a quantidade de vertices do grafo: ");
  scanf("%d", &qtdV);
  struct Grafo* grafo = criaGrafo(qtdV);
  printf("Grafo criado!\n");

  while(op!=0) {
    printf("\n---MENU DE OPCOES---");
    printf("\n1) Adicionar arestas");
    printf("\n2) Realizar busca DFS");
    printf("\n3) Imprimir grafo\n0)Sair\nOpcao: ");
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
          criaAresta(grafo, inicio, fim);     
          printf("Aresta (%d, %d) criada!\n", inicio, fim);
          //imprime(grafo);
        }
      }break;
      case 2:
      {
        int vertice;
        printf("\nInsira o vertice a ser buscado: ");
        scanf("%d", &vertice);
        dfs(grafo, vertice);     
        imprime(grafo);
      }break;
      case 3: imprime(grafo); break;
      case 0: printf("\nSaindo do sistema..."); break;
      default: printf("\nAVISO: Opcao invalida!"); break;
    }
  }
  return 0;
}