#include <iostream>
#include <stdlib.h>

using namespace std;

//estruturas
struct address{
    int chave;
    // posso ter outros atributos aqui
    char nome[30];
    char rua[30];
    char email[80];

    // lista duplamente encadeada
    struct address *prox; // aponta para o endereço do proximo elemento
};

typedef struct address no;

// lista de controle

typedef struct{
    no *inicio;
    int TAM;
} LISTA;

// Métodos a serem implementados
// 1- Inicializar

// 2 - Inserir no Início
// 3 - Inserir no Fim

// 4 - Remover no 
// no de remoçãatualInício
// 5 - Remover no Fim

// 6 - Inserir em posição específica
// 7 - Remover elemento específico com base na chave

void init(LISTA *l);
void imprime(LISTA *l);

// nos inseres, a verificação é se o próximo eh nulo
void insereInicio(LISTA *l);
void insereFim(LISTA *l);

// aqui a verificação eh se o atual eh nulo 
void removeInicio(LISTA *l);
void removeFim(LISTA *l);

void insere_posicao(LISTA *l);
void remove_base_especifica(LISTA *l);


int main(){
   
    return 0;
}

void init(LISTA *l){
    l->inicio = NULL;
    l->TAM = 0;

    cout << "\n Lista iniciada encadeada!" << endl;
}

void imprime(LISTA *l){
    no *atual;
    int contador = 0;

    cout << "Tamanho da Lista: " << l->TAM << endl;
    while (atual != NULL){
        cout << "Chave: " << atual->chave << endl;
        atual = atual->prox;
        contador++;
    }
    cout << "Fim da lista! Ela foi percorrida " << contador << "vezes" << endl;
}

// malloc aloca um ponto de memoria nao utlizado para um ponteiro

void insereInicio(LISTA *l, int valor){
    no* novo_no = (no*) malloc(sizeof(no));
    
    novo_no->chave = valor;

    

}

void insereFim(LISTA *l);

void removeInicio(LISTA *l);

void removeFim(LISTA *l);

void insere_posicao(LISTA *l);


void remove_base_especifica(LISTA *l){
    if (l->inicio == NULL){
        cout << "Lista Vazia!" << endl;
        return;
    }

    // ponteiros atual e anterior
    no *atual;
    no *anterior;
    atual = l->inicio;

}

