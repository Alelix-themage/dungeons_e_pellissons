#include <iostream>
#include <string>

//Classe responsável por detalhar os comportamentos e atributos do monstro
class Monstro {
    public:
        Monstro();
        ~Monstro();
        void DefinirNome(std::string n );
        int RetornarHP();
        void TomarDano(int dano);
        void EvolucaoMonstro();

    private: 
    //Características fundamentais do monstro
        std::string nome;
        int vida;
        int dano;



};