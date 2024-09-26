#include "Elemento.h"
#include "Cinto.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// compilar g++ -std=c++11 testecinto.cpp Elemento.cpp Cinto.cpp -o testecinto.exe

int main() {

    // criar itens random para teste
    Elemento itens_criados[10];

    for (int i = 0; i < 10; i++) {
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

    Cinto cinto_heroi;
    Elemento itemtemp;

    cinto_heroi.RetornaTodosItens();

    cinto_heroi.InserirItem(itens_criados[4], cinto_heroi.TamanhoCinto() + 2);
    cout << "Itens no Cinto: " << cinto_heroi.TamanhoCinto() << endl;
    cinto_heroi.InserirItem(itens_criados[3], cinto_heroi.TamanhoCinto() + 1);
    cout << "Itens no Cinto: " << cinto_heroi.TamanhoCinto() << endl;
    cinto_heroi.InserirItem(itens_criados[2], cinto_heroi.TamanhoCinto() + 1);
    cout << "Itens no Cinto: " << cinto_heroi.TamanhoCinto() << endl;
    cout << "Itens no Cinto: " << cinto_heroi.TamanhoCinto() << endl;

    cinto_heroi.RetornaTodosItens();

    cinto_heroi.RetornaItem(itemtemp, 3);
    if (itemtemp.tipo == 'A') {
            cout << "Arma criada: " << itemtemp.nome << ", Dano: " << itemtemp.dano << "\n";
        } else {
            cout << "Pocao: " << itemtemp.nome << ", Cura: " << itemtemp.cura << "\n";
        } 
    return 0;
}