// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Heroi.h"
#include "Elemento.h"
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
    Elemento armainicial; // inicializar arma atual
    armainicial.nome = "Soco";
    armainicial.dano = 5;
    armainicial.tipo = 'A';
    armaatual = armainicial;
};

Heroi::~Heroi(){
    cout << "Heroi desalocado" << endl;
};

void Heroi::DefinirNome(string n){
    nome = n;
};

string Heroi::Nome(){
    return nome;
};

Elemento& Heroi::ArmaAtual(){
    return armaatual;
}

int Heroi::RetornarHP(){
    return vida_atual;
};

int Heroi::RetornarDano(){
    return dano_atual;
};

void Heroi::TomarDano(int dano){
    vida_atual -= dano;
}

void Heroi::TomarPocao(Elemento pocao){
    int vidaAntesCura = vida_atual;
    if (vida_atual + pocao.cura > maxvida) {
    vida_atual = maxvida; // verificar se não vai curar a mais do max de vida do heroi
} else {
    vida_atual += pocao.cura; 
}
    cout << RESET << "\nVoce tomou " << RED << pocao.nome << RESET << " e recuperou " << RED << vida_atual - vidaAntesCura << RESET <<" pontos de HP" << endl;
};

void Heroi::Descansar(){
    int vidaAntesCura = vida_atual;
    if (vida_atual + 3 > maxvida) {
    vida_atual = maxvida; // verificar se não vai curar a mais do max de vida do heroi
    } else {
    vida_atual += 3;
    }
    if (vida_atual != maxvida)
    cout << RED << "3 pontos de vida recuperados!" << RESET << endl;
}

void Heroi::EquiparArma(Elemento arma){
    armaatual = arma;
    dano_atual = arma.dano;
}

Mochila& Heroi::AcessarMochila(){
    return mochilaHeroi;
}

void Heroi::MenuMochila(Heroi &player){ // metodo para acessar menu da mochila do heroi
    if (mochilaHeroi.MochilaEmpty()){ // verificar se a mochila ta vazia
        cout << RED << "\nSua mochila esta vazia!! XD" << RESET << endl;
        return;
    }
    Elemento itemtemp; // item temporario
    mochilaHeroi.MochilaTop(itemtemp); // passa o topo da mochila para o item temporario
    cout << RED << "\nItem no topo da mochila: " << RESET;
    if (itemtemp.tipo == 'A') { // imprime o item que esta no topo
        cout << RESET << "Arma: " << RED << itemtemp.nome << RESET << ", Dano: " << RED << itemtemp.dano << "\n"; 
    } else {
        cout << "Pocao: " << itemtemp.nome << ", Cura: " << itemtemp.cura << "\n";
    }
    char op;
    do{
        cout << RED << "-" << RESET << " O que deseja fazer?" << endl;
        cout << RED << "[1] -" << RESET << " Utilizar item" << endl;
        cout << RED << "[2] -" << RESET << " Descartar item (Nao podera recupera-lo depois)" << endl;
        cout << RED << "[3] -" << RESET << " Sair da mochila" << endl;
        cout << RED << "----> ";
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer

        // verificando se o player digitou uma opção valida
        if (op != '1' && op != '2' && op != '3') { //diferente de 1,2,3
            cout << RED << "\nOpcao invalida! Tente novamente." << RESET << endl;
        }
    } while (op != '1' && op != '2' && op != '3');

    cout << RED << "\n----------------------------------------------------\n";

    if (op == '1') { // utilizar item
        if (itemtemp.tipo == 'A') { // se for arma
            // equipar arma
            cout << RESET << "\nVoce equipou a arma " << RED << itemtemp.nome << ", que da " << RED << itemtemp.dano << RESET << " de dano." << endl;
            mochilaHeroi.MochilaPop(itemtemp); // tira da mochila pois foi para a mao do player
            player.EquiparArma(itemtemp); // equipa a arma na mao do player
        } else { // se for pocao o topo da mochila
            // pocao de cura
            mochilaHeroi.MochilaPop(itemtemp); // tira da mochila pois o player tomou
            player.TomarPocao(itemtemp); // vai curar o heroi
        }
    } else if (op == '2') { // descartar item
        cout << "Voce descartou o item " << itemtemp.nome << "!" << endl;
        mochilaHeroi.MochilaPop(itemtemp); // descartar item
    } else {
        return;
    }
}

Cinto& Heroi::AcessarCinto(){
    return cintoHeroi;
}

void Heroi::MenuCinto(Heroi &player) {
    // método responsável por permitir que o usuário acesse o cinto

    // Exibe todos os itens no cinto
    cintoHeroi.RetornaTodosItens();
    if (cintoHeroi.CintoVazio()) { // verificar se o cinto esta vazio
        return;
    }
    
    char op; // Variável para armazenar a opção do usuário
    if (!cintoHeroi.CintoVazio()){
        while (true) {
        cout << RED << "-" << RESET << " Deseja utilizar algum item do cinto?" << RED << " [S/N]" << endl;
        cout << RED << "----> ";
        cin >> op;
        cout << RED << "\n----------------------------------------------------\n";
        if (op == 'S' || op == 's') {
            int p; // Para armazenar a posição do item escolhido
            cout << RED << "-" << RESET << " Escolha um item do cinto " << RED << "[1 a " << cintoHeroi.TamanhoCinto() << "]" << RESET << " : ";
            cin >> p;
            // Validação da entrada
            while (p < 1 || p > cintoHeroi.TamanhoCinto()) {
                cout << "Posicao invalida! Tente novamente: ";
                cout << "----> ";
                cin >> p;
            }
            Elemento x; // variável responsável por armazenar o item escolhido pelo usuário
            cintoHeroi.RetornaItem(x, p); 
            cout << "Voce pegou o item: " << x.nome << endl; 
            if(x.tipo == 'P'){
                // pocao de cura
                cintoHeroi.DeletarItem(x, p); // tira da mochila pois o player tomou
                player.TomarPocao(x); // vai curar o heroi
            }
            else {
                 // equipar arma
                cout << RESET << "\nVoce equipou a arma " << RED << x.nome << ", que da " << RED << x.dano << RESET << " de dano." << endl;
                cintoHeroi.DeletarItem(x, p); // tira da mochila pois foi para a mao do player
                player.EquiparArma(x); // equipa a arma na mao do player
                cout << "O heroi pegou " <<  x.nome << "." << endl;
            }
            break; 
        }
        if (op == 'N' || op == 'n') {
            cout << "Voce nao pegou nada do cinto!" << endl;
            break;
        } else {
            cout << "Tecla nao permitida! Selecione S ou N!" << endl; 
        }
    }
    }
}


#endif