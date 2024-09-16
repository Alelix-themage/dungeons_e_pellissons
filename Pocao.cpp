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


int Pocao::RetornarCura(){
    return cura;
}

void Pocao::CriarPocao(int dificuldade, int num_niveis){
    
    static std::mt19937 gen(std::random_device{}());
    
    // intervalo da pocao
    int minCura = 5;
    int maxCura = 25;

    // gerar pocao no intervalo
    std::uniform_int_distribution<> distr(minCura, maxCura);
    cura = distr(gen);

    // formula pra ajustar de acordo com a dif
    cura = minCura + (cura - minCura) * dificuldade / num_niveis;
}

#endif