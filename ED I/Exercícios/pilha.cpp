#include<iostream>
using namespace std;
struct PILHA
{
    int num;
    PILHA *prox;
};

int main()
{
    PILHA *topo = NULL;
    PILHA *aux ;
    int op;
    do
    {
        cout<<"\n MENU DE OPÇÕES \n";
        cout<<"\n 1- Inserir na pilha";
        cout<<"\n 2- Consultar toda a pilha";
        cout<<"\n 3- Remover da pilha";
        cout<<"\n 4- Esvaziar";
        cout<<"\n 5- Sair";
        cout<<"\n Digite a sua opcao:";
        //cin é o equivalente ao scanf
        cin>>op;
        if(op< 1|| op>5)
            cout<<" Opcao invalida!\n";
        if(op ==1) //insercao na pilha
        {
            cout<<"Digite o número a ser inserido\n";
            PILHA *novo = new PILHA();
            cin>> novo -> num;novo -> prox = topo;
            topo = novo;
        }
        if(op == 2) //Consultar a pilha
        {
            if( topo == NULL)
                cout<<"Pilha Vazia!";
            else
            {
                aux = topo;
                while (aux != NULL)
                {
                cout<< aux->num<<" \n";
                aux = aux ->prox;
                }
            }
        }
        if(op == 3)//Remoção na pilha
        {
            if(topo == NULL)
                cout<<"Pilha Vazia";
            else
            {
                aux = topo;
                cout<<"Numero" << topo -> num << "removido\n";
                topo = topo -> prox;
                delete(aux);
            }
        }
        if(op == 4) //esvaziar a pilha
        {
            if(topo == NULL)
                cout<<" Pilha Vazia";
            else
            {
                aux = topo;
                while(aux != NULL)
                {
                topo = topo -> prox;
                delete(aux);
                aux = topo;
                }
            cout<<"Pilha esvaziada\n";
            }
        }
    }while(op != 5);
    return 0;
}