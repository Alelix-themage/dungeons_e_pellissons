#include "Mochila.h"
#include <iostream>
using namespace std;


// contrutor

Mochila :: Mochila(){
    capacidade = 5; // capacidade inicial
    itens = new int[capacidade]; // ira alocar dinamicamente a capacidade da mochila 
    topo = 0; // inicia o topo vazio
}

Mochila :: ~Mochila(){
    delete[] itens; // vai liberar a memoria que foi alocada anteriormente

}

bool Mochila :: MochilaFull(){
    return topo == capacidade ; // caso a mochila estiver cheia ira informar ao jogador
}

bool Mochila :: MochilaEmpty(){
    return topo == 0; // ira informar ao jogador caso a mochila estiver vazia
}

void Mochila :: MochilaPush(int x){
    if (MochilaFull()){
        //Quando a mochila estiver cheia ela vai triplicar o tamanho ao jogador
        capacidade *= 3;
        int* maisEspaco= new int[capacidade];

        // traz os itens antigos ao novo armazenamento dinamico
        for (int i=0; i<=topo; i++){
            maisEspaco[i] = itens[i];
        }
        // apaga o armazenamento inicial e usa o novo armazenamento (dinamico)
        delete[] itens;
        itens = maisEspaco;
    }

    topo ++; // incrementa topo
    itens[topo] = x; // incrementa itens no top
}

void Mochila :: MochilaPop(int &x){
    if(MochilaEmpty()){ // verifica se a mochila esta vazia
        cout << "Mochila ja esta vazia não tem como remover mais itens! " << endl;

    }else{
        x = itens[topo]; // pega os itens do topo
        topo --; // retira os itens do topo
    }
}