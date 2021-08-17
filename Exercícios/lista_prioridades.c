//lista de prioridades - heap maximo
#include<stdio.h>
#include<stdlib.h>

int Pai(int x)
{
  //divisao int ja é floor.
  return x/2;
}

void heap_fica(int vet[],int i,int qtd)
{
  int f_esq,f_dir,maior,aux;
  
  maior=i;
  //o nó tem filhos para esquerda e direita(se tem pra direita tem pra esquerda)
  if(2*i+1<=qtd)
  {
    f_esq=2*i;
    f_dir=2*i+1;
    
    if(vet[f_esq]>=vet[f_dir] && vet[f_esq]>vet[i])
      maior=2*i;
    
    else if(vet[f_dir]>vet[f_esq] && vet[f_dir]>vet[i])
      maior=2*1+1;
  }

  //o nó que está sendo analisado tem filho apenas para a esquerda
  else if(2*i<=qtd)
  {
    f_esq=2*i;
    if(vet[f_esq]>vet[i])
      maior=2*i;
  }

  //forma de realizar o aprofundamento na árvore.
  if(maior!=i)
  {
    //troca pra aprofundar na arvore
    aux=vet[i];
    vet[i]=vet[maior];
    vet[maior]=aux;
    
    heap_fica(vet,maior,qtd);
  }
  
}

void main()
{
  //declaração do vetor com a capacidade do heap
  int vet[11];
  int op,tam=0,ind,num;
  
  do
  {
    printf("\nMENU DE OPCOES - HEAP MAXIMO");
    printf("\n1 - Inserir elemento na lista de prioridades");
    printf("\n2 - Consultar o elemento de maior prioridade");
    printf("\n3 - Remover o elemento de maior prioridade");
    printf("\n4 - Consultar toda a lista");
    printf("\n5 - Sair");
    printf("\nDigite sua opcao: ");
    scanf("%d",&op);
    if(op<1 || op>5)
      printf("\nOpcao Invalida");
    else
    {
      switch(op)
      {
        case 1:
        {
          //verificação - se ainda existe espaço disponível no vetor.
          if(tam<10)
          {
            tam++;
            printf("Digite o numero: ");
            scanf("%d",&num);
            ind=tam;
            
            while(ind>1 && vet[Pai(ind)]<num)
            {
              vet[ind]=vet[Pai(ind)];
              ind = Pai(ind);
            }
            vet[ind]=num;
            printf("\nNumero inserido.");
          }
          else
            printf("\nLista de Prioridades cheia.");
          break;
        }
        //Consultar o elemento de maior prioridade.
        case 2:
        {
          if(tam==0)
            printf("\nLista vazia.");
          else
            printf("\nElemento de maior prioridade: %d",vet[1]);
          break;
        }
        //Remoção de elemento com maior prioridade.
        case 3:
        {
          if(tam==0)
            printf("Lista vazia.");
          else{
            int maior_prior=vet[1];
            vet[1]=vet[tam];
            tam--;
            
            heap_fica(vet,1,tam);
            printf("\nO elemento removido foi: %d",maior_prior);
          }
          break;
        }
        //consultar toda a lista
        case 4:
        {
          if(tam==0)
            printf("\nLista vazia.");
          else
          {
            int j;
            printf("\nA seguir, todos os elementos da lista de prioridades\n");
            for(j=1;j<=tam;j++)
            {
              printf("%d ",vet[j]);
            }
          }
          break;
        }
      }
    }
  }while(op!=5);
}
