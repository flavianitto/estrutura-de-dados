#include<bits/stdc++.h>
using namespace std;

#define L 12
#define C 4

void converteMes(int mes);

int main()
{
    float matriz[L][C], vendas=0;
    float totAno=0;
    int i, j, op=-1;
    int sem, mes;

    //entrada de dados
    for(i=1; i<=L; i++)
    {
        for(j=1; j<=C; j++)
        {
            printf("Digite o valor de vendas da semana %d do mes de ", i);
            converteMes(i);
            cin >> vendas;
            matriz[i][j] = vendas;
            totAno += vendas;
            vendas=0;
        }
    }

    //Menu de opcoes
    while(op!=0)
    {
        printf("\nMENU DE OPCOES");
        printf("\n1) Mostra total vendido em cada mes do ano");
        printf("\n2) Mostra o total vendido em cada semana durante o ano");
        printf("\n3) Mostra o total vendido no ano");
        printf("\n0) Sair do sistema");
        printf("\nOpcao: ");
        cin >> op;        
        switch(op)
        {
            case 1:
            {
                float totMes=0;
                printf("\nDigite o numero do mes para consultar o total de vendas (de 1 ate 12): ");
                cin >> mes;
                for(i=1; i<=L; i++)
                {
                    if(i==mes)
                    {
                        converteMes(mes);
                        for(j=1; j<=C; j++)
                        {
                            totMes = totMes + matriz[i][j];
                        }
                    }
                }    
                printf("%.2f\n", totMes);
            }break;

            case 2:
            {
                printf("\nDigite o numero da semana para consultar o total de vendas: ");
                cin >> sem;
                for(i=1; i<=L; i++)
                {
                    printf("Total de vendas da semana %d do mes de ", sem);
                    converteMes(i);
                    printf("%.2f \n", matriz[i][sem]);
                }                
            }break;

            case 3:
            {
                printf("Total de vendas do ano: %.2f\n", totAno);
            }break;

            case 0: printf("Saindo do sistema..."); break;
            default: printf("Opcao invalida!!!"); break;
        }
    }
}

void converteMes(int mes)
{
    switch(mes)
    {
        case 1: cout << "Janeiro: "; break;
        case 2: cout << "Fevereiro: "; break;
        case 3: cout << "Marco: "; break;
        case 4: cout << "Abril: "; break;
        case 5: cout << "Maio: "; break;
        case 6: cout << "Junho: "; break;
        case 7: cout << "Julho: "; break;
        case 8: cout << "Agosto: "; break;
        case 9: cout << "Setembro: "; break;
        case 10: cout << "Outubro: "; break;
        case 11: cout << "Novembro: "; break;
        case 12: cout << "Dezembro: "; break;
        default: cout << "Mes invalido"; break;
    }
}

/*
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
1
2
3
4
*/
