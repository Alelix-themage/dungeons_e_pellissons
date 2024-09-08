#include "Heroi.h"
#include <string>
#include <iostream>
using namespace std;

const string RED = "\033[1;31m";
const string RESET = "\033[0m";

#ifndef HEROI_H
#define HEROI_H

Heroi::Heroi(){
    vida = 10;
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
    return vida;
};

void Heroi::TomarDano(int dano){
    vida -= dano;
    cout << "O heroi tomou " << dano << " de dano!" << endl;
};

#endif