#include<bits/stdc++.h> 
using namespace std;

int main() 
{ 
    struct LISTA 
    { 
        int num; 
        LISTA *prox; 
        LISTA *ant; 
    }; 
    LISTA *inicio = NULL; 
    LISTA *fim = NULL; 
    LISTA *aux; 
    int op, numero, achou; 
    do 
    { 
        //cout é o equivalente ao printf 
        cout<<"\n MENU DE OPÇÕES \n"; 
        cout<<"\n 1- Inserir na lista"; 
        cout<<"\n 2- Consultar a lista do inicio ao fim"; 
        cout<<"\n 3- Consultar a lista do fim ao inicio"; 
        cout<<"\n 4- Remover da lista"; 
        cout<<"\n 5- Esvaziar a lista"; 
        cout<<"\n 6- Sair"; 
        cout<<"\n Digite a sua opcao:"; 
        //cin é o equivalente ao scanf 
        cin>>op; 
        if(op< 1|| op>6) 
            cout<<" Opcao invalida!\n"; 

        if(op == 1) //inserção de elementos 
        { 
            cout<<"Digite o Elemento!"; 

            LISTA *novo = new LISTA(); 
            cin>> novo -> num; 
            if(inicio == NULL)// lista esta vazia 
            { 
                novo -> prox = NULL; 
                novo -> ant = NULL; 
                inicio = novo; 
                fim = novo; 
            }// fim if 
            else // significa que existem elementos na lista 
            { 
                aux = inicio; 
                while( aux != NULL && novo -> num > aux -> num) 
                { 
                    aux = aux -> prox; 
                }// fim while 
                if(aux == inicio) // if 01 o elemento a é o menor de todos 
                { 
                    novo -> prox = inicio; 
                    novo -> ant = NULL; 
                    inicio -> ant = novo; 
                    inicio = novo;  
                }// fim if 01 
                else if(aux == NULL) //if 02 o elemento é o maior de todos 
                { 
                    fim -> prox = novo; 
                    novo -> ant = fim; 
                    fim = novo; 
                    fim -> prox = NULL; 
                }//fim if 02 
                else //else 02 o elemento será inserido no meio da lista 
                { 
                    novo -> prox = aux; 
                    aux -> ant -> prox = novo; 
                    novo -> ant = aux -> ant; 
                    aux -> ant = novo; 
                }// fim else 02 
            }// fim else 
        }//fim if op==1 

        if(op == 2)// consultar a lista do inicio ao fim 
        { 
            if( inicio == NULL) 
                cout<<"LISTA VAZIA!\n"; 
            else //lista contem elementos 
            { 
                cout<<"Consultando lista do inicio ao fim"; 
                aux = inicio; 
                while(aux != NULL) 
                { 
                    cout<< aux -> num << " " ; 
                    aux = aux -> prox;  
                }// fim while 
            }// fim do else 
        }//fim op==2 

        if(op == 3) //consultar a lista do fim ao inicio 
        { 
            if( inicio == NULL) 
                cout<<"LISTA VAZIA!\n"; 
            else //lista contem elementos 
            { 
                cout<<"Consultando lista do inicio ao fim"; 
                aux = fim; 
                while(aux != NULL) 
                { 
                    cout<< aux -> num << " " ; 
                    aux = aux -> ant; 
                }// fim while 
            }// fim do else 
        }// fim op==3 

        if(op == 4) // remover elemento da lista 
        { 
            if( inicio == NULL) 
                cout<<"LISTA VAZIA!\n"; 
            else //a lista contem elementos 
            { 
                cout<<"Digite o elemento a ser removido:"; 
                cin >> numero; 
                aux = inicio; 
                achou = 0; 

                while(aux != NULL) 
                { 
                    if(aux -> num == numero) //if 01 encontrei 
                    { 
                        achou = achou + 1; 
                        if(aux == inicio) // if 02 elemento é primeiro da lista 
                        { 
                            inicio = aux -> prox; 
                            if(inicio != NULL) 
                            inicio -> ant = NULL; 

                            delete(aux); 
                            aux = inicio; 
                        }// fim if 02 

                        else if(aux == fim) //if 03 elemento é o último 
                        { 
                            fim = fim -> ant; 
                            fim -> prox = NULL; 
                            delete(aux); 
                            aux = NULL; 
                        }// fim if 03 
                        else// else 04 elemento esta no meio 
                        { 
                            aux -> ant -> prox = aux -> prox; 
                            aux -> prox -> ant = aux -> ant; 

                            LISTA *aux2; 
                            aux2 = aux -> prox; 

                            delete(aux); 
                            aux = aux2; 
                        }// fim else 04 
                    }// fim if 01  else //ainda não encontrou o numero 
                    aux = aux -> prox; 
                }// fim while 
                if(achou == 0) 
                    cout<<"Elemento não encontrado!\n"; 
                else if(achou == 1) 
                    cout<<"Elemento removido 1 vez\n"; 
                else 
                    cout<<"Numero removido"<< achou<<"vezes!\n"; 
            }// fim else 
        }// fim op == 4 

        if(op == 5) // Esvaziar a lista 
        { 
            if( inicio == NULL) 
                cout<<"LISTA VAZIA!\n"; 
            else // a lista será esvaziada 
            { 
                aux = inicio; 
                while( aux != NULL ) 
                { 
                    inicio = inicio -> prox; 
                    delete(aux); 
                    aux = inicio; 
                } // fim do while 
                cout<<"Lista Esvaziada!\n"; 
            }//fim do else 
        }// fim do op==5  
    }while(op != 6); 
    return 0; 
}