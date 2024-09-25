// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Heroi.h"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

const string RED = "\033[1;31m";
const string RESET = "\033[0m";

#ifndef HEROI_H
#define HEROI_H

Heroi::Heroi(){
    
};

Heroi::~Heroi(){

};

void Heroi::DefinirNome(string n){
    nome = n;
};

string Heroi::Nome(){
    return nome;
};

int Heroi::RetornarHP(){
    return vidaatual;
};

void Heroi::TomarDano(int dano){
    vidaatual -= dano;
    cout << "Voce tomou " << dano << " de dano." << endl;
}

void Heroi::TomarPocao(int cura){
    int vidaantesdacura = vidaatual;
    if (vidaatual + cura > maxvida) {
    vidaatual = maxvida; // verificar se não vai curar a mais do max de vida do heroi
} else {
    vidaatual += cura; 
}
    cout << "Voce tomou a pocao e recuperou " << vidaatual - vidaantesdacura << " pontos de HP";
};

Mochila& Heroi::AcessarMochila(){ // metodo para acessar mochila do heroi
    
    if (mochilaheroi.MochilaSize() == 0){
        cout << "Sua mochila ta vazia!! XD" << endl;
        abort();
    }
    cout << "\nItens na mochila: ";
    for (int i = 0; i < mochilaheroi.MochilaSize(); i++){
        Elemento item = mochilaheroi.AcessarItem(i);
        cout << "[" << i + 1 << "]: " << item.nome << " (";
        if(item.cura > 0){
            cout << "Cura: " << item.cura << " HP";
        }else if(item.dano > 0 ){
            cout << "Dano: " << item.dano << " HP";
            cout << " )" << endl;
        }

    }
    int opcao;
    
    do {
        cout << "Escolha um item para usar (1 a " << mochilaheroi.MochilaSize() << "), ou 0 para cancelar: ";
        cin >> opcao;

        //verifica se a entrada ta valida
        if(cin.fail() || opcao < 0 || opcao > mochilaheroi.MochilaSize()){
            cin.clear(); //limpa se tiver erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n' ); // limpa a entrada
            cout << "Opcao invalida! tente de novo! " << endl;
            opcao = -1; // vai forcar a repeticao do looping
        }

    }
    while (opcao < 0 || opcao > mochilaheroi.MochilaSize());

    //Se o jogador escolher o 0
    if(opcao == 0){
        cout << "Voce cancelou o uso do item! " << endl;
        return;
    }

    //Processar o item escolhido
    Elemento itemEscolhido = mochilaheroi.AcessarItem(opcao - 1);
    if(itemEscolhido.cura > 0){
        //pocao de cura
        cout << "Voce usou " << itemEscolhido.nome << " e curou " << itemEscolhido.cura << " HP. " << endl;
        TomarPocao(itemEscolhido.cura); // vai curar o heroi

    }else if(itemEscolhido.dano > 0){
        // equipar arma
        cout << "Voce equipou " << itemEscolhido.nome << " com dano de " << itemEscolhido.dano << " HP " << endl;

    }
    // remocar item da mochila
    mochilaheroi.RemoveItem(opcao -1);

    
    
    return mochilaheroi;
}

#endif