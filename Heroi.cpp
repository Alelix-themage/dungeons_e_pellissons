// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Heroi.h"
#include <string>
#include <iostream>
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
    return mochilaheroi;
}

#endif