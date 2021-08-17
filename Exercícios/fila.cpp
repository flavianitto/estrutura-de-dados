#include<bits/stdc++.h>
using namespace std;

struct FILA
{
    int num;
    FILA *prox;
};
int main()
{
    FILA *inicio = NULL;
    FILA *fim = NULL;
    FILA *aux;int op;
    do
    {
        cout<<"\n MENU DE OPÇÕES \n";
        cout<<"\n 1- Inserir na fila";
        cout<<"\n 2- Consultar toda a fila";
        cout<<"\n 3- Remover da fila";
        cout<<"\n 4- Esvaziar a fila";
        cout<<"\n 5- Sair";
        cout<<"\n Digite a sua opcao:";
        //cin é o equivalente ao scanf
        cin>>op;
        if(op< 1|| op>5)
            cout<<" Opcao invalida!\n";
        if(op == 1) //inserção
        {
            cout<<"Digite o número a ser inserido da fila:";
            FILA *novo = new FILA();
            cin>> novo -> num;
            novo -> prox = NULL;
            if(inicio == NULL ) //primeiro elemento
            {
                inicio = novo;
                fim = novo;
            }
            else// ja contém elemento
            {
                fim -> prox = novo;
                fim = novo;
            }
        }
        if(op == 2)// consultar a fila
        {
            if(inicio == NULL)
                cout<< "Fila Vazia\n";
            else
            {
                aux = inicio;
                while(aux != NULL)
                {
                    cout<< aux -> num;
                    aux = aux -> prox;
                }
            }
        }
        if (op == 3) //remover da fila
        {
            if(inicio == NULL)
                cout<<"Fila Vazia\n";
            else
            {
                aux = inicio;
                cout<<"Número "<< inicio -> num<<"Removido";
                inicio = inicio -> prox;
                delete(aux);
            }
        }
        if(op == 4)
        {
            if(inicio == NULL)
            cout<<"Fila vazia!";
            else
            {
                aux = inicio;
                while (aux != NULL)
                {
                inicio = inicio -> prox;
                delete(aux);
                aux = inicio;
                }
            }
        }
    }while(op != 5);
    return 0;
}