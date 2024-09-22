#include <iostream>
#include <string>
using namespace std;

//Classe responsável por detalhar os comportamentos e atributos do monstro
class Monstro {
    public:
        Monstro(int dificuldade, int num_niveis);
        ~Monstro();
        string Nome();
        int Atacar();
        int RetornarHP(); // retornar vida
        int MaxHP(); // retornar total de vida pro display
        void TomarDano(int dano);
    private: 
    //Características fundamentais do monstro
        string nome;
        int maxvida;
        int vida_atual;
        int danoataque;
};