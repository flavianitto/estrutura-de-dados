/* Escreva um programa simples, em C/C++, de reserva de bilhetes de linha áerea. O programa exibe um menu com as seguintes opções: 
reserva de bilhete, cancelamento de bilhete, verificação se um bilhete está reservado para uma pessoa particular e exibição dos passageiros.
A informação é mantida alfabeticamente numa VOO encadeada de nomes. Em uma versão mais simples do programa, assuma que os bilhetes 
estão reservados para somente um voo. Crie uma VOO encadeada de voos com cada nó incluindo um ponteiro para uma VOO ligada de passageiros. */

#include<bits/stdc++.h>
using namespace std;

struct VOO
{
    char nome[30];
    struct VOO *prox;
};

int main()
{
    struct VOO *head=NULL;
    struct VOO *tail=NULL;
    struct VOO *aux, *prev;
    char excluir[30], consultar[30];
    int op, i;
    bool find;

    //menu de opcoes
    while(op!=0)
    {
        printf("\nMENU DE OPCOES");
        printf("\n1) Reserva de bilhetes");
        printf("\n2) Cancelamento de bilhete");
        printf("\n3) Verificacao do bilhete");
        printf("\n4) Exibicao dos passageiros");
        printf("\n0) Sair do sistema");
        printf("\nOpcao: ");
        cin >> op;
        switch(op)
        {
            case 1:
            {
                //reserva o bilhete
                printf("Digite o nome do passageiro que reservou o bilhete: ");
                struct VOO *novo = new VOO();
                cin >> novo->nome;
                if(head==NULL)
                {
                    head=novo;
                    tail=novo;
                    novo->prox=NULL;
                }
                else
                {
                    prev=NULL;
                    aux=head;
                    //verificando se é maior que o primeiro nome
                    while(aux!=NULL && novo->nome > aux->nome)
                    {
                        prev=aux;
                        aux=aux->prox;
                    }
                    //novo primeiro
                    if(prev==NULL)
                    {
                        novo->prox=head;
                        head=novo;
                    }
                    //novo ultimo
                    else if(aux==NULL)
                    {
                        tail->prox=novo;
                        novo->prox=NULL;
                        tail=novo;
                    }
                    else
                    {
                        novo->prox=prev->prox;
                        prev->prox=novo;
                    }
                }
            }break;

            case 2:
            {
                //cancela o bilhete
                //verifica se a lista nao esta vazia
                if(head!=NULL)
                {
                    printf("Digite o nome do passageiro a cancelar o bilhete: ");
                    cin >> excluir;
                    if(!strcmp(head->nome,excluir) && !strcmp(tail->nome,excluir))
                    {
                        delete(head);
                        head=NULL;
                        tail=NULL;
                        printf("Bilhete cancelado, lista de passageiros esta vazia\n");
                    }
                    else if(!strcmp(head->nome,excluir))
                    {
                        aux=head->prox;
                        delete(head);
                        head=aux;
                        printf("Bilhete cancelado\n");
                    }
                    else if(!strcmp(tail->nome,excluir))
                    {
                        aux=head;
                        while(aux != tail)
                        {
                            prev=aux;
                            aux=aux->prox;
                        }
                        delete(tail);
                        tail=prev;
                        prev->prox=NULL;
                        printf("Bilhete cancelado\n");    
                    }
                    else
                    {
                        find=false;
                        aux=head;
                        while(aux != tail)
                        {
                            prev=aux;
                            aux=aux->prox;
                            if(!strcmp(aux->nome,excluir))
                            {
                                find=true;
                                break;
                            }
                        }
                        if(find)
                        {
                            prev->prox=aux->prox;
                            delete(aux);
                            printf("Bilhete cancelado\n");
                        }
                        else
                        {
                            printf("Bilhete nao encontrado no sistema\n");
                        }
                    }
                }
                else
                {
                    printf("Lista esta vazia!!!\n");
                }
            }break;

            case 3:
            {
                //verifica se o bilhete esta reservado
                if(head!=NULL)
                {
                    printf("Digite o nome do passageiro a ser consultado: ");
                    cin >> consultar;
                    aux=head;

                    while(aux != NULL)
                    {
                        if(!strcmp(aux->nome, consultar))
                        {
                            printf("Bilhete reservado para o passageiro %s\n", aux->nome);
                            //aux=aux->prox;
                            break;
                        }
                        else
                        {
                            aux=aux->prox;
                            //break;
                        }
                    }
                    if(aux==NULL)
                    {
                        printf("Bilhete nao esta reservado ainda\n");
                        aux==NULL;
                        break;
                    }
                }
                else
                {
                    printf("Lista esta vazia!!!\n");
                }
            }break;

            case 4:
            {
                //exibe os passageiros
                aux=head;
                for(i=0; aux!=NULL; i++)
                {
                    printf("Passageiro[%d]: %s\n", i+1, aux->nome);
                    aux=aux->prox;
                }
            }break;

            case 0: printf("Saindo do sistema..."); break;
            default: printf("Opcao invalida!!!\n"); break;
        }
    }
    return 0;
}