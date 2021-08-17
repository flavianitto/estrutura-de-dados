#include<bits/stdc++.h>
using namespace std;

void main()
{
    struct LISTA //estrutura do nó da lista
    {
    int num;
    LISTA *prox;
    LISTA *ant;
    };
    LISTA *inicio = NULL;
    LISTA *fim = NULL;
    LISTA *aux;
    int op, numero, achou;
    do
    {
        cout<<"\n MENU DE OPÇÕES \n";
        cout<<"\n 1- Inserir no início da lista";
        cout<<"\n 2- Inserir no fim da lista";
        cout<<"\n 3- Consultar a lista do início ao fim";
        cout<<"\n 4- Consultar a lista do fim ao início";
        cout<<"\n 5- Remover da lista";
        cout<<"\n 6- Esvaziar a lista";
        cout<<"\n 7- Sair";
        cout<<"\n Digite a sua opção:";
        cin>>op;
        if(op < 1 || op > 7)
            cout<<"Opção inválida!\n";
        if(op == 1) //inserção no início da lista
        {
            cout<<"\nDigite o número a ser inserido:";
            LISTA *novo = new LISTA();
            cin>> novo -> num;
            if(inicio == NULL) // lista vazia
            {
                inicio = novo;
                fim = novo;
                novo -> prox = inicio;
                novo -> ant = inicio;
            }
            else // a lista contém elementos
            {
                novo -> prox = inicio;
                inicio -> ant = novo;
                novo -> ant = fim;
                fim -> prox = novo;
                inicio = novo;
            }// fim else
        }// fim if op==1

        if(op == 2) // inserção no final da lista
        {
            cout<<"\n Digite o número a ser inserido:";
            LISTA *novo = new LISTA();
            cin>> novo -> num;
            if(inicio == NULL) // lista vazia
            {
                inicio = novo;
                fim = novo;
                novo -> prox = inicio;
                novo -> ant = inicio;
            }// fim do if
            else // a lista contém elementos
            {
                fim -> prox = novo;
                novo -> ant = fim;
                fim = novo;
                fim -> prox = inicio;
                inicio -> ant = fim;
            }// fim do else
        }// fim if op==2

        if(op == 3) //consultar a lista do início ao fim
        {
            if(inicio == NULL) //lista vazia
            cout<<"Lista Vazia \n";
            else //lista mostrada do início ao fim
            {
                aux = inicio;
                do
                {
                    cout<<aux -> num<<" ";
                    aux = aux -> prox;
                }while(aux != inicio);
            }// fim else
        }//fim if op==3

        if(op == 4) //Consultar a lista do fim ao início
        {
            if(inicio == NULL) //lista vazia
            cout<<"Lista Vazia \n";
            else //lista mostrada do fim ao início
            {
                aux = fim;
                do
                {
                    cout<< aux -> num << " ";
                    aux = aux -> ant;
                }while(aux != fim);
            }// fim else
        }// fim if op==4

        if(op == 5) //remoção na lista
        {
            if(inicio == NULL) //lista vazia
            cout<<"Lista Vazia \n";
            else // lista contém elementos
            {
                cout<<"Digite o elemento a ser removido:";
                cin>>numero;
                aux = inicio;
                achou = 0;
                int quantidade = 0;
                do //descobrindo a quantidade de elementos na lista
                {
                    quantidade++;
                    aux = aux -> prox;
                }while(aux != inicio); //fim do do/while
                int elemento = 1;
                do
                {
                    // se a lista possui apenas um elemento
                    if(inicio == fim && inicio -> num == numero)
                    {
                        inicio = NULL;
                        delete(inicio);
                        achou++;
                    }//fim if
                    else // lista contém mais de um elemento
                    {
                        if(aux -> num == numero)
                        {
                            achou++;
                            if(aux == inicio) //primeiro elemento
                            {
                                inicio = aux -> prox;
                                inicio -> ant = fim;
                                fim -> prox = inicio;
                                delete (aux);
                                aux = inicio;
                            }// fim if
                            else if(aux == fim) // ultimo elemento
                            {
                                fim = fim -> ant;
                                fim -> prox = inicio;
                                inicio -> ant = fim;
                                delete(aux);
                                aux = NULL;
                            }// fim else/if
                            else //esta no meio da lista
                            {
                                aux->ant->prox = aux->prox;
                                aux -> prox -> ant = aux-> ant;
                                LISTA *aux2;
                                aux2 = aux;
                                aux = aux -> prox;
                                delete(aux2);
                            }// fim else
                        }// fim if
                        else // não encontrou o elemento
                        {
                            aux = aux -> prox;
                        }
                    }//fim elseelemento ++;
                }while(elemento <= quantidade);
            }// fim else
        }// fim if op==5

        if(op ==6) //esvaziamento da lista
        {
            if (inicio == NULL) //lista não contem elementos
            {
                cout<<"Lista Vazia!";
            }
            else //lista contém elementos
            {
                aux = inicio;
                do
                {
                    inicio = inicio -> prox;
                    delete (aux);
                    aux = inicio;
                }while(aux!= fim);
                delete(fim);
                inicio = NULL;
            }// fim do else
        }//fim if op==6
    } while(op != 7 ); //fim do do/while
}// fim do main()