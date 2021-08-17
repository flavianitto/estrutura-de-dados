/*
Escreva um programa simples, em C/C++, de reserva de bilhetes de linha áerea. O programa exibe um menu com as seguintes opções: 
reserva de bilhete, cancelamento de bilhete, verificação se um bilhete está reservado para uma pessoa particular e exibição dos passageiros.
A informação é mantida alfabeticamente numa lista encadeada de nomes. Em uma versão mais simples do programa, assuma que os bilhetes 
estão reservados para somente um voo. Crie uma lista encadeada de voos com cada nó incluindo um ponteiro para uma lista ligada de passageiros.
*/
#include<stdio.h>
#include<stdlib.h>

struct Lista
{
    
};

int main()
{
    int op;

    //menu de opcoes
    while(op!=0)
    {
        printf("MENU DE OPCOES");
        printf("1) Reserva de bilhetes");
        printf("2) Cancelamento de bilhete");
        printf("3) Verificação do bilhete");
        printf("4) Exibicao dos passageiros");
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                //reserva o bilhete
            }break;

            case 2:
            {
                //cancela o bilhete
            }break;

            case 3:
            {
                //verifica se o bilhete esta reservado
            }break;

            case 4:
            {
                //exibe os passageiros
            }break;
        }
    }
}