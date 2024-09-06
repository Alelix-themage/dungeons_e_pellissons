// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include <string>
#include <iostream>
using namespace std;


//Uma função Global que gera danos nos personagens
void ReceberDano(int dano);


//Classe responsável pelas funcionalidades e atributos do heroi
class Heroi{
    public:
        Heroi();
        ~Heroi();
        void EscolherNome(string nome);
    private:  
        // nome e vida do Herói só pode ser acessada por métodos da classe herói
        string nome; 
        int vida;
};

//Classe responsável pelo comportamento dos objetos do tipo Monstro
class Monstro {
    public:
        Monstro();
        ~Monstro();
        

    private:
        string nome;
        int vida = 50; //50
    
};

struct Arma {
    //tipo de dado responsável pelas especificações da arma
    int dano = 25; //25

};
