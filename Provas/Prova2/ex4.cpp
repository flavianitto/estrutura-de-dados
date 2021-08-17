#include<bits/stdc++.h>
using namespace std;

struct NO
{
    int index;
    NO *esq;
    NO *dir;
};
NO *raiz;

//Buscando elemento k na arvore
int busca(NO *folha, int k)
{
    if(folha==NULL)
    {
        return 0;
    }
    else if(k==folha->index)
    {
        return 1;
    }
    else if(k < folha->index)
    {
        return(busca(folha->esq, k));
    }
    else
    {
        return(busca(folha->dir, k));
    }
}