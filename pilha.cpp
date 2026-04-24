#include <iostream>
#include <stdlib.h>

using namespace std;

// toda vez que eu digitar TIPOCHAVE ele vai ser compilado como int;
#define TIPOCHAVE int
#define MAX 10

// estrutura que representa um REGISTRO
typedef struct REGISTRO{
    TIPOCHAVE chave;
};

// estrutura que representa uma Pilha
typedef struct Pilha{
    REGISTRO A[MAX];
    int top; // variável de controle de pilha
};

// Métodos da Pilha:
void initPilha(Pilha *p);
void exibePilha(Pilha *p);

bool isPilhaCheia(Pilha *p);
bool isPilhaVazia(Pilha *p);

bool push(Pilha *p, REGISTRO reg); // Adiciona registro
void menu(Pilha *p);
int buscaregistro(Pilha *p, TIPOCHAVE valor_chave);

int main(){
    Pilha p;
    menu(&p);
    return 0;
}

void initPilha(Pilha *p){
    p->top = -1;
    cout << "Pilha iniciada" << endl;
}

void exibePilha(Pilha *p){
    if(isPilhaVazia(p)){
        cout << "Pilha vazia!";
        return;   
    }
    int qnt_registros = p->top;
    for(int i = qnt_registros; i >= 0; i--){
        cout << "\nregistro: " << i << "\nValor: " << p->A[i].chave << endl;
    }
}

bool isPilhaCheia(Pilha *p){
    return (p->top == MAX-1);
}

bool isPilhaVazia(Pilha *p){
    return (p->top == -1);
}

bool push(Pilha *p, REGISTRO reg){
    if (isPilhaCheia(p)){
        cout << "\nPilha Cheia! Nao foi possivel inserir mais registros na pilha";
        return false; 
    }
    
    cout << "\nDigite um valor para a chave do registro: " << endl;
    cin >> reg.chave;

    p->top++;
    p->A[p->top] = reg;

    cout << "\nRegistro adicionado com sucesso";
    return true;
}

bool pop(Pilha *p){
    if (isPilhaVazia(p)){
        cout << "Não ha registros a serem removidos" << endl;
        return false;
    }
    cout << "O registro de valor " << p->A[p->top].chave << " foi deletado";
    p->top--;
    return true;
}

int buscaregistro(Pilha *p, TIPOCHAVE valor_chave){
    for (int i = 0; i < p->top; i++){
        if(valor_chave == p->A[i].chave)
           return i; 
    }
    return -1;
}


void menu(Pilha *p){
    int resposta = -1;

    do{
        cout << "----  MANIPULACAO DE PILHAS ----" << endl;
        cout << "Selecione sua opcao:\n1-Inicializar Pilha \n2-Verificar se a Pilha esta vazia \n3-Verificar se a Pilha esta cheia \n4-Exibir Pilha  \n5-Adicionar registro\n6-Remover registro" << endl;
        cin >> resposta;

        switch (resposta){
            case 1:
                initPilha(p);
                break;
            
            case 2:
                (isPilhaVazia(p)) ? cout << "\nPilha vazia" : cout << "\nA pilha nao esta vazia";
                break;

            case 3:
                (isPilhaCheia(p)) ? cout << "\nPilha cheia" : cout << "\nAinda ha espaco disponivel na Pilha";
                break;

            case 4:
                exibePilha(p);
                break;

            case 5:
                REGISTRO new_reg;
                push(p, new_reg);
                break;

            case 6:
                pop(p);
                break;

            default:
                break;

        }
    }while(resposta != -1);
}
