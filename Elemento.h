// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <string>
using namespace std;

struct Elemento {
    string nome;
    char tipo; // P = pocao A = arma
    int peso;
    int dano;
    int cura;
};

Elemento criarArma(int dificuldade, int num_niveis);
Elemento criarPocao(int dificuldade, int num_niveis);