// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <string>
#include <iostream>
using namespace std;

class Heroi{
    public:
        Heroi();
        ~Heroi();
        void DefinirNome(string n);
        int RetornarHP();
        string Nome();
    private:  
        // nome e vida do Herói só pode ser acessada por métodos da classe herói
        string nome; 
        int vida;
};

