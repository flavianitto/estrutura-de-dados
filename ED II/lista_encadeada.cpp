/*
Faca a implementacao da busca e da remoção do ultimo no de uma lista 
encadeada com cinco posicoes
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    int num;
    struct node *prox;
};

int main() {
    struct node *inicio=NULL, *ultimo=NULL, *aux, *prev; //lista com 5 elementos
    int op=-1, i=0;
    do
    {
        cout << "\n\n---MENU DE OPCOES---\n";   
        cout << "1) Preencher lista\n";
        cout << "2) Buscar ultimo elemento\n";
        cout << "3) Remover ultimo elemento\n";
        cout << "0) Sair\n";
        cout << "Opcao: "; 
        cin >> op;
        switch(op)
        {
            case 1: 
            {
                printf("\n---Preenchendo a lista---\n");
                for(i=0; i<5; i++)
                {                    
                    printf("-Digite um numero para a posicao [%d] da lista: ", i);
                    struct node *novo = new node();        
                    cin >> novo->num;

                    if(inicio==NULL) { //se a lista esta vazia
                        inicio=novo;
                        ultimo=novo;
                        novo->prox=NULL;
                    }
                    else { //se a lista nao esta vazia         
                        ultimo->prox=novo;
                        novo->prox=NULL;
                        ultimo=novo;
                    }
                }
                printf("\nLista preenchida!\n");

                //mostrando lista
                printf("\nMostrando a lista:\n");
                aux=inicio;
                for(i=0; aux!=NULL; i++) {
                    printf("[%d]: %d\n", i, aux->num);
                    aux=aux->prox;
                }                
            }break;

            case 2:
            {
                if(ultimo!=NULL)
                    printf("Ultimo: %d\n", ultimo->num);
                else
                    printf("Lista vazia!\n");
            }break;            
            case 3:
            {
                if(inicio!=NULL || ultimo!=NULL) {
                    printf("Removendo numero [%d]...\n", ultimo->num);      
                    aux=inicio;
                    while(aux!=ultimo) {
                        prev=aux;
                        aux=aux->prox;
                    }
                    delete(ultimo);                        
                    ultimo=prev;
                    prev->prox=NULL;
                    cout << "Numero removido\n";                               
                }      
                else {
                    printf("Lista vazia!\n");
                }                          
            }break;
            case 0: cout << "Saindo do sistema...\n"; break;
            default: cout << "Opcao invalida!\n"; break;
        }
    }while(op!=0); 
}