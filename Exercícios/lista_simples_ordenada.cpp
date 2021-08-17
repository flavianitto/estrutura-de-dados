#include<iostream>
#include<stdio.h>
#include<stdlib.h>
struct LISTA{
  int num;
  struct LISTA *prox;
};

int main(){
  struct LISTA *primeiro=NULL,*ultimo=NULL,*aux,*anterior;
  int op,numero,achou;
  do{
    std::cout<<"\nMENU DE OPÇÕES\n";
    std::cout<<"1- Inserir\n";
    std::cout<<"2- Consultar\n";
    std::cout<<"3- Remover\n";
    std::cout<<"4- Esvaziar\n";
    std::cout<<"5- Sair\n";
    std::cout<<"Digite a sua opcao: ";
    //cin é scanf
    std::cin>>op;
    if(op<1||op>5)
      std::cout<<"Opcao invalida.\n";
    else
      switch(op){
        case 1:{
          std::cout << "Digite o numero a ser inserido na lista:";
          struct LISTA *novo=new LISTA();
          std::cin >> novo->num;
          //verificando se lista esta vazia. Se estiver, elemento sera primeiro e ultimo.
          if(primeiro==NULL){
            primeiro=novo;
            ultimo=novo;
            novo->prox=NULL;
          }
          else{
            anterior=NULL;
            aux=primeiro;
            //aux será o elemento a frente de novo.
            //só vai entrar se for maior que primeiro.
            while(aux!=NULL && novo->num > aux->num){
              anterior=aux;
              aux=aux->prox;
            }
            //como não entrou é menor que primeiro, ent é o novo primeiro.
            if(anterior==NULL){
              novo->prox=primeiro;
              primeiro=novo;
            }
            //se entrou e o while chegou até o fim, ent é maior que o ultimo.
            //ent é o novo ultimo.
            else if(aux==NULL){
              ultimo->prox=novo;
              novo->prox=NULL;
              ultimo=novo;
            }
            else{
              novo->prox=anterior->prox;
              anterior->prox=novo;
            }
          }
          break;
        }
        case 2:{
          aux=primeiro;
          for(int i=0;aux!=NULL;i++){
            printf("%d: %d\n",i,aux->num);
            aux=aux->prox;
          }
          break;
        }
        case 3:{
          if(primeiro!=NULL){
            std::cout << "Digite o numero a ser removido: ";
            std::cin >> numero;
            if(primeiro->num==numero && ultimo->num==numero){
              delete(primeiro);
              primeiro=NULL;
              ultimo=NULL;
              std::cout << "Numero removido, lista vazia." << '\n';
            }
            else if(primeiro->num==numero){
              aux=primeiro->prox;
              delete(primeiro);
              primeiro=aux;
              std::cout << "Numero removido." << '\n';
            }
            else if(ultimo->num==numero){
              aux=primeiro;
              while(aux!=ultimo){
                anterior=aux;
                aux=aux->prox;
              }
              delete(ultimo);
              ultimo=anterior;
              anterior->prox=NULL;
              std::cout << "Numero removido." << '\n';
            }
            else{
              achou=0;
              aux=primeiro;
              while(aux!=ultimo){
                anterior=aux;
                aux=aux->prox;
                if(aux->num==numero){
                  achou=1;
                  break;
                }
              }
              if(achou){
                anterior->prox=aux->prox;
                delete(aux);
                std::cout << "Numero removido." << '\n';
              }
              else
                std::cout << "Numero não encontrado." << '\n';
            }
          }
          break;
        }
        case 4:{
          if(primeiro!=NULL){
            aux=primeiro->prox;
            anterior=primeiro;
            while(aux!=NULL){
              std::cout << anterior->num << " removido\n";
              delete(anterior);
              anterior=aux;
              aux=aux->prox;
            }
            std::cout << ultimo->num << " removido\n";
            delete(ultimo);
            primeiro=NULL;
            ultimo=NULL;
          }
        }
      }
  }while(op!=5);
  return 0;
}