#include<iostream>

using namespace std;

#define TAM 8

struct FILA{
    int A[TAM];
    int inicio;
    int qnt_elementos;
};


void exibeFila(FILA *f){
    int i = f->inicio; 
    int j;
    for(j=0; j < f->qnt_elementos; j++){
        cout << f->A[i] << " ";
        i = (i + 1) % TAM;
    }
    cout<<endl;
}

void uneFilas(FILA *f1, FILA *f2, FILA *f3){
    f3->qnt_elementos = TAM;
    f3->inicio = 0;

    int i1 = 0, i2 = 0, j = 0;
    while(i1 < f1->qnt_elementos){
        f3->A[j] = f1->A[i1];
        j++;
        i1++;

        f3->A[j] = f2->A[i2];
        j++;
        i2++;
    }
}

int main(){
    FILA f1;
    FILA f2;

    f1.A[0] = 1;
    f1.A[1] = 2;
    f1.A[2] = 3;
    f1.A[3] = 4;

    f2.A[0] = 10;
    f2.A[1] = 20;
    f2.A[2] = 30;
    f2.A[3] = 40;

    f1.inicio = 0;
    f2.inicio = 0;

    f1.qnt_elementos = TAM/2;
    f2.qnt_elementos = TAM/2;

    // exercicio
    FILA f3;
    uneFilas(&f1, &f2, &f3);
    exibeFila(&f3);
    return 0;
}