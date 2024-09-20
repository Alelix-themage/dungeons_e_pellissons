#include "Elemento.h"
#include "Mochila.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// compilar g++ -std=c++11 testemochila.cpp Elemento.cpp Mochila.cpp -o testemochila.exe

int main(){

    Mochila m1;
    Elemento itens_criados[5];

    for (int i = 0; i < 5; i++) {
        if(i % 2 == 0) {
            criarArma(itens_criados[i], 1, 5);
        } else {
            criarPocao(itens_criados[i], 1, 5);
        }  
    }

    for (int i = 0; i < 5; i++) {
        if (itens_criados[i].tipo == 'A') {
            cout << "Arma criada: " << itens_criados[i].nome << ", Dano: " << itens_criados[i].dano << "\n";
        } else {
            cout << "Pocao: " << itens_criados[i].nome << ", Cura: " << itens_criados[i].cura << "\n";
        }
        
    }

    for(int i = 0; i < 5; i++){
        m1.MochilaPush(itens_criados[i]);
        cout << "Itens na mochila: " << m1.MochilaSize() << endl;
    }
    for(int i = 0; i < m1.MochilaSize(); i++){
        Elemento item;
        m1.MochilaPop(item);
        cout << "Item: " << item.nome << endl;
        cout << "Itens na mochila: " << m1.MochilaSize() << endl;
    }

    return 0;
}