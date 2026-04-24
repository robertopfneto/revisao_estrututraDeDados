#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

#define TAM 6

struct address {
    char chave;
    address *prox;
};

typedef address no;

struct LISTA {
    no *inicio;
    int tam;
};

void imprime(LISTA *l) {
    no *atual = l->inicio;

    while (atual != NULL) {
        cout << atual->chave << endl;
        atual = atual->prox;
    }
    cout << "cabo" << endl;
}

void insere_fim(LISTA *l, char valor) {
    no *novo = (no*) malloc(sizeof(no));
    novo->chave = valor;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        no *atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }

    l->tam++;
}

void separaListas(LISTA *f1, LISTA *f2, LISTA *f3) {
    no *atual_l1 = f1->inicio;

    while (atual_l1 != NULL) {
        if (isalpha(atual_l1->chave)) {
            insere_fim(f2, atual_l1->chave);
        } else {
            insere_fim(f3, atual_l1->chave);
        }
        atual_l1 = atual_l1->prox;
    }
}

int main() {
    LISTA l1;

    no no1;
    no no2;
    no no3;
    no no4;

    l1.inicio = &no1;
    l1.tam = 4;

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
    l2.tam = 0;

    l3.inicio = NULL;
    l3.tam = 0;

    separaListas(&l1, &l2, &l3);

    cout << "Lista original:" << endl;
    imprime(&l1);

    cout << "Lista de letras:" << endl;
    imprime(&l2);

    cout << "Lista de nao letras:" << endl;
    imprime(&l3);

    return 0;
}