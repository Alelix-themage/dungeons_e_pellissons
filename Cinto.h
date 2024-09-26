// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <iostream>
#include "Elemento.h"
//Classe responsável pelo cinto do Heroi

const int MAX_CINTO = 5;
const int MAX_PESOCINTO = 15;

class Cinto{
    public:
        Cinto();
        ~Cinto();
        bool CintoVazio();
        bool CintoCheio();
        void InserirItem(Elemento x, int p); // x é o elemento, e p é o índice (posição)
        void DeletarItem(Elemento &x, int p);
        int TamanhoCinto();
        void LimparCinto();
        void RetornaItem(Elemento &x, int p);
        void RetornaTodosItens();
    private:
        Elemento Entry[MAX_CINTO+1];
        int count;
        int pesodositens = 0; // variavel pra verificar se n excedeu o limite de peso
};