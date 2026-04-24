#include<iostream>
#include<stdlib.h>

using namespace std;

#define TAM 6

struct address{
    char chave;
    struct address *prox;
};

typedef struct address no;

typedef struct LISTA{
    no *inicio;
    int tam;
};

void imprime(LISTA *l){
    no *atual;
    atual = l->inicio;

    while(atual != NULL){
        cout << atual->chave << endl;
        atual = atual->prox;
    }
    cout << "cabo" << endl;
}

void insere_inicio(LISTA *l, int valor, no *atual){
    // novo no por lista dinamica
    no *novo = (no*) malloc(sizeof(no));
    novo->chave = valor;
    novo->prox = NULL;

    if(l->inicio == NULL){
        l->inicio = novo; // o novo eh o inicio
    }
    else{
        atual = l->inicio; // se nao tiver vazia
        while (atual->prox != NULL){ // enquanto ouver proximos na lista
            atual = atual->prox; // percorre a lista
        }
        atual->prox = novo; // saiu do for significa que chegou no ultimo
        l->tam ++; // aumenta o tamanho da lista
    }
}

void separaListas(LISTA *f1, LISTA *f2, LISTA *f3){
    no *atual_l1, *atual_l2, *atual_l3;
    atual_l1 = f1->inicio; 
    atual_l2 = f2->inicio; 
    atual_l3 = f3->inicio;
    
    
    while (atual_l1 != NULL){
        if(isalpha(f1->inicio->chave)){
            insere_inicio(f2, atual_l1->chave, atual_l2);
        }else{
            insere_inicio(f3, atual_l1->chave, atual_l3);
        }
        atual_l1 = atual_l1->prox;
    }
    
}

int main(){
    LISTA l1;

    no no1;
    no no2;
    no no3;
    no no4;

    l1.inicio = &no1;
    l1.tam = TAM;

    no1.chave = '1';
    no1.prox = &no2;

    no2.chave = 'a';
    no2.prox = &no3;
    
    no3.chave = '2';
    no3.prox = &no4;
    
    no4.chave = 'b';
    no4.prox = NULL;

    LISTA l2;
    LISTA l3;

    l2.inicio = NULL;
    l2.tam = TAM/2;

    l3.inicio = NULL;
    l3.tam = TAM;

    separaListas(&l1, &l2, &l3);
    imprime(&l1);
    imprime(&l2);
    imprime(&l3);
}