#include "Heroi.h"
#include <string>
#include <iostream>
using namespace std;

const string RED = "\033[1;31m";
const string RESET = "\033[0m";

#ifndef HEROI_H
#define HEROI_H

Heroi::Heroi(){
    vida = 100;
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

void Heroi::TomarPocao(int cura){
    vida += cura;
};

#endif