// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <string>
#include <random>
#include "Elemento.h"
using namespace std;

#ifndef ELEMENTO_H
#define ELEMENTO_H

// Função para criar uma arma
Elemento criarArma(int dificuldade, int num_niveis) {
    // nomes para as armas
    static const string nomesarmasp[10] = { 
    "Karambit",
    "Faca Tramontina",
    "Espada Curta",
    "Porrete",
    "Garrafa de vidro quebrada",
    "Marreta do Zoio",
    "Clava",
    "Espada Longa",
    "Katana",
    "Lanca Tribal"
    };
    
    // inicializa o elemento
    Elemento item;
    item.tipo = 'A';
    item.peso = 10;

    // escolhe um nome random para arma
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> distrNome(0, 9);
    item.nome = nomesarmasp[distrNome(gen)];

    // gerar dano random
    int minDano = 5;
    int maxDano = 40;
    std::uniform_int_distribution<> distrDano(minDano, maxDano);
    item.dano = distrDano(gen);
    item.dano = minDano + (item.dano - minDano) * dificuldade / num_niveis;

    return item;
}
   

// Função para criar uma poção
Elemento criarPocao(int dificuldade, int num_niveis) {
    static const string nomesarmasg[5] = { // nomes das pocoes
    "Pocao de Cura",
    "Pocao da Vida",
    "Semente dos Deuses",
    "Canja de Galinha",
    "Copao Muito Loko"
    };

    // inicializa o item
    Elemento item;
    item.tipo = 'P';
    item.peso = 3;

    // escolhe um nome random para pocao
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> distrNome(0, 4);
    item.nome = nomesarmasg[distrNome(gen)];

    // gerar cura random
    int minCura = 5;
    int maxCura = 25;
    std::uniform_int_distribution<> distrCura(minCura, maxCura);
    item.cura = distrCura(gen);
    item.cura = minCura + (item.cura - minCura) * dificuldade / num_niveis;

    return item;
}

#endif