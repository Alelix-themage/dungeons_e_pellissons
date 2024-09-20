// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Cinto.h"
#include <iostream>
using namespace std;

#ifndef CINTO_H
#define CINTO_H

Cinto::Cinto(){
    //Inicializar o contador
    count = 0;
}

Cinto::~Cinto(){
    cout << "Cinto destruido!" << endl;
}

bool Cinto::CintoVazio(){
    count == 0;
    cout << "O cinto esta vazio! E possivel inserir um item" << endl;
    return 0;
}

bool Cinto::CintoCheio(){
    count == MAX_CINTO;
    cout << "Nao e possivel adicionar itens, o cinto esta cheio!" << endl;
    return 0;
}

void Cinto::InserirItem(int x, int p){
    if(CintoCheio()){
        cout << "O cinto esta cheio! Nao e possivel adicionar outro item." << endl;
        abort();
    }

    if(p < 1 || p > count+1){
        //O item não pode entrar em índices menores que 0 e nem maiores que o count mais 1, 
        //são posições inválidas para uma lista
        cout << "Nao e possivel alocar o item nesse espaco! Ultrapassa o tamanho do cinto." << endl;
    }

    for(int i = count; i >= p; i--){
        // Só podemos adicionar itens dentro do tamanho setado por MAX_CINTO
        Entry [i + 1] = Entry[i];
    }
    //adiciona x no lugar da posição p
    Entry[p] = x;
    count ++;
}

void Cinto::DeletarItem(int &x, int p){
    if(CintoVazio()){
        cout << "Nao ha itens para retirar." << endl;
    }

    if(p < 1 || p > count + 1){
        cout << "Posicao invalida!" << endl;
        abort();
    }

    x = Entry[p]; //x recebe o valor da posição p
    for(int i = p + 1; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count --;
}

int Cinto::TamanhoCinto(){
    // Retorna o tamanho da Mochila e os itens inseridos
    if(CintoVazio()){
        cout << "Ainda nao ha itens no cinto!" << endl;
    }
    else{
        cout << "Seu cinto possui: " << count << " itens" << endl;
    }

}

void Cinto::LimparCinto(){
    //Função que retira todos os itens do cinto
    count = 0;
    cout << "Os itens foram removidos do cinto!" << endl;
}

void Cinto::RetornaItem(int &x, int p){
    //Retorno dos itens que o Heroi possui
    if( p < 1 || p > count +1){
        cout << "Nao existem itens nessa posicao!" << endl;
        abort();
    }
    x = Entry[p];
    cout << "O item que esta nessa posicao e: " << x << endl;
}

#endif