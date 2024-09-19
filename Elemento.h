// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#ifndef ELEMENTO_H  
#define ELEMENTO_H  

#include <string>
using namespace std;

struct Elemento {
    string nome;
    char tipo; // P = pocao A = arma
    int peso;
    int dano;
    int cura;
};

void criarArma(Elemento &item_temp, int dificuldade, const int num_niveis); // funcao pra criar arma
void criarPocao(Elemento &item_temp, int dificuldade, const int num_niveis); // funcao pra criar cinto

#endif