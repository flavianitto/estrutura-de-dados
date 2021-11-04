#include<bits/stdc++.h>
using namespace std;

struct LISTA
{
    int idade;
    int senha;
    LISTA *prox;
};

int main()
{
    LISTA *aux, *ant;
    LISTA *inicio=NULL;
    LISTA *fim=NULL;
    int op, idade, senha, atende;
    do
    {
        printf("\n\n---MENU DE OPCOES---");
        printf("\n1) Adicionar cliente");
        printf("\n2) Chamar cliente (remove da fila)");
        printf("\n3) Esvaziar fila");
        printf("\n4) Mostrar fila completa");
        printf("\n0) Sair do menu");
        printf("\nOpcao: ");
        cin >> op;
        switch(op)
        {
            case 1:
            {
                //adicionar cliente na fila
                LISTA *novo = new LISTA();
                printf("\n---Adicionando cliente---");
                printf("\n-Senha do cliente: ");
                cin >> senha;
                novo->senha = senha;
                printf("-Idade do cliente: ");
                cin >> idade;
                novo->idade = idade;
                if(inicio==NULL)
                {
                    inicio=novo;
                    fim=novo;
                    novo->prox=NULL;
                }
                else
                {
                    ant=NULL;
                    aux=inicio;
                    if(idade<60)
                    {
                        fim->prox=novo;
                        fim=novo;
                        novo->prox=NULL;
                    }
                    else
                    {
                        while(aux!=NULL && aux->idade>=60)
                        {
                            ant=aux;
                            aux=aux->prox;
                        }
                        if(ant==NULL)
                        {
                            novo->prox=inicio;
                            inicio=novo;
                        }
                        else if(ant==fim)
                        {
                            fim->prox=novo;
                            fim=novo;
                            novo->prox=NULL;
                        }
                        else
                        {
                            novo->prox=aux;
                            ant->prox=novo;
                        }
                    }
                }
            }break;

            case 2:
            {
                //chamar cliente para ser atendido
                if(inicio==NULL)
                {
                    printf("AVISO: Fila esta vazia!\n");
                }
                else
                {
                    int senhaAux = inicio->senha;
                    atende=inicio->idade;
                    aux=inicio;
                    inicio=inicio->prox;
                    delete(aux);
                    cout << "O cliente de senha [" << senhaAux << "] com " << atende << " anos foi atendido!\n";                    
                }
            }break;

            case 3:
            {
                //Esvaziando a fila
                aux=inicio;
                ant=NULL;
                while(aux!=NULL)
                {
                    ant=aux;
                    aux=aux->prox;
                    delete(ant);
                }
                inicio=NULL;
                fim=NULL;
            }break;

            case 4:
            {
                //Mostrar fila completa
                if(inicio==NULL)
                {
                    printf("AVISO: Fila esta vazia!\n");
                }
                else
                {
                    aux=inicio;
                    printf("\n---Mostrando fila---");
                    printf("\n\t-inicio-\n");
                    while(aux!=NULL)
                    {
                        cout << "Senha[" << aux->senha << "] com " << aux->idade << " anos\n";
                        aux=aux->prox;
                    }
                    printf("\t-fim-");
                }
            }break;

            default: printf("\nSaindo do sistema...\n");
        }
    }while(op != 0);
}