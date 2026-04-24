#include <iostream>

using namespace std;
#define MAX 6

// defino int como tipo_chave para facilitar a troca de tipos
typedef int TIPOCHAVE;

// fila circular

typedef struct REGISTRO{
    TIPOCHAVE chave;
};  

typedef struct FILA{
    REGISTRO A[MAX];
    int inicio;
    int qnt_elementos;
};



bool isQueueFull(FILA *f);
bool isQueueInicialized(FILA *f);

void initQueue(FILA *f);
void enqueue(FILA *f, REGISTRO reg);
void unqueue(FILA *f);
void exibeFila(FILA *f);

void menu(FILA *f);
int main(){         
    FILA fila;
    menu(&fila);


    return 0;
}

void menu(FILA *f){
    int resposta = -1;

    do{
        cout << "---- MANIPULACAO DE FILAS ----";
        cout << "Qual operacao deseja realizar?\n\n1-Inicializar fila \n2-Adicionar registro da fila \n3-Remover registro da fila \n4-Exibir fila";

        switch (resposta)
        {
            case 1:
                if(isQueueInicialized(f)) cout << "Fila já inicializada!";
                else{
                    initQueue(f);
                    cout << "Pilha inicializada com sucesso" << endl;
                }
                break;
            
            case 2:
                if(isQueueInicialized){
                    REGISTRO aux;
                    enqueue(f, aux);
                    cout << "Registro adicionado na fila";
                } else cout << "Lista não inicializada" << endl;
                break;

        
            case 3:
                if(isQueueInicialized){
                    unqueue(f);
                } else cout << "Lista não inicializada" << endl;
                break;
        
            
            case 4:
                if(isQueueInicialized){
                    exibeFila(f);
                } else cout << "Lista não inicializada" << endl;
                break;
        
            default:
                break;
        }
        
    }while(resposta != -1);
}

void initQueue(FILA *f){
    f->inicio = -1;
    f->qnt_elementos = 0;
}

bool isQueueFull(FILA *f){
    return (f->qnt_elementos >= MAX);
}
bool isQueueInicialized(FILA *f){
    return(f->qnt_elementos > 0);
}

int retornaPosicao(FILA *f){
    return (f->inicio + f->qnt_elementos) % MAX;
}

void enqueue(FILA *f, REGISTRO reg){
    int pos;

    if (f->qnt_elementos == MAX){
        cout << "Fila cheia, nao eh possivel inserir mais elementos" << endl;
        return;
    }

    pos = retornaPosicao(f);
    cout << "Informe o valor da chave para o registro que voce quer inserir: ";
    cin >> reg.chave;
    f->qnt_elementos ++;
    f->A[pos] = reg;

    cout << "Registro de chave: " << reg.chave << "\nPosicao no array: " << pos << endl;
    cout << "Insercao realizada com sucesso!! " << endl; 
}

void unqueue(FILA *f){
    if (f->qnt_elementos == 0){
        cout << "Fila vazia, nao eh possivel remover mais elementos" << endl;
        return;
    }

    f->inicio =( f->inicio+1) % MAX;
    f->qnt_elementos --;
    cout << "Registro removido da fila" << endl;
    cout << "Elementos restantes: " << f->qnt_elementos << "/" << MAX << endl;
}

void exibeFila(FILA *f){
    int i = f->inicio; 
    int j;
    for(j=0; j < f->qnt_elementos; j++){
        cout << f->A[i].chave << " ";
        i = (i + 1) % MAX;
    }
    cout<<endl;
}

