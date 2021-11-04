#include<bits/stdc++.h>
using namespace std;

typedef struct professor
{
    char nome[51];
    int qtdDisciplinas; //maximo 5
}Professor;

typedef struct disciplina
{
    int indice;
    char codigo[11];
    char nome[51];
    int ano; //2013 a 2030
    int semestre; //1 ou 2
    int qtdAlunos; //maximo 50
    int qtdProvas; //maximo 4
    int qtdTrabalhos; //maximo 10
    int cargaHP; //default: 60h
    int cargaHR; 
    double notaMin; //default: 5 (entre 0 e 10)
    double percentualMin; //default: 70 (entre 0 e 100)
    //o percentual e calculado com base na carga horaria prevista e nao na realizada

    //ProvaTrab provaTrab[14]; //4 primeiras para provas, 10 ultimas para trabalhos
    //Aluno alunos[50];
    //Aula aulas;
}Disciplina;
Disciplina disciplina[5];

int main()
{
    //int i=0;
    FILE *arquivo, *editado;
    Professor novo, antigo;
    char line[100];
    //Disciplina disciplina[5];
    //tem que salvar os dados do professor em algum arquivo - senao nao salva as alteracoes
    //duas primeiras linhas do arquivo disciplinas.txt sao os dados do professor
    if((arquivo=fopen("disciplinas.txt", "r+"))==NULL)
    {
        printf("\nAVISO: Arquivo nao pode ser aberto!");
    }
    else
    {
        //recebe os dados novos
        printf("\n-Editando dados do professor-");
        printf("\n-Novo nome: ");
        scanf(" %[^\n]s", novo.nome);
        fflush(stdin);
        printf("-Nova quantidade de disciplinas: ");
        scanf("%d", &novo.qtdDisciplinas);
        fflush(stdin);

        //copiar os dados para uma estrutura disciplinailiar
        arquivo=fopen("disciplinas.txt", "r");

        fscanf(arquivo, " %[^\n]s", line);
        fflush(stdin);
        strcpy(antigo.nome,strtok(line,";"));
        antigo.qtdDisciplinas=atoi(strtok(line,";"));
        disciplina[0].indice=atoi(strtok(line,";"));
        disciplina[0].codigo=atoi(strtok(line,";"));
        strcpy(disciplina[0].nome,strtok(line,";"));
        disciplina[0].ano=atoi(strtok(line,";"));
        disciplina[0].semestre=atoi(strtok(line,";"));
        disciplina[0].qtdAlunos=atoi(strtok(line,";"));  
        disciplina[0].qtdProvas=atoi(strtok(line,";"));
        disciplina[0].qtdTrabalhos=atoi(strtok(line,";"));
        disciplina[0].cargaHP=atoi(strtok(line,";"));
        disciplina[0].cargaHR=atoi(strtok(line,";"));
        disciplina[0].notaMin=atol(strtok(line,";"));
        disciplina[0].percentualMin=atol(strtok(line,";"));
        fclose(arquivo);

        int tam=i;
        if((editado=fopen("disciplinas.txt", "w"))==NULL)
        {
            printf("\nERRO");
        }
        else
        {
            fprintf(editado, "%s", novo.nome);
            fprintf(editado, ";%d", novo.qtdDisciplinas);
            int j=0;
            while(j<tam)
            {
                fprintf(editado, ";%d", disciplina[j].indice);
                fprintf(editado, ";%s", disciplina[j].codigo);
                fprintf(editado, ";%s", disciplina[j].nome);
                fprintf(editado, ";%d", disciplina[j].ano);
                fprintf(editado, ";%d", disciplina[j].semestre);
                fprintf(editado, ";%d", disciplina[j].qtdAlunos);
                fprintf(editado, ";%d", disciplina[j].qtdProvas);
                fprintf(editado, ";%d", disciplina[j].qtdTrabalhos);
                fprintf(editado, ";%d", disciplina[j].cargaHP);
                fprintf(editado, ";%d", disciplina[j].cargaHR);
                fprintf(editado, ";%.2lf", disciplina[j].notaMin);
                fprintf(editado, ";%.2lf", disciplina[j].percentualMin);
                j++;
            }
            fclose(editado);
        }
    }
}

/*
geraldo
3
1
123
2021
2
45
2
5
60
20
5
70
2
321
2021
2
45
2
5
60
20
5
70
*/
