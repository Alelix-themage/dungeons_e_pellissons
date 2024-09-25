// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Heroi.h"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

const string RED = "\033[1;31m";
const string RESET = "\033[0m";

#ifndef HEROI_H
#define HEROI_H

Heroi::Heroi(){
    
};

Heroi::~Heroi(){

};

void Heroi::DefinirNome(string n){
    nome = n;
};

string Heroi::Nome(){
    return nome;
};

int Heroi::RetornarHP(){
    return vida_atual;
};

void Heroi::TomarDano(int dano){
    vida_atual -= dano;
    cout << "Voce tomou " << dano << " de dano." << endl;
}

void Heroi::TomarPocao(int cura){
    int vidaAntesCura = vida_atual;
    if (vida_atual + cura > maxvida) {
    vida_atual = maxvida; // verificar se não vai curar a mais do max de vida do heroi
} else {
    vida_atual += cura; 
}
    cout << "Voce tomou a pocao e recuperou " << vida_atual - vidaAntesCura << " pontos de HP";
};

Mochila& Heroi::AcessarMochila(){ // metodo para acessar mochila do heroi
    
    if (mochilaHeroi.MochilaSize() == 0){
        cout << "Sua mochila ta vazia!! XD" << endl;
        abort();
    }
    cout << "\nItens na mochila: ";
    for (int i = 0; i < mochilaHeroi.MochilaSize(); i++){
        Elemento item = mochilaHeroi.AcessarItem(i);
        cout << "[" << i + 1 << "]: " << item.nome << " (";
        if(item.cura > 0){
            cout << "Cura: " << item.cura << " HP";
        }else if(item.dano > 0 ){
            cout << "Dano: " << item.dano << " HP";
            cout << " )" << endl;
        }

    }
    int opcao;
    
    do {
        cout << "Escolha um item para usar (1 a " << mochilaHeroi.MochilaSize() << "), ou 0 para cancelar: ";
        cin >> opcao;

        //verifica se a entrada ta valida
        if(cin.fail() || opcao < 0 || opcao > mochilaHeroi.MochilaSize()){
            cin.clear(); //limpa se tiver erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n' ); // limpa a entrada
            cout << "Opcao invalida! tente de novo! " << endl;
            opcao = -1; // vai forcar a repeticao do looping
        }
    }
    while (opcao < 0 || opcao > mochilaHeroi.MochilaSize());

    //Se o jogador escolher o 0
    if(opcao == 0){
        cout << "Voce cancelou o uso do item! " << endl;
        return;
    }

    //Processar o item escolhido
    Elemento itemEscolhido = mochilaHeroi.AcessarItem(opcao - 1);
    if(itemEscolhido.cura > 0){
        //pocao de cura
        cout << "Voce usou " << itemEscolhido.nome << " e curou " << itemEscolhido.cura << " HP. " << endl;
        TomarPocao(itemEscolhido.cura); // vai curar o heroi

    }else if(itemEscolhido.dano > 0){
        // equipar arma
        cout << "Voce equipou " << itemEscolhido.nome << " com dano de " << itemEscolhido.dano << " HP " << endl;

    }
    // remocar item da mochila
    mochilaHeroi.RemoveItem(opcao -1);

    
    
    return mochilaHeroi;
}


void Heroi::AcessarCinto() {
    // método responsável por permitir que o usuário acesse o cinto

    // Exibe todos os itens no cinto
    cintoHeroi.RetornaTodosItens();

    char op; // Variável para armazenar a opção do usuário
    while (true) {
        cout << "Deseja pegar algum item do cinto? (s/n)" << endl;
        cin >> op;

        if (op == 'S' || op == 's') {
            int p; // Para armazenar a posição do item escolhido
            cout << "Escolha um item do cinto (1 a " << cintoHeroi.TamanhoCinto() << "): ";
            cin >> p;

            // Validação da entrada
            while (p < 1 || p > cintoHeroi.TamanhoCinto()) {
                cout << "Posição inválida! Tente novamente: ";
                cin >> p;
            }

            Elemento x; // variável responsável por armazenar o item escolhido pelo usuário
            cintoHeroi.RetornaItem(x, p); 
            cout << "Você pegou o item: " << x.nome << endl; 
            if(x.tipo == 'P'){
                vida_atual = vida_atual + x.cura;
                cout << "Heroi recebe "  << x.cura << " de HP" << endl;
            }
            else {
                cout << "O heroi pegou " <<  x.nome << "." << endl;
            }
            break; 
        }

        if (op == 'N' || op == 'n') {
            cout << "Você não pegou nada do cinto!" << endl;
            break;
        } else {
            cout << "Tecla não permitida! Selecione s ou n!" << endl; 
        }
    }
}


#endif