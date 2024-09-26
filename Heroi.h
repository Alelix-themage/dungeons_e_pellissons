// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <string>
#include "Cinto.h"
#include "Mochila.h"
using namespace std;

class Heroi{
    public:
        Heroi();
        ~Heroi();
        void DefinirNome(string n);
        int RetornarHP();
        int RetornarDano();
        string Nome();
        void TomarPocao(Elemento pocao);
        void EquiparArma(Elemento arma);
        void TomarDano(int dano);
        Mochila& AcessarMochila();
        void MenuMochila(Heroi &player);
        Cinto& AcessarCinto();
        void MenuCinto(Heroi &player);
        void Descansar();
    private:  
        // nome e vida do Herói só pode ser acessada por métodos da classe herói
        Mochila mochilaHeroi;
        Cinto cintoHeroi;
        string nome;
        int dano_atual = 5; // dano padrão do heroi, como um 'soco'
        int vida_atual = 100;
        Elemento armaatual;
        const int maxvida = 100;
};

