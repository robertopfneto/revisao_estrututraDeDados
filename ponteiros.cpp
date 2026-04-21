#include <iostream>
#include <stdlib.h>

// Ponteiros são variavéis que armazenam um endereço de memória
using namespace std;

void exemplo_ponteiros(){
    int x;
    int *p;

    x = 10;
    p = &x;

    cout << "Acessando valor de x pelo ponteiro p: " << *p << endl;
    cout << "Endereço de x" << &x << endl;
}

void trocando_valores(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x, y;
    x = 2;
    y = 5;

    cout << "Antes: " << endl;
    cout << "Valor de x: " << x << endl;
    cout << "Valor de y: " << y << endl;
    
    trocando_valores(&x, &y);

    cout << "\nDepois: " << endl;
    cout << "Valor de x: " << x << endl;
    cout << "Valor de y: " << y << endl;
    
}
