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
        string Nome();
        void TomarPocao(int cura);
        void TomarDano(int dano);
    private:  
        // nome e vida do Herói só pode ser acessada por métodos da classe herói
        string nome; 
        int vidaatual = 100;
        const int maxvida = 100;
        
        //Cinto e Mochila do Heroi
        Cinto cintoHeroi;
        Mochila mochilaHeroi;

};

