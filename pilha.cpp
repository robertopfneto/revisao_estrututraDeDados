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
bool pop(Pilha *p, REGISTRO *regRemovido); // Remove registro

bool catchTopo(Pilha *p, REGISTRO *regTopo); // pega registro do topo
int qntElementos(Pilha *p); // retorna quantidade de elementos da Pilha

void esvaziarPilha(Pilha *p); // apaga todos os registros da pilha
void buscarValor(Pilha *p, int valor); // busca por registro com determinado valor

int main(){

    return 0;
}

void initPilha(Pilha *p){
    p->top = -1;
    
}