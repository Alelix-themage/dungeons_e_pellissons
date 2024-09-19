#include "Monstro.h"
#include <iostream>
#include <string>

Monstro::Monstro(){
    //Construtor
    vida = 15;
    dano = 5;
}

Monstro::~Monstro(){
    //Destrutor
    std::cout << "Monstro foi finalizado." << std::endl;
}

void Monstro::DefinirNome(std::string n){
    //Define o nome do Monstro
    nome = n;
    std::cout << "O nome do monstro e: " << n;
}

int Monstro::RetornarHP(){
    //Retorna o HP do monstro
    return vida;
}

void Monstro::TomarDano(int dano){
    // Da o Dano no monstro
    vida = vida - dano;
    std::cout << "Voce deu um ataque no " << nome << " e tirou " << vida << "de vida" << std::endl;
}

void Monstro::EvolucaoMonstro(){
    //Evolui o monstro a cada nivel 
    //Método deve ser chamado a cada subida de nível
    vida = vida * 2; //Pode ser alterado
    dano =  dano * 2;

}