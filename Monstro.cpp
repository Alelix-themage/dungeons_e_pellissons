// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040"

#include "Monstro.h"
#include <iostream>
#include <string>
#include <random>
#include <chrono> // tempo atual do pc
using namespace std;

// CORES
const string RED = "\033[1;31m";
const string RESET = "\033[0m";

// nomes para as armas
static const string nomesmonstros[10] = { 
"Debugogro",
"Bruxo dos dados",
"Stackvampire",
"Orc",
"Troll",
"Morto-vivo",
"Goblin Safado",
"Elemental de Fogo",
"Gigante",
"Urutu-Cruzeiro"
};

Monstro::Monstro(int dificuldade, int num_niveis){
    // Construtor

    // GERADOR NUMEROS RANDOM
    random_device rd;
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // gerar numero random a partir do tempo atual
    
    // gerar nome random da lista
    uniform_int_distribution<> distrNome(0, 9);
    nome = nomesmonstros[distrNome(gen)];
    
    
    // gerar vida do monstro random
    int minVidaMonstro = 5;
    int maxVidaMonstro = 100;
    uniform_int_distribution<> distrVida(minVidaMonstro, maxVidaMonstro);
    maxvida = distrVida(gen);
    maxvida = minVidaMonstro + (maxvida - minVidaMonstro) * dificuldade / num_niveis; // gera conforme a dificuldade
    vida_atual = maxvida;

    // gerar ataque do monstro random
    int minDanoMonstro = 1;
    int maxDanoMonstro = 20;
    uniform_int_distribution<> distrDano(minDanoMonstro, maxDanoMonstro);
    danoataque = distrDano(gen);
    danoataque = minDanoMonstro + (danoataque - minDanoMonstro) * dificuldade / num_niveis;
}

Monstro::~Monstro(){
    // Destrutor
}

string Monstro::Nome(){
    return nome;
}

int Monstro::Atacar(){
    return danoataque;
}

int Monstro::RetornarHP(){
    // Retorna o HP do monstro
    return vida_atual;
}

int Monstro::MaxHP(){
    // Retorna o HP do monstro
    return maxvida;
}

void Monstro::TomarDano(int dano){
    // Da o Dano no monstro
    vida_atual -= dano;
    cout << RESET << "\nVoce deu um ataque em " << RED << nome << RESET << " e tirou " << RED << dano << RESET << " de vida." << endl;
}