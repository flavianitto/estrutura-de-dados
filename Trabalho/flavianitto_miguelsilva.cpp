#include<bits/stdc++.h>
using namespace std;

typedef struct data
{
    int dia;
    int mes;
    int ano;
    int invertida;
    char formatada[11];
    int semestre;
}Data;

typedef struct professor
{
    char nome[51];
    int qtdDisciplinas; //maximo 5
}Professor;
Professor professor;

typedef struct provaTrab
{
    char nome[51];
    char tipo; //P(prova), T(trabalho) ou E(exame)//aqui ÃƒÂ© um campo sÃƒÂ³, nÃƒÂ£o os 3
    Data data; //maior ou igual ao inicio do ano/semestre
    double peso; //entre 0 e 100
}ProvaTrab;

typedef struct aula
{
    int numOrdem; //comeÃƒÂ§a a partir do 1
    Data data; //maior ou igual ao inicio do ano/semestre
    double qtdHoras; //default: 2h
    char conteudo[256]; 
}Aula;

typedef struct aluno
{
    int numero; //entre 1 e 50
    char nome[51]; 
    double *notas; //fazer malloc com o numero de avaliacoes - entre 0 e 10
    double notaExame; //entre 0 e 10 - nao obrigatoria
    //char presenca[2]; //P(presenca) ou F(falta)
    int P=0; //ir somando
    int F=0; 
    bool situacao;
    double media;
}Aluno;

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

    ProvaTrab provaTrab[14]; //4 primeiras para provas, 10 ultimas para trabalhos
    Aluno alunos[50];
    Aula *aulas;
}Disciplina;
Disciplina disciplina[5];

/*
typedef struct lista
{
    Disciplina listaD[5];
    Aluno listaA;
    LISTA *prox;
}LISTA;
*/

void data_str(int coddisc,int i ,char *diamesano) //funÃƒÂ§ÃƒÂ£o para o tratamento da data
{
    char ano[5], mes[3], dia[3];
    char data_strcerta[9], data_strnormal[11];
    int aux;

    strcpy(disciplina[coddisc].provaTrab[i].data.formatada,diamesano);
    strcpy(data_strnormal, strtok(diamesano, "/")); //aqui ele recebe o dia , e atravÃƒÂ©s do comando strtok ele le atÃƒÂ© o /
    strcpy(dia, data_strnormal);
    disciplina[coddisc].provaTrab[i].data.dia = atoi(dia); //aqui transforma o dia em inteiro

    strcpy(data_strnormal, strtok(NULL, "/")); //como explicado acima mas com o mes
    strcpy(mes, data_strnormal);
    disciplina[coddisc].provaTrab[i].data.mes = atoi(mes);

    strcpy(data_strnormal, strtok(NULL, "/")); //como explicado acima mas com o ano
    strcpy(ano, data_strnormal);
    disciplina[coddisc].provaTrab[i].data.ano = atoi(ano);

    strcpy(data_strcerta, ano); //concatenaÃƒÂ§ÃƒÂ£o da string de data para a ordenaÃƒÂ§ÃƒÂ£o
    strcat(data_strcerta, mes);
    strcat(data_strcerta, dia);

    disciplina[coddisc].provaTrab[i].data.invertida = atol(data_strcerta); //transformaÃƒÂ§ÃƒÂ£o dessa string para inteiro
    if(disciplina[coddisc].provaTrab[i].data.mes<=6 && disciplina[coddisc].provaTrab[i].data.mes>0)
    {
        disciplina[coddisc].provaTrab[i].data.semestre=1;
    }
    else if(disciplina[coddisc].provaTrab[i].data.mes>0)
    {
        disciplina[coddisc].provaTrab[i].data.semestre=2;
    }
    
    //return disciplina[coddisc].provaTrab[i].data.invertida;
}
void data_stra(int coddisc,char *diamesano) //funÃƒÂ§ÃƒÂ£o para o tratamento da data
{
    char ano[5], mes[3], dia[3];
    char data_strcerta[9], data_strnormal[11];
    int aux;

    strcpy(disciplina[coddisc].aulas->data.formatada,diamesano);
    strcpy(data_strnormal, strtok(diamesano, "/")); //aqui ele recebe o dia , e atravÃƒÂ©s do comando strtok ele le atÃƒÂ© o /
    strcpy(dia, data_strnormal);
    disciplina[coddisc].aulas->data.dia = atoi(dia); //aqui transforma o dia em inteiro

    strcpy(data_strnormal, strtok(NULL, "/")); //como explicado acima mas com o mes
    strcpy(mes, data_strnormal);
    disciplina[coddisc].aulas->data.mes = atoi(mes);

    strcpy(data_strnormal, strtok(NULL, "/")); //como explicado acima mas com o ano
    strcpy(ano, data_strnormal);
   disciplina[coddisc].aulas->data.ano = atoi(ano);

    strcpy(data_strcerta, ano); //concatenaÃƒÂ§ÃƒÂ£o da string de data para a ordenaÃƒÂ§ÃƒÂ£o
    strcat(data_strcerta, mes);
    strcat(data_strcerta, dia);

    disciplina[coddisc].aulas->data.invertida = atol(data_strcerta); //transformaÃƒÂ§ÃƒÂ£o dessa string para inteiro
    if(disciplina[coddisc].aulas->data.mes<=6 && disciplina[coddisc].aulas->data.mes>0)
    {
        disciplina[coddisc].aulas->data.semestre=1;
    }
    else if(disciplina[coddisc].aulas->data.mes>0)
    {
       disciplina[coddisc].aulas->data.semestre=2;
    }
    
    //return disciplina[coddisc].provaTrab[i].data.invertida;
}

void cadastraProvaTrab(char nomeArquivo[], int coddisc)
{
    char op;
    FILE *arquivo;
    strcat(nomeArquivo,".txt");
    printf("Insira o que deseja cadastrar:\nT - Para trabalho;\nP - Para prova;\nE - Para exame; op: ");
    scanf(" %c",&op);
    switch(op)
    {
        case 'P':
        {
            char data[11];
            int data1;
            printf("\n-Cadastrando nova Prova-");
            if((arquivo=fopen(nomeArquivo, "a"))==NULL)
            {
                printf("\nAVISO: Arquivo nao pode ser aberto!");
            }
            else
            {
                arquivo = fopen(nomeArquivo, "a");
                for(int i=0;i<3;i++)
                {
                    if(disciplina[coddisc].provaTrab[i].nome[1] != NULL)
                    {
                        disciplina[coddisc].provaTrab[i].tipo=op;
                        fprintf(arquivo, "\n%c", disciplina[coddisc].provaTrab[i].tipo);

                        printf("-Insira o nome da Prova: ");
                        cin>>disciplina[coddisc].provaTrab[i].nome;
                        fprintf(arquivo, ";%s", disciplina[coddisc].provaTrab[i].nome);

                        printf("-Insira o peso da Prova (0-100): ");
                        cin>>disciplina[coddisc].provaTrab[i].peso;
                        fprintf(arquivo, ";%.2f", disciplina[coddisc].provaTrab[i].peso);
                        
                        printf("-Insira a data da prova: ");
                        cin>>data;
                        data_str(coddisc,i,data);
                        if(disciplina[coddisc].provaTrab[i].data.ano<disciplina[coddisc].ano || disciplina[coddisc].provaTrab[i].data.semestre < disciplina[coddisc].semestre)
                        {
                            printf("--AVISO: Data incorreta, por favor insira uma data vÃƒÂ¡lida!--");
                            printf("-Insira a data da prova: ");
                            cin>>data;
                            data_str(coddisc,i,data);
                        }
                        fprintf(arquivo, ";%s", disciplina[coddisc].provaTrab[i].data.formatada);                        
                        printf("-Prova cadastrada com sucesso!-");
                        break;
                    }
                }
                fclose(arquivo);
            }
        }break;        
        case 'T':
        {
            char data[11];
            int data1;
            printf("\n-Cadastrando novo Trabalho-");
            if((arquivo=fopen(nomeArquivo, "a"))==NULL)
            {
                printf("\nAVISO: Arquivo nao pode ser aberto!");
            }
            else
            {
                arquivo = fopen(nomeArquivo, "a");
                for(int i=4;i<11;i++)
                {
                    if(disciplina[coddisc].provaTrab[i].nome[1] != NULL)
                    {
                        disciplina[coddisc].provaTrab[i].tipo=op;
                        fprintf(arquivo, "\n%c", disciplina[coddisc].provaTrab[i].tipo);

                        printf("-Insira o nome do trabalho: ");
                        cin>>disciplina[coddisc].provaTrab[i].nome;
                        fprintf(arquivo, ";%s", disciplina[coddisc].provaTrab[i].nome);

                        printf("-Insira o peso do trabalho (0-100): ");
                        cin>>disciplina[coddisc].provaTrab[i].peso;
                        fprintf(arquivo, ";%.2f", disciplina[coddisc].provaTrab[i].peso);
                        
                        printf("-Insira a data do trabalho: ");
                        cin>>data;
                        data_str(coddisc,i,data);
                        if(disciplina[coddisc].provaTrab[i].data.ano<disciplina[coddisc].ano || disciplina[coddisc].provaTrab[i].data.semestre < disciplina[coddisc].semestre)
                        {
                            printf("--AVISO: Data incorreta, por favor insira uma data vÃƒÂ¡lida!--");
                            printf("-Insira a data do trabalho: ");
                            cin>>data;
                            data_str(coddisc,i,data);
                        }
                        fprintf(arquivo, ";%s", disciplina[coddisc].provaTrab[i].data.formatada);                        
                        printf("-Trabalho cadastrado com sucesso!-");
                        break;
                    }
                }
                fclose(arquivo);
            }
        }break;
        case 'E':
        {
            char data[11];
            int data1;
            printf("\n-Cadastrando novo Exame-");
            if((arquivo=fopen(nomeArquivo, "a"))==NULL)
            {
                printf("\nAVISO: Arquivo nao pode ser aberto!");
            }
            else
            {
                arquivo = fopen(nomeArquivo, "a");
                for(int i=12;i<14;i++)
                {
                    if(disciplina[coddisc].provaTrab[i].nome[1] != NULL)
                    {
                        disciplina[coddisc].provaTrab[i].tipo=op;
                        fprintf(arquivo, "\n%c", disciplina[coddisc].provaTrab[i].tipo);

                        printf("-Insira o nome do Exame: ");
                        cin>>disciplina[coddisc].provaTrab[i].nome;
                        fprintf(arquivo, ";%s", disciplina[coddisc].provaTrab[i].nome);

                        printf("-Insira o peso do Exame (0-100): ");
                        cin>>disciplina[coddisc].provaTrab[i].peso;
                        fprintf(arquivo, ";%.2f", disciplina[coddisc].provaTrab[i].peso);
                        
                        printf("-Insira a data do Exame: ");
                        cin>>data;
                        data_str(coddisc,i,data);
                        if(disciplina[coddisc].provaTrab[i].data.ano<disciplina[coddisc].ano || disciplina[coddisc].provaTrab[i].data.semestre < disciplina[coddisc].semestre)
                        {
                            printf("-AVISO: Data incorreta, por favor insira uma data vÃƒÂ¡lida!--");
                            printf("-Insira a data do Exame: ");
                            cin>>data;
                            data_str(coddisc,i,data);
                        }
                        fprintf(arquivo, ";%s", disciplina[coddisc].provaTrab[i].data.formatada);                        
                        printf("-Exame cadastrado com sucesso!-");
                        break;
                    }
                }
                fclose(arquivo);
            }
        }break;
        default: printf("\nERRO: Opcao invalida!"); break;
    }
}

void cadastraAula(int i)
{
    FILE *arquivo;
    disciplina[i].aulas = (Aula*)malloc(sizeof(Aula));
    if((arquivo=fopen("aulas.txt", "r+"))==NULL)
    {
        printf("\nAVISO: Arquivo nao pode ser aberto!");
    }
    else
    {
        char data[12];
        printf("\n-Cadastrando aula ministrada-");
        arquivo=fopen("aulas.txt", "a");
        while(disciplina[i].aulas->numOrdem < 0)
        {
            printf("\n-Numero de ordem: ");
            cin >> disciplina[i].aulas->numOrdem;            
        }
        fprintf(arquivo, "%d", disciplina[i].aulas->numOrdem);
        printf("-Data: ");
        cin>>data;
        data_stra(i,data);
        if(disciplina[i].aulas->data.semestre<disciplina[i].semestre && disciplina[i].aulas->data.ano<disciplina[i].ano)
        {
            printf("-AVISO: Data incorreta, por favor insira uma data vÃƒÂ¡lida!--");
            printf("-Data: ");
            cin>>data;
            data_stra(i,data);
        }
        fprintf(arquivo,"\n%s",disciplina[i].aulas->data.formatada);
        printf("-Quantidade de horas associada a aula: 2h");
        disciplina[i].aulas->qtdHoras=2;
        fprintf(arquivo, "\n%.2lf", disciplina[i].aulas->qtdHoras);
        printf("\n-Conteudo dado (250 caracteres): ");
        scanf(" %[^\n]s", disciplina[i].aulas->conteudo);
        fprintf(arquivo, "\n%s", disciplina[i].aulas->conteudo);
    }
}

void cadastraAluno(int d, int qtdAlunos, char nomeDisciplina[50])
{
    int i=0;
    strcat(nomeDisciplina, ".txt");
    FILE *arquivo;
    if(qtdAlunos<0 || qtdAlunos>50)
    {
        printf("\nAVISO: Ocorreu um erro no cadastro!");
    }
    else
    {
        printf("\n-Cadastrando novo aluno-");
        if((arquivo=fopen(nomeDisciplina, "a"))==NULL)
        {
            printf("\nAVISO: Arquivo nao pode ser aberto!");
        }
        else
        {
            arquivo = fopen(nomeDisciplina, "a");
            while(disciplina[d].alunos[i].numero<0 || disciplina[d].alunos[i].numero>50)
            {
                printf("\n-Numero do aluno: ");
                cin >> disciplina[d].alunos[i].nome;                
            }            
            fprintf(arquivo, "%d\n%s", i+1, disciplina[d].alunos[i].numero);
            printf("-Nome do aluno: ");
            cin >> disciplina[d].alunos[i].nome;
            fprintf(arquivo, "\n%s\n", disciplina[d].alunos[i].nome);
            
            //ARRUMAR ISSO AQUI - tava pensnado em fazer uma matriz com os 50 alunos e 14 notas
            disciplina[d].alunos[i].notas = (double*)malloc(qtdAlunos*sizeof(double));
            memset(disciplina[d].alunos[i].notas, 0, sizeof(disciplina[d].alunos[i].notas)); //inicia todas as notas como 0
            fprintf(arquivo, "%.2lf ", disciplina[d].alunos[i].notas);
            
            disciplina[d].alunos[i].notaExame=0;
            fprintf(arquivo, "\n%.2lf", disciplina[d].alunos[i].notaExame);
            disciplina[d].alunos[i].P=0;
            fprintf(arquivo, "\n%d", disciplina[d].alunos[i].P);
            disciplina[d].alunos[i].F=0;
            fprintf(arquivo, "\n%d", disciplina[d].alunos[i].F);
            disciplina[d].alunos[i].situacao=false;
            fprintf(arquivo, "\nfalse");
            disciplina[d].alunos[i].media=0.0;
            fprintf(arquivo, "\n%.2lf", disciplina[d].alunos[i].media);
        }
        fclose(arquivo);
    }
}

void cadastraDisciplina(int qtd)
{
    int i=0, j=0;
    FILE *arquivo;

    if(qtd<0 || qtd>=5)
    {
        printf("\nAVISO: Ocorreu um erro no cadastro!");
    }
    else
    {
        printf("\n-Cadastrando nova disciplina-");
        if((arquivo=fopen("disciplinas.txt", "r+"))==NULL)
        {
            printf("\nAVISO: Arquivo nao pode ser aberto!");
        }
        else
        {
            arquivo = fopen("disciplinas.txt", "a");
            
            for(i=0; i<qtd; i++)
            {
                disciplina[i].indice=j+1;
                printf("\n-Codigo da disciplina: ");
                cin >> disciplina[i].codigo;
                fprintf(arquivo, "%d\n%s", disciplina[i].indice, disciplina[i].codigo);
                printf("-Nome da disciplina: ");
                scanf(" %[^\n]s", disciplina[i].nome);
                fprintf(arquivo, "\n%s", disciplina[i].nome);
                while(disciplina[i].ano<2013 || disciplina[i].ano>2030) {
                    printf("-Ano (2013 ate 2030): ");
                    cin >> disciplina[i].ano;            
                }
                fprintf(arquivo, "\n%d", disciplina[i].ano);
                while(disciplina[i].semestre<1 || disciplina[i].semestre>2) {
                    printf("-Semestre (1 ou 2): ");
                    cin >> disciplina[i].semestre;                
                }
                fprintf(arquivo, "\n%d", disciplina[i].semestre);
                while(disciplina[i].qtdAlunos<0 || disciplina[i].qtdAlunos>50) {
                    printf("-Quantidade de alunos (max: 50): ");
                    cin >> disciplina[i].qtdAlunos;            
                }
                fprintf(arquivo, "\n%d", disciplina[i].qtdAlunos);
                while(disciplina[i].qtdProvas<0 || disciplina[i].qtdProvas>4) {
                    printf("-Quantidade de provas (max: 4): ");
                    cin >> disciplina[i].qtdProvas;
                }
                fprintf(arquivo, "\n%d", disciplina[i].qtdProvas);
                while(disciplina[i].qtdTrabalhos<0 || disciplina[i].qtdTrabalhos>10) {
                    printf("-Quantidade de trabalhos (max: 10): ");
                    cin >> disciplina[i].qtdTrabalhos;    
                }             
                fprintf(arquivo, "\n%d", disciplina[i].qtdTrabalhos);       
                printf("-Carga horaria prevista: 60h");
                disciplina[i].cargaHP = 60;   
                fprintf(arquivo, "\n%d", disciplina[i].cargaHP);
                while(disciplina[i].cargaHR<0 || disciplina[i].cargaHR>60) {
                    printf("\n-Carga horaria realizada: ");
                    cin >> disciplina[i].cargaHR;            
                }
                fprintf(arquivo, "\n%d", disciplina[i].cargaHR);
                printf("\n-Nota minima para aprovacao: 5.0");
                disciplina[i].notaMin = 5;        
                fprintf(arquivo, "\n%lf", disciplina[i].notaMin);
                printf("\n-Percentual minimo de frequencia: 70%");
                disciplina[i].percentualMin = 70;        
                fprintf(arquivo, "\n%lf\n", disciplina[i].percentualMin);  
                printf("\nCadastro realizado com sucesso!\nRedirecionando para o cadastro dos alunos dessa disciplina...\n");
                j++;   

                //chamar o cadastro de alunos aqui - se tem disciplina, precisa de alunos
                cadastraAluno(i, disciplina[i].qtdAlunos, disciplina[i].nome);
            }
        }
        fclose(arquivo);                
    }
}

void cadastraProfessor()
{
    FILE *arquivo = fopen("disciplinas.txt", "w");
    strcpy(professor.nome, "Geraldo");
    fprintf(arquivo, "%s", professor.nome);
    professor.qtdDisciplinas=3;
    fprintf(arquivo, "%d\n", professor.qtdDisciplinas);
    fclose(arquivo);

    //cadastrando as disciplinas 
    cadastraDisciplina(professor.qtdDisciplinas);
}

void editaDadosProfessor()
{
    int i;
    FILE *arquivo, *editado;
    Professor novo, antigo;
    Disciplina aux[5];
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
        scanf("%s", novo.nome);
        while(novo.qtdDisciplinas<0 || novo.qtdDisciplinas>5) {
            printf("-Nova quantidade de disciplinas: ");
            scanf("%d", &novo.qtdDisciplinas);            
        }

        //copiar os dados para uma estrutura auxiliar
        arquivo=fopen("disciplinas.txt", "r");
        while(!feof(arquivo))
        {
            fscanf(arquivo, " %[^\n]s", antigo.nome);
            fscanf(arquivo, "%d", &antigo.qtdDisciplinas);
            fscanf(arquivo, "%d", &aux[i].indice);
            fscanf(arquivo, " %[^\n]s", aux[i].codigo);
            fscanf(arquivo, " %[^\n]s", aux[i].nome);
            fscanf(arquivo, "%d", &aux[i].ano);
            fscanf(arquivo, "%d", &aux[i].semestre);
            fscanf(arquivo, "%d", &aux[i].qtdAlunos);
            fscanf(arquivo, "%d", &aux[i].qtdProvas);
            fscanf(arquivo, "%d", &aux[i].qtdTrabalhos);
            fscanf(arquivo, "%d", &aux[i].cargaHP);
            fscanf(arquivo, "%d", &aux[i].cargaHR);
            fscanf(arquivo, "%lf", &aux[i].notaMin);
            fscanf(arquivo, "%lf", &aux[i].percentualMin);
            i++;  
        }
        fclose(arquivo);

        editado=fopen("disciplinas.txt", "w");
        fprintf(editado, "%s", novo.nome);
        fprintf(editado, "\n%d", novo.qtdDisciplinas);
        int j=0;
        for(j=0; j<i; j++)
        {
        	fprintf(editado, "\n%d", aux[j].indice);
            fprintf(editado, "\n%s", aux[j].codigo);
            fprintf(editado, "\n%s", aux[j].nome);
            fprintf(editado, "\n%d", aux[j].ano);
            fprintf(editado, "\n%d", aux[j].semestre);
            fprintf(editado, "\n%d", aux[j].qtdAlunos);
            fprintf(editado, "\n%d", aux[j].qtdProvas);
            fprintf(editado, "\n%d", aux[j].qtdTrabalhos);
            fprintf(editado, "\n%d", aux[j].cargaHP);
            fprintf(editado, "\n%d", aux[j].cargaHR);
            fprintf(editado, "\n%.2lf", aux[j].notaMin);
            fprintf(editado, "\n%.2lf", aux[j].percentualMin);
        }
        fclose(editado);
    }
}

void editaDadosDisciplina()
{
    int i=0;
    FILE *arquivo, *editado;
    Professor aux;
    Disciplina novo[5], antigo[5];

    if((arquivo=fopen("disciplinas.txt", "r+"))==NULL)
    {
        printf("\nAVISO: Arquivo nao pode ser aberto!");
    }
    else
    {
        //recebe os dados novos - codigo e nome da disciplina nao podem se alterados!
        printf("\n-Editando dados da disciplina-");
        while(novo[i].ano<2013 || novo[i].ano>2030) {
            printf("-Novo ano (2013 ate 2030): ");
            cin >> novo[i].ano;            
        }        
        while(novo[i].semestre<1 || novo[i].semestre>2) {
            printf("-Novo semestre (1 ou 2): ");
            cin >> novo[i].semestre;            
        }
        while(novo[i].qtdAlunos<0 || novo[i].qtdAlunos>50) {
            printf("-Nova quantidade de alunos (max: 50): ");
            cin >> novo[i].qtdAlunos;            
        }
        while(novo[i].qtdProvas<0 || novo[i].qtdProvas>4) {
            printf("-Nova quantidade de provas (max: 4): ");
            cin >> novo[i].qtdProvas;
        }
        while(novo[i].qtdTrabalhos<0 || novo[i].qtdTrabalhos>10) {
            printf("-Nova quantidade de trabalhos (max: 10): ");
            cin >> novo[i].qtdTrabalhos;
        }
        while(novo[i].cargaHP<0 || novo[i].cargaHP>60) {
            printf("\n-Nova carga horaria prevista: ");
            cin >> novo[i].cargaHP;            
        }          
        while(novo[i].cargaHR<0 || novo[i].cargaHR>60) {
            printf("\n-Nova carga horaria realizada: ");
            cin >> novo[i].cargaHR;            
        }         
        while(novo[i].notaMin<0 || novo[i].notaMin>10) {
            printf("\n-Nova nota minima para aprovacao: ");
            cin >> novo[i].notaMin;            
        }        
        while(novo[i].percentualMin<0 || novo[i].percentualMin>100) {
            printf("\n-Novo percentual minimo para aprovacao: ");
            cin >> novo[i].percentualMin;            
        }
              
        //copiando os dados para uma estrutura auxiliar na memoria local
        arquivo=fopen("disciplinas.txt", "r");
        while(!feof(arquivo))
        {
            fscanf(arquivo, " %[^\n]s", aux.nome);
            fscanf(arquivo, "%d", &aux.qtdDisciplinas);
            fscanf(arquivo, "%d", &antigo[i].indice);
            fscanf(arquivo, " %[^\n]s", antigo[i].codigo);
            fscanf(arquivo, " %[^\n]s", antigo[i].nome);
            fscanf(arquivo, "%d", &antigo[i].ano);
            fscanf(arquivo, "%d", &antigo[i].semestre);
            fscanf(arquivo, "%d", &antigo[i].qtdAlunos);
            fscanf(arquivo, "%d", &antigo[i].qtdProvas);
            fscanf(arquivo, "%d", &antigo[i].qtdTrabalhos);
            fscanf(arquivo, "%d", &antigo[i].cargaHP);
            fscanf(arquivo, "%d", &antigo[i].cargaHR);
            fscanf(arquivo, "%lf", &antigo[i].notaMin);
            fscanf(arquivo, "%lf", &antigo[i].percentualMin);
            i++;             
        }
        fclose(arquivo);

        editado=fopen("disciplinas.txt", "w");
        fprintf(editado, "%s", aux.nome);
        fprintf(editado, "\n%d", aux.qtdDisciplinas);
        int j=0;
        for(j=0; j<i; j++)
        {
        	fprintf(editado, "\n%d", antigo[j].indice);
            fprintf(editado, "\n%s", antigo[j].codigo);
            fprintf(editado, "\n%s", antigo[j].nome);
            fprintf(editado, "\n%d", antigo[j].ano);
            fprintf(editado, "\n%d", antigo[j].semestre);
            fprintf(editado, "\n%d", antigo[j].qtdAlunos);
            fprintf(editado, "\n%d", antigo[j].qtdProvas);
            fprintf(editado, "\n%d", antigo[j].qtdTrabalhos);
            fprintf(editado, "\n%d", antigo[j].cargaHP);
            fprintf(editado, "\n%d", antigo[j].cargaHR);
            fprintf(editado, "\n%.2lf", antigo[j].notaMin);
            fprintf(editado, "\n%.2lf", antigo[j].percentualMin);
        }
        fclose(editado);        
    }
}

void consultaAluno(char nome[], int coddisc)
{
    for(int i=0;i<disciplina[coddisc].qtdAlunos;i++)
    {
        if(strcmp(nome,disciplina[coddisc].alunos[i].nome)==0){
            printf("%d ",disciplina[coddisc].alunos[i].numero);
            printf("%s\n",disciplina[coddisc].alunos[i].nome);
            printf("%s\n",disciplina[coddisc].alunos[i].notas);
            printf("%s\n faltas",disciplina[coddisc].alunos[i].F);
            if(disciplina[coddisc].alunos[i].situacao==true){
                printf("\nAtivo");
            }
            else{
                printf("\nInativo");
            }
            break;
        }
    }    
}
void consultaGeral(int coddisc)
{
    for(int i=0; i<disciplina[coddisc].qtdAlunos; i++)
    {
            printf("%d ",disciplina[coddisc].alunos[i].numero);
            printf("%s\n",disciplina[coddisc].alunos[i].nome);
            if(disciplina[coddisc].alunos[i].situacao==true){
                printf("\nAtivo");
            }
            else{
            printf("\nInativo");
        }
          
    }
}   


int main()
{
    int op, op3, op4, op6;
    cadastraProfessor();
    Data *d = (Data*)malloc(sizeof(Data)); 

    do
    {
        //Menu de opcoes
        printf("\nBem vindo ao sistema de controle!");
        printf("\nProfessor: %s\nQuantidade de disciplinas: \n%d", professor.nome, professor.qtdDisciplinas);
        printf("\n\n---MENU DE OPCOES---");
        printf("\n1) Cadastrar nova disciplina"); //validar se nao e maior que 5
        printf("\n2) Cadastrar aluno"); //validar se nao e maior que 50
        printf("\n3) Cotidiano");
        printf("\n4) Mostrar relatorios"); 
        printf("\n5) Consolidar semestre");
        printf("\n6) Editar dados");
        printf("\n0) Sair do sistema de controle\nOpcao: ");
        scanf("\n%d", &op);
        if(op<0 || op>6)
            printf("\nERRO: Opcao invalida!");
        switch(op)
        {
            case 1:
            {
                //Cadastrar disciplina
                if(professor.qtdDisciplinas>=5)
                {
                    printf("\nAVISO: Nao e possivel cadastrar novas disciplinas!");
                }
                else
                {
                    cadastraDisciplina(1);
                }
            }break;

            case 2:
            {
                //Cadastrar aluno
                char auxNome[51];
                Professor auxProf;
                Disciplina aux[5];
                bool encontrou=false;

                FILE *auxArq=fopen("disciplinas.txt", "r");
                
                printf("\nDigite o nome da disciplina: ");
                scanf(" %[^\n]s", auxNome);
                
                int indice, i=0;
                while(!feof(auxArq))
                {
                    fscanf(auxArq, " %[^\n]s", auxProf.nome);
                    fscanf(auxArq, "%d", &auxProf.qtdDisciplinas);
                    fscanf(auxArq, "%d", &aux[i].indice);
                    fscanf(auxArq, " %[^\n]s", aux[i].codigo);
                    fscanf(auxArq, " %[^\n]s", aux[i].nome);
                    fscanf(auxArq, "%d", &aux[i].ano);
                    fscanf(auxArq, "%d", &aux[i].semestre);
                    fscanf(auxArq, "%d", &aux[i].qtdAlunos);
                    fscanf(auxArq, "%d", &aux[i].qtdProvas);
                    fscanf(auxArq, "%d", &aux[i].qtdTrabalhos);
                    fscanf(auxArq, "%d", &aux[i].cargaHP);
                    fscanf(auxArq, "%d", &aux[i].cargaHR);
                    fscanf(auxArq, "%lf", &aux[i].notaMin);
                    fscanf(auxArq, "%lf", &aux[i].percentualMin);      
                    i++;         

                    if(strcmp(auxNome, aux[i].nome)==0)   
                    {
                        encontrou=true;   
                        indice=i;       
                        break;
                    }                  
                    else
                        encontrou=false;
                }
                fclose(auxArq);
                if(encontrou)                            
                    cadastraAluno(indice, 1, aux[i].nome);    
                else
                    printf("\nAVISO: Disciplina nao foi encontrada na base de dados");
            }break;

            case 3:
            {
                //Cotidiano - perguntar se e aula normal ou prova
                do
                {
                    printf("\n---Cotidiano---");
                    printf("\n1) Registrar aula ministrada");
                    printf("\n2) Registrar aula avaliacao"); 
                    printf("\n0) Voltar ao menu\nOpcao: ");
                    cin >> op3;
                    if(op3<0 || op3>2)
                        printf("\nERRO: Opcao invalida!");
                    switch(op3)
                    {
                        case 1:
                        {
                            //Registrar aula ministrada
                            char auxNome[51];
                            Professor auxProf;
                            Disciplina aux[5];
                            bool encontrou=false;

                            FILE *auxArq=fopen("disciplinas.txt", "r");
                            
                            printf("\nDigite o nome da disciplina: ");
                            scanf(" %[^\n]s", auxNome);
                            
                            int indice, i=0;
                            while(!feof(auxArq))
                            {
                                fscanf(auxArq, " %[^\n]s", auxProf.nome);
                                fscanf(auxArq, "%d", &auxProf.qtdDisciplinas);
                                fscanf(auxArq, "%d", &aux[i].indice);
                                fscanf(auxArq, " %[^\n]s", aux[i].codigo);
                                fscanf(auxArq, " %[^\n]s", aux[i].nome);
                                fscanf(auxArq, "%d", &aux[i].ano);
                                fscanf(auxArq, "%d", &aux[i].semestre);
                                fscanf(auxArq, "%d", &aux[i].qtdAlunos);
                                fscanf(auxArq, "%d", &aux[i].qtdProvas);
                                fscanf(auxArq, "%d", &aux[i].qtdTrabalhos);
                                fscanf(auxArq, "%d", &aux[i].cargaHP);
                                fscanf(auxArq, "%d", &aux[i].cargaHR);
                                fscanf(auxArq, "%lf", &aux[i].notaMin);
                                fscanf(auxArq, "%lf", &aux[i].percentualMin);      
                                i++;         

                                if(strcmp(auxNome, aux[i].nome)==0)   
                                {
                                    encontrou=true;   
                                    indice=i;       
                                    break;
                                }                  
                                else
                                    encontrou=false;
                            }
                            fclose(auxArq);
                            if(encontrou)                            
                                cadastraAula(indice);    
                            else
                                printf("\nAVISO: Disciplina nao foi encontrada na base de dados");
                        }break;
                        case 2:
                        {
                            //Registrar aula avaliacao - registrar os dados rotineiros + notas de cada aluno
                            char auxNome[51];
                            Professor auxProf;
                            Disciplina aux[5];
                            bool encontrou=false;

                            FILE *auxArq=fopen("disciplinas.txt", "r");
                            
                            printf("\nDigite o nome da disciplina: ");
                            scanf(" %[^\n]s", auxNome);
                            
                            int indice, i=0;
                            while(!feof(auxArq))
                            {
                                fscanf(auxArq, " %[^\n]s", auxProf.nome);
                                fscanf(auxArq, "%d", &auxProf.qtdDisciplinas);
                                fscanf(auxArq, "%d", &aux[i].indice);
                                fscanf(auxArq, " %[^\n]s", aux[i].codigo);
                                fscanf(auxArq, " %[^\n]s", aux[i].nome);
                                fscanf(auxArq, "%d", &aux[i].ano);
                                fscanf(auxArq, "%d", &aux[i].semestre);
                                fscanf(auxArq, "%d", &aux[i].qtdAlunos);
                                fscanf(auxArq, "%d", &aux[i].qtdProvas);
                                fscanf(auxArq, "%d", &aux[i].qtdTrabalhos);
                                fscanf(auxArq, "%d", &aux[i].cargaHP);
                                fscanf(auxArq, "%d", &aux[i].cargaHR);
                                fscanf(auxArq, "%lf", &aux[i].notaMin);
                                fscanf(auxArq, "%lf", &aux[i].percentualMin);      
                                i++;         

                                if(strcmp(auxNome, aux[i].nome)==0)   
                                {
                                    encontrou=true;   
                                    indice=i;       
                                    break;
                                }                  
                                else
                                    encontrou=false;
                            }
                            fclose(auxArq);
                            if(encontrou)                            
                                cadastraProvaTrab(aux[i].nome, i);
                            else
                                printf("\nAVISO: Disciplina nao foi encontrada na base de dados");
                        }break;
                        default: printf("\nVoltando ao menu...\n"); break;
                    }
                }while(op3!=0);   
            }break;

            case 4:
            {
                //Mostrar relatorios
                do
                {
                    printf("\n---Relatorios---");
                    printf("\n1) Consultar aluno");
                    printf("\n2) Listagem geral de uma disciplina"); //pergunta por codigo
                    printf("\n0) Voltar ao menu\nOpcao: ");
                    cin >> op4;
                    if(op4<0 || op4>5)
                        printf("\nERRO: Opcao invalida!");                    
                    switch(op4)
                    {
                        case 1:
                        {
                            int cods;
                            char nome[25];
                            printf("\nInsira o nome do aluno a ser exibido: ");
                            scanf("%[^\n]s",nome);
                            printf("\nInsira o cÃƒÂ³digo da disciplina que ele cursa: ");
                            scanf("%d",&cods);
                            consultaAluno(nome, cods);
                        }break;
                        case 2:
                        {
                            int cods;
                            printf("\nInsira o cÃƒÂ³digo da disciplina para a listagem: ");
                            cin>>cods;
                            consultaGeral(cods);
                        }break;

                        default: printf("\nVoltando ao menu...\n"); break;
                    }
                }while(op4!=0);

            }break;

            case 5:
            {
                //Consolidar semestre - calcula as medias e as % de frequencias
                char auxNome[51];
                Professor auxProf;
                Disciplina aux[5];
                bool encontrou=false;

                FILE *auxArq=fopen("disciplinas.txt", "r");
                
                printf("\nDigite o nome da disciplina: ");
                scanf(" %[^\n]s", auxNome);
                
                int indice, i=0;
                while(!feof(auxArq))
                {
                    fscanf(auxArq, " %[^\n]s", auxProf.nome);
                    fscanf(auxArq, "%d", &auxProf.qtdDisciplinas);
                    fscanf(auxArq, "%d", &aux[i].indice);
                    fscanf(auxArq, " %[^\n]s", aux[i].codigo);
                    fscanf(auxArq, " %[^\n]s", aux[i].nome);
                    fscanf(auxArq, "%d", &aux[i].ano);
                    fscanf(auxArq, "%d", &aux[i].semestre);
                    fscanf(auxArq, "%d", &aux[i].qtdAlunos);
                    fscanf(auxArq, "%d", &aux[i].qtdProvas);
                    fscanf(auxArq, "%d", &aux[i].qtdTrabalhos);
                    fscanf(auxArq, "%d", &aux[i].cargaHP);
                    fscanf(auxArq, "%d", &aux[i].cargaHR);
                    fscanf(auxArq, "%lf", &aux[i].notaMin);
                    fscanf(auxArq, "%lf", &aux[i].percentualMin);      
                    i++;         

                    if(strcmp(auxNome, aux[i].nome)==0)   
                    {
                        encontrou=true;   
                        indice=i;       
                        break;
                    }                  
                    else
                        encontrou=false;
                }
                fclose(auxArq);
                if(encontrou)     
                {
                    printf("\n-Consolidando semestre-");
                    //consolida o semestre   
                    //chama a funcao para calcular medias, frequencias e percentual                 
                }
                else
                    printf("\nAVISO: Disciplina nao foi encontrada na base de dados");
            }break;
            
            case 6:
            {
                //Editar dados
                do
                {
                    printf("\n---Editar dados---");
                    printf("\n1) Editar dados professor");
                    printf("\n2) Editar dados disciplina");  
                    printf("\n0) Voltar ao menu\nOpcao: ");
                    cin >> op6;
                    //fazer validacao - se for menor que 0 ou maior que 2
                    if(op6<0 || op6>2)
                        printf("\nERRO: Opcao invalida!");                                        
                    switch(op6)
                    {
                        case 1:
                        {
                            //Editar dados professor
                            editaDadosProfessor();
                        }break;
                        case 2:
                        {
                            //Editar dados disciplina
                            editaDadosDisciplina();
                        }break;
                        default: printf("\nVoltando ao menu...\n"); break;
                    }
                }while(op6!=0);                
            }break;        

            default: printf("\nSaindo do sistema...\n"); break;    
        }
    }while(op!=0);
}