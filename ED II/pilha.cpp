//Implemente uma pilha ilimitada (dinamica) como uma lista ligada
#include<bits/stdc++.h>
using namespace std;

struct pilha
{
    int num;
    struct pilha *prox;
};

int main()
{
    struct pilha *topo=NULL, *aux;
    int op=-1, i=0;
    do
    {
        cout << "\n\n---MENU DE OPCOES---\n";
        cout << "1) Inserir elemento na pilha\n";
        cout << "2) Remover elemento da pilha\n";
        cout << "3) Mostrar pilha\n";
        cout << "0) Sair\nOpcao: ";
        cin >> op;
        switch(op)
        {
            case 1:
            {   
                printf("\n---Inserindo novo elemento---\n");
                struct pilha *novo = new pilha();
                printf("-Digite o numero a ser inserido: ");
                cin >> novo->num;
                novo->prox=topo;
                topo=novo;
            }break;
            case 2:
            {
                printf("\n---Removendo topo da pilha---\n");
                if(topo==NULL)
                    cout << "\nAVISO: pilha vazia!\n";
                else
                {
                    aux = topo;
                    printf("Elemento [%d] foi removido!\n", topo->num);
                    topo=topo->prox;
                    delete(aux);
                }
            }break;
            case 3:
            {
                if(topo==NULL)
                    cout << "\nAVISO: pilha vazia!\n";
                else
                {
                    aux = topo;
                    printf("\n---Mostrando pilha---\n");
                    while(aux != NULL)
                    {
                        printf("[%d]\n", aux->num);
                        aux=aux->prox;
                    }
                }

            }break;
            case 0: cout << "\nSaindo do sistema...\n"; break;
            default: cout << "\nOpcao invalida!\n"; break;
        }
    } while(op!=0);
    
}