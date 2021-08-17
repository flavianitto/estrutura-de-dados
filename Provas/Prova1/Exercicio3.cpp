#include <bits/stdc++.h>
using namespace std;

typedef struct Lista
{
    int num;
    LISTA *prox;
}LISTA;

//funcao recursiva
LISTA pesquisaNum(LISTA head, int N)
{
    LISTA *aux = head;

    if(aux->num == N)
    {
        return aux;
    }
    else if(aux->prox == NULL)
    {
        return NULL;
    }
    else
    {
        return pesquisaNum(aux->prox, N);
    }
}

