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