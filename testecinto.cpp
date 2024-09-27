#include "Cinto.h"
#include "Elemento.h"
#include <iostream>
#include <string>
#include <chrono> // tempo atual do pc
using namespace std;

int main() {

    Cinto c1;
    Elemento itens[10];
    for (int i = 0; i < 10; i++){
        criarArma(itens[i], 1, 1);
    }
    for (int i = 0; i < 10; i++){
        cout << "Nome: " << itens[i].nome << endl;
        c1.InserirItem(itens[i], 1);
        cout << "Itens no cinto: " << c1.TamanhoCinto() << endl;
    }

    c1.RetornaTodosItens();

    return 0;
}
