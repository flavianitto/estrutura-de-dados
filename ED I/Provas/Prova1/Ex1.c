/*
 Escreva um programa em C/C++ que insere 25 inteiros aleatórios de 1 a 10000 em ordem em uma lista encadeada. 
 O programa deve calcular a soma dos elementos, a média dos elementos, o maior e o menor elemento, e mostrar a lista construída.
 Se esses números inseridos forem pesquisados em uma lista simplesmente encadeada e em uma lista duplamente encadeada,
 o resultado será o mesmo? Justifique.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 25

void main(){

    struct lista{
        int numero;
        struct lista* prox;
    };

    struct lista *inicio = NULL;
    struct lista *final = NULL;
    struct lista *aux, *anterior;

    srand(time(0));

    int numero, i;

    for (i = 0; i < max; i++)
    {

        struct lista *novo = malloc(sizeof(struct lista));
        numero = ((rand() % 10000) + 1);
        novo->numero = numero;
        if (inicio == NULL){
            inicio = novo;
            final = novo;
            novo->prox = NULL;
        }
        else{
            anterior = NULL;
            aux = inicio; 

            while (aux != NULL && novo->numero > aux->numero)
            {
                anterior = aux;
                aux = aux->prox;
            }
            if (anterior == NULL)
            {
                novo->prox = inicio;
                inicio = novo;
            }
            else if(aux == NULL){
                final->prox = novo;
                final = novo;
                novo->prox = NULL;
            }
            else{
                anterior->prox = novo;
                novo->prox = aux;
            }
        }
    }
    
    int maior;
    int menor;
    double soma;
    aux = inicio;

    while (aux != NULL)
    {
        if (aux == inicio)
        {
            maior = aux->numero;
            menor = aux->numero;
        }
        else{
            if (aux->numero < menor)
            {
                menor = aux->numero;
            }
            if (aux->numero > maior)
            {
                maior = aux->numero;
            }
        }
        soma += aux->numero;
        printf("%d\n", aux->numero);
        aux = aux->prox;
    }
    double media = soma / max;
    putchar('\n');
    printf("soma = %.0lf\n", soma);
    printf("media = %.4lf\n", media);
    printf("maior = %d\n", maior);
    printf("menor = %d\n", menor);
}