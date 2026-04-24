#include <iostream>

using namespace std;

#define TAM 4

typedef struct PILHA{
    int A[TAM];
    int top;
};

void init(PILHA *p){
    if(p->top != -1){
        cout << "Pilha ja inicializada";
        return;
    }
    p->top = -1;
}

void imprimePilha(PILHA *p){
    int n = p->top;

    if(p->top == -1){
        cout << "pilha vazia";
        return;
    }
    while (n != -1){
        cout << p->A[n] << endl;
        n--;
    }
}

void invertePilha(PILHA *p){
    
    if (p->top == -1){
        cout << "Pilha nao inicializada" << endl;
        return;
    }
    
    int fim = p->top;
    int inicio = 0;
    int aux;
    while (inicio < fim){
        aux = p->A[inicio];
        p->A[inicio] = p->A[fim];
        p->A[fim] = aux;
        inicio ++;
        fim --;
    }

    cout << "Lista invertida" << endl;
}


int main(){
    PILHA pilha;

    pilha.A[0] = 1;
    pilha.A[1] = 2;
    pilha.A[2] = 3;
    pilha.A[3] = 4;
    pilha.top = 3;

    imprimePilha(&pilha);
    invertePilha(&pilha);
    imprimePilha(&pilha);

    return 0;
}