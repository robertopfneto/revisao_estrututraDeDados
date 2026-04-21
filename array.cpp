#include<iostream>


using namespace std;
#define MAX 10
#define TIPOCHAVE int
typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int n_elementos;
} LISTA;

// verifica consistencia
// inserir na lista um novo registro
// busca sequencial
// excluir elemento na lista
// exibir lista

bool initArray(LISTA *l);
bool isArrayConsistent(LISTA *l, int i);

void insertList(LISTA *l, REGISTRO reg, int i);
int sequentialSearch(LISTA *l, TIPOCHAVE chave);

bool removeElementByKey(LISTA *l, TIPOCHAVE chave);

void showList(LISTA *l);

void menu(int resposta, LISTA *l);


// fazer as verificações antes de cada;
int main(){
    LISTA lista;
    int resposta = 0;

    lista.n_elementos = -1;

    do{
        cout << "Deseja iniciar a manipulação de listas? 1 - Sim | 0 - Não " << endl;
        cin >> resposta;
    }while(resposta != 1 && resposta != 0);
    
    menu(resposta, &lista);
    
}
    
bool initArray(LISTA *l){
    // se a lista de elementos não existir
    if (l->n_elementos == -1){
        l->n_elementos = 0; // inicializa = 0
        cout << "Lista inicializada com sucesso! " << endl;
        return true;
    }
    cout << "Lista já está inicializada! " << endl;
    return false;
}

bool isArrayConsistent(LISTA *l, int i){
    if(l->n_elementos <= MAX || i < MAX || i >= 0) 
        return true;
    cout << "A estrutura do array não está consistente" << endl;
    return false;
}

void insertList(LISTA *l, REGISTRO reg, int i){
    int j;
    for(j = l->n_elementos; j > i; j--)
        l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->n_elementos ++;
}

int sequentialSearch(LISTA *l, TIPOCHAVE chave){
    for(int i = 0; i < l->n_elementos; i++){
        if(l->A[i].chave == chave){
            cout << "Elemento encontrado na posição: " << i << endl;
            return l->A[i].chave;
        }
    }
    return -1;       
}

bool removeElementByKey(LISTA *l, TIPOCHAVE chave){
    int pos = sequentialSearch(l, chave);
    if(pos == -1)
        return false;

    for(int j = pos; j < l->n_elementos-1; j++)
        l->A[j] = l->A[j+1];
    
    l->n_elementos--;
    return true;
}

void showList(LISTA *l){
    for (int i = 0; i < l->n_elementos; i++)
        cout << "\nPosicao: " << i << " \nChave: " << l->A[i].chave << endl;
    cout << l->n_elementos << endl;
}

void menu(int resposta, LISTA *l){
    int isInitialized = false;

    cout << "Processo Inicializado!" << endl;

    do{
        cout << "\n---- MANIPULACAO DE LISTAS ----" << endl;
        cout << "\n0 - Encerrar Processo " << endl;
        cout << "1 - Inicializar Lista " << endl;
        cout << "2 - Inserir registro na Lista " << endl;
        cout << "3 - Procurar registro na Lista " << endl;
        cout << "4 - Remover registro Lista " << endl;
        cout << "5 - Exibir Lista de Registros " << endl;
        cin >> resposta;

        // inicializa e lista
        switch (resposta){
            case 1:
                isInitialized = initArray(l);
                break;

            case 2:
                if (isInitialized){
                    REGISTRO aux;
                    int pos;
                    cout << "\nQual o valor que deseja inserir na lista?" << endl;
                    cin >> aux.chave;

                    cout << "\nEm qual posição deseja inserir o registro?" << endl;
                    cin >> pos;

                    if(isArrayConsistent(l, pos)){
                        insertList(l, aux, pos);
                    }
                }
                else cout << "Lista não inicializada" << endl;
                break;
            
            case 3:
                if (isInitialized){
                    TIPOCHAVE valor_chave;
                    cout << "\nQual o valor que deseja procurar na lista?" << endl;
                    cin >> valor_chave;

                    int pos_registro = sequentialSearch(l, valor_chave);
                    if(pos_registro == -1) 
                        cout << "\nChave não encontrada na lista! " << endl;
                }
                else 
                    cout << "\nLista não inicializada" << endl; 
                break;
            
            case 4:
                int valor_chave;
                bool isRemoved;

                cout << "\n\n Insira o valor da chave a ser removida: " << endl;
                cin >> valor_chave;

                if (isInitialized){
                    isRemoved = removeElementByKey(l, valor_chave);
                    if(isRemoved)
                        cout << "\nElemento removido com sucesso!" << endl;
                    else
                        cout << "\nNão foi possível remover o elemento" << endl;
                }else 
                    cout << "\nLista não inicializada" << endl; 
            case 5:
                if (isInitialized)
                    showList(l);
                else 
                    cout << "\nLista não inicializada" << endl; 
                break;

            default:
                cout << "\nProcesso finalizado :)";
                break;
        }   
    }while(resposta != 0);
}
