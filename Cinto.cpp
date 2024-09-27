// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Cinto.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const string RED = "\033[1;31m";
const string RESET = "\033[0m";

#ifndef CINTO_H
#define CINTO_H

Cinto::Cinto(){
    //Inicializar o contador
    count = 0;
}

Cinto::~Cinto(){
    cout << "Cinto desalocado" << endl;
}

bool Cinto::CintoVazio(){
    return count == 0; // retorna true se a quantidade de itens no cinto for 0
}

bool Cinto::CintoCheio(){
    return count == MAX_CINTO; // retorna true se a quantidade de itens no cinto for igual a definida como a maxima
}

void Cinto::InserirItem(Elemento x, int p){
    if(CintoCheio()){
        cout << "O cinto esta cheio! Nao e possivel adicionar outro item." << endl;
        return;
    }

    if(p < 1 || p > count+1){
        //O item não pode entrar em índices menores que 0 e nem maiores que o count mais 1, 
        //são posições inválidas para uma lista
        cout << "Nao e possivel alocar o item nesse espaco! Ultrapassa o tamanho do cinto." << endl;
        return;
    }

    if(pesodositens+x.peso > MAX_PESOCINTO){
        // nao pode adicionar caso exceda o quanto o cinto suporta de peso
        cout << "Nao e possivel alocar o item no cinto, execedera seu limite de peso!" << endl;
        return;
    }

    for(int i = count; i >= p; i--){
        // Só podemos adicionar itens dentro do tamanho setado por MAX_CINTO
        Entry [i + 1] = Entry[i];
    }
    
    //adiciona x no lugar da posição p
    Entry[p] = x;
    pesodositens += x.peso;
    count ++;
    cout << "ADICIONOU BB" << endl;
}

void Cinto::DeletarItem(Elemento &x, int p){
    if(CintoVazio()){
        cout << "Nao ha itens para retirar." << endl;
        return;
    }
    if(p < 1 || p > count){
        cout << "Posicao invalida!" << endl;
        return;
    }

    x = Entry[p]; //x recebe o valor da posição p
    pesodositens -= Entry[p].peso; // tira o peso do item a ser removido
    // remover o item
    for(int i = p + 1; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count --;
}

int Cinto::TamanhoCinto(){
    // Retorna quantos itens tem no cinto
    return count;
}

void Cinto::LimparCinto(){
    //Função que retira todos os itens do cinto
    count = 0;
    cout << "Os itens foram removidos do cinto!" << RESET << endl;
}

void Cinto::RetornaItem(Elemento &x, int p){
    //Retorno dos itens que o Heroi possui
    if( p < 1 || p > count +1){
        cout << "Nao existem itens nessa posicao!" << endl;
        return;
    }
    x = Entry[p];
    cout << "O item que esta nessa posicao e: " << x.nome << endl;
}

void Cinto::RetornaTodosItens() {
    if (CintoVazio()) {
        cout << RED << "Cinto esta vazio!" << RESET << endl;
        return;
    }

    cout << RED << "Itens que o heroi possui no cinto:" << RESET << endl;
    for (int i = 1; i < count+1; i++) {
        cout << RED << "[" << i << "] " << RESET << Entry[i].nome;
        
        if (Entry[i].tipo == 'P') {
            cout << " (Cura: " << Entry[i].cura << " HP)";
        } else {
            cout << " (Dano: " << Entry[i].dano << " HP)";
        }
        cout << endl;
    }
}


#endif