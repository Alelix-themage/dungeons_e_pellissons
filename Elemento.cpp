// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <string>
#include <random>
#include <chrono> // tempo atual do pc
#include <cstdlib> // abort
#include "Elemento.h"
using namespace std;



// Função para criar uma arma
void criarArma(Elemento &item_temp, int dificuldade, int num_niveis) {
    // GERADOR NUMEROS RANDOM
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // gerar numero random a partir do tempo atua

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
    

    item_temp.tipo = 'A';
    item_temp.peso = 7;

    // escolhe um nome random para arma
    uniform_int_distribution<> distrNome(0, 9);
    item_temp.nome = nomesarmasp[distrNome(gen)];

    // gerar dano random de acordo com a dificuldade
    int minDano = 5;
    int maxDano = 40;
    uniform_int_distribution<> distrDano(minDano, maxDano);
    item_temp.dano = distrDano(gen);
    item_temp.dano = minDano + (item_temp.dano - minDano) * dificuldade / num_niveis;
    item_temp.cura = 0;
}
   

// Função para criar uma poção
void criarPocao(Elemento &item_temp, int dificuldade, int num_niveis) {
    // GERADOR NUMEROS RANDOM
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // gerar numero random a partir do tempo atua
    
    static const string nomesarmasg[5] = { // nomes das pocoes
    "Pocao de Cura",
    "Pocao da Vida",
    "Semente dos Deuses",
    "Canja de Galinha",
    "Copao Muito Loko"
    };

    item_temp.tipo = 'P';
    item_temp.peso = 3;

    // escolhe um nome random para pocao
    uniform_int_distribution<> distrNome(0, 4);
    item_temp.nome = nomesarmasg[distrNome(gen)];

    // gerar cura random + dificuldade
    int minCura = 5;
    int maxCura = 25;
    uniform_int_distribution<> distrCura(minCura, maxCura);
    item_temp.cura = distrCura(gen);
    item_temp.cura = minCura + (item_temp.cura - minCura) * dificuldade / num_niveis;
    item_temp.dano = 5;
}