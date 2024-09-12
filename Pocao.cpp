// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Pocao.h"
#include <iostream>
#include <random>
using namespace std;


#ifndef POCAO_H
#define POCAO_H

Pocao::Pocao(){

}

Pocao::~Pocao(){

}


int Pocao::Curar(){
    return cura;
}

void Pocao::CriarPocao(int dificuldade){
    // FALTA IMPLEMENTAR DIFICULDADE
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(5, 25);
    cura = distr(gen);
}

#endif