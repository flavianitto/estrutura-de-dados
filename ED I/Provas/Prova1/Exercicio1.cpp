#include<bits/stdc++.h>
using namespace std;

typedef struct elem
{
    ELEM *prox;
    int numero;
}ELEM;


int main()
{
    int i, num, total=0;
    ELEM *head=NULL, *prox=NULL;
    ELEM *novo, *prev, *tail;
    srand(time(NULL));
    
    
    for(i=0; i<25; i++)
    {
        num = (rand()%10000)+1;
        novo = (ELEM*)malloc(sizeof(ELEM));

        novo->numero = num;
        novo->prox = NULL;
        if(head==NULL)
        {
            head = novo;
            tail = novo;
            novo->prox = NULL;
        }
        else
        {
            prev = NULL;
            prox = head;

            while(prox != NULL && novo->numero > prox->numero)
            {
                prev = prox;
                prox= prox->prox;
            }
            if(prev == NULL)
            {
                novo->prox = head;
                head = novo;
            }
            else if(prox == NULL)
            {
                tail->prox = novo;
                tail = novo;
                tail->prox = NULL;
            }
            else
            {
                prev->prox = novo;
                novo->prox = prox;
            }
        }
    }
    prox = head;

    while(prox!=NULL)
    {
        printf(" %d ", prox->numero);
        total=total+prox->numero;
        prox=prox->prox;
    }
    printf("\nSaida de dados: ");
    printf("\nMenor %d\n", head->numero);
    printf("\nMaior %d\n", tail->numero);
    printf("\nTotal %d\n", total);
    
    return 0;
}