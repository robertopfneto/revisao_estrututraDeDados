#include <iostream>
#include <stdlib.h>

using namespace std;


struct address{
    int chave;
    struct address *prox;
};

typedef struct address no;

typedef struct LISTA{
    no *inicio;
    int tam;
};


// métodos

void init(LISTA *l){
    l->inicio = NULL;
    l->tam = 0;
}

void insere_inicio(LISTA *l, int valor){
    // novo no por lista dinamica
    no *novo = (no*) malloc(sizeof(no));
    no *atual;
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

void imprime(LISTA *l){
    no *atual;
    atual = l->inicio;

    while(atual != NULL){
        cout << atual->chave << endl;
        atual = atual->prox;
    }
    cout << "cabo" << endl;
}

void remover(LISTA *l, int valor){
    if(l->inicio == NULL){
        cout << "Lista vazia" << endl;
        return;
    }

    // LISTA DUPLAMENTE ENCADEADA AQUI
    no *atual;
    no *anterior;

    atual = l->inicio;
    anterior = NULL;

    while (atual != NULL && atual->chave != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL){
        cout << "Nao encontrou o valor" << endl;
    }

    // remover no inicio
    if(anterior == NULL){
        l->inicio = atual->prox;
    }else{ // se for no meio
        anterior->prox =atual->prox;
    }
    // libera espaço na memoria
    free(atual);

    l->tam --;
    cout << "Elemento " << valor << "removido com sucesso";
    
}

