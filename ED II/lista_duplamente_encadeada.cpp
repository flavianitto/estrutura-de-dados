/*
Faca a implementacao da busca e da remocao do primeiro no de
uma lista duplamente encadeada com cinco posicoes
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    int num;
    struct node *prox;
    struct node *prev;
};

int main() 
{
    struct node *inicio=NULL, *ultimo=NULL, *aux;
    int op=-1, i=0;
    do 
    {
        cout << "\n\n---MENU DE OPCOES---\n";   
        cout << "1) Preencher lista\n";
        cout << "2) Buscar primeiro elemento\n";
        cout << "3) Remover primeiro elemento\n";
        cout << "0) Sair\n";
        cout << "Opcao: "; 
        cin >> op;
        switch(op)
        {
            case 1:
            {
                printf("\n---Preenchendo a lista---\n");
                for(i=0; i<5; i++) {
                    struct node *novo = new node();
                    printf("-Digite um numero para a posicao [%d] da lista: ", i);
                    cin >> novo->num;
                    if(inicio==NULL) {
                        inicio=novo;
                        ultimo=novo;
                        novo->prox=NULL; //lista nao e circular
                        novo->prev=NULL;
                    }
                    else {
                        ultimo->prox=novo;
                        novo->prev=ultimo;
                        ultimo=novo;
                        ultimo->prox=NULL;                        
                    }
                }
                //mostrando a lista
                printf("\n---Mostrando a lista---\n");
                printf("\n-Usando o ponteiro prox:\n");
                aux=inicio;
                for(i=0; aux!=NULL; i++) {
                    printf("[%d]: %d\n", i, aux->num);
                    aux=aux->prox;
                }
                printf("\n-Usando o ponteiro prev:\n");
                aux=ultimo;
                for(i=5; aux!=NULL; i--) {
                    printf("[%d]: %d\n", i, aux->num);
                    aux=aux->prev;
                }                
            }break;
            case 2:
            {
                printf("\n---Buscando primeiro elemento---\n");
                if(inicio!=NULL && ultimo!=NULL) {
                    printf("-Primeiro elemento (prox): %d\n", inicio->num);
                    printf("-Primeiro elemento (prev): %d\n", ultimo->num);
                }
                else {
                    cout << "\nLista vazia!\n";
                }
            }break;
            case 3:
            {
                int op3=-1;
                while(op3!=0) 
                {
                    printf("\n---Removendo primeiro elemento---\n");
                    printf("\n1) Remover primeiro elemento usando o prox");
                    printf("\n2) Remover primeiro elemento usando o prev\nOpcao: ");
                    cin >> op3;
                    switch(op3)
                    {
                        case 1:
                        {
                            aux=inicio;
                            inicio=aux->prox;
                            inicio->prev=NULL;
                            ultimo->prox=NULL;
                            delete(aux);
                            aux=inicio;
                            printf("\nNumero removido!\n");
                            
                            printf("\n---Mostrando a lista---\n");
                            aux=inicio;
                            for(i=0; aux!=NULL; i++) {
                                printf("[%d]: %d\n", i, aux->num);
                                aux=aux->prox;
                            }                        
                        }break;
                        case 2:
                        {
                            aux=ultimo;
                            ultimo=ultimo->prev;
                            ultimo->prox=NULL;
                            delete(aux);
                            aux=NULL;
                            printf("\nNumero removido!\n");

                            printf("\n---Mostrando a lista---\n");
                            aux=ultimo;
                            for(i=5; aux!=NULL; i--) {
                                printf("[%d]: %d\n", i, aux->num);
                                aux=aux->prev;
                            }                               
                        }break;
                        default: cout << "\nOpcao invalida!\n"; break;
                    }
                }
            }break;
            case 0: cout << "\nSaindo do sistema...\n"; break;
            default: cout << "\nOpcao invalida!\n"; break;
        }
    }while(op!=0);
}
