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

    cout << "Itens na mochila: " << m1.MochilaSize() << endl;
    m1.MochilaPush(itens_criados[0]);
    cout << "Itens na mochila: " << m1.MochilaSize() << endl;
    Elemento topomochila;
    m1.MochilaTop(topomochila);
    cout << "Item no topo da mochila: " << topomochila.nome << endl;
    m1.MochilaPush(itens_criados[1]);
    cout << "Itens na mochila: " << m1.MochilaSize() << endl;
    m1.MochilaTop(topomochila);
    cout << "Item no topo da mochila: " << topomochila.nome << endl;

    return 0;
}