// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040"

#include "Mochila.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const string RED = "\033[1;31m";
const string RESET = "\033[0m";

// contrutor

Mochila :: Mochila(){
    quantidade = 0; // capacidade inicial
    topo = NULL; // inicia o topo vazio
}

Mochila :: ~Mochila(){
    MochilaClear(); // vai liberar a memoria que foi alocada anteriormente
}

void Mochila :: MochilaPush(Elemento x){
    PonteiroMochila p; 
    p = new SlotMochila; // alocando slot dinamicamente
    if (p==NULL){
        cout << "Falha na alocacao da mochila, memoria insuficiente para rodar o jogo!!!" << endl;
        abort();
    }
    p->Item = x;
    p->ProximoItem = topo;
    topo = p;
    quantidade ++; // incrementa quantidade de itens
    cout << RED << x.nome << RESET << " adicionado a mochila!" << endl;
}

void Mochila :: MochilaPop(Elemento &x){
    if(MochilaEmpty()){ // verifica se a mochila esta vazia
        cout << "Mochila ja esta vazia nao tem como remover mais itens! " << endl;
        abort();
    }
    PonteiroMochila p;
    x = topo->Item;
    p = topo;
    topo = topo->ProximoItem;
    delete p;
    quantidade--;
}

void Mochila :: MochilaClear() {
    PonteiroMochila p;
    while(topo != NULL) {
        p = topo;
        topo = topo->ProximoItem;
        delete p;
    }
}

void Mochila :: MochilaTop(Elemento &x){
    x = topo->Item;
}

bool Mochila :: MochilaFull(){
    return false ; // mochila tem tamanho infinito
}

bool Mochila :: MochilaEmpty(){
    return topo == NULL; // ira informar ao jogador caso a mochila estiver vazia
}

int Mochila :: MochilaSize(){
    return quantidade;
}

void Mochila :: TopoMochila(){
    Elemento itemtopo;
    MochilaTop(itemtopo);
    if (itemtopo.tipo == 'P') {
        cout << RED << "ULTIMO ITEM DA MOCHILA: " << RESET << itemtopo.nome << " (Cura: " << itemtopo.cura << " HP)" << endl;
    } else {
        cout << RED << "ULTIMO ITEM DA MOCHILA: " << RESET << itemtopo.nome << " (Dano: " << itemtopo.dano << " HP)" << endl;
    }
}