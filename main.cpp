// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040"

#include <iostream>
#include <string>
#include "Heroi.h"
#include "Pocao.h"
using namespace std;

const int larguradisplay = 52;
const int tamanho_mapa = 15;
const int num_niveis = 5;
const string nomesniveis[num_niveis] = {"Estrada da Main", "Floresta Binaria", "Montanha Pilha de Neve", "Vulcao Recursivo", "Fortaleza dos Dados"}; // nomes de exemplo
const string RED = "\033[1;31m";
const string RESET = "\033[0m";

void Logo();
void Centralizar(int largura, string text);
void display(int &nivelatual, int &sqmatual, Heroi player);

// g++ main.cpp Heroi.cpp Pocao.cpp -o jogo.exe  <=== COMPILAR
// g++ -std=c++11 Heroi.cpp main.cpp -o jogo.exe

// .\jogo.exe                <=== RODAR

int main(){

    char start;
    int nivelatual = 1;
    int sqmatual = 1;
    bool fim = false;

    Heroi player;

    Logo();
    Centralizar(larguradisplay,"PRESSIONE QUALQUER TECLA PARA INICIAR...");
    start = cin.get();
    cout << "----------------------------------------------------\n" << RESET;
    cout << RED << " - Nome do seu heroi -----> " << RESET;
    string n;
    getline(cin, n);
    player.DefinirNome(n);
    cout << RED << "----------------------------------------------------\n" << RESET;

    while(!fim){
        //Displayy Caraiii
        display(nivelatual, sqmatual, player);
        Pocao p1;

        player.TomarPocao(p1.RetornarCura());

        // Finalizar "Round"
        if (sqmatual == tamanho_mapa){
            nivelatual++;
            sqmatual = 1;
        } else {
            sqmatual++;
        }
        if (nivelatual == num_niveis && sqmatual == tamanho_mapa){
            fim = true;
        }
    }
    cout << "FIM";

    return 0;
}

void Logo(){
    

    cout << RED << "----------------------------------------------------\n";
    cout << "                           ,    ,    /\\   /\\\n";
    cout << "      ____                /( /\\ )\\  _\\ \\_/ /_\n";
    cout << "     /\\' .\\    _____      |\\_||_/| < \\_   _/ >\n";
    cout << "    /: \\___\\  / .  /\\     \\______/ \\| 0   0 |/\n";
    cout << "    \\' / . / /____/..\\      _\\/__  _(_  ^  _)_\n";
    cout << "     \\/___/  \\'  '\\  /     ( () ) /`\\|V\"\"\"V|/`\\\n";
    cout << "              \\'__'\\/        {}   \\  \\_____\\/  /\n";
    cout << "                             ()   /\\   )=(   /\\\n";
    cout << "                             {}  /  \\_/\\=/\\_/  \\\n";
    cout << "----------------------------------------------------\n";
    Centralizar(larguradisplay, "-= DUNGEONS & PELLISSONS =-");
    cout << "--------------------------------------------------"  << endl;;
}

void display(int &nivelatual, int &sqmatual, Heroi player){
    cout << RED << "NIVEL: " << RESET << nivelatual << RED << " | " << nomesniveis[nivelatual-1] << " | PROGRESSO: " << RESET << sqmatual << "/" << tamanho_mapa << endl;
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "HEROI: " << RESET << player.Nome() << RED << " | HP: " << player.RetornarHP() << endl;
    cout << RED << "----------------------------------------------------\n\n" << RESET;
}

void Centralizar(int largura, string texto){
    int espacoesquerda = (largura - texto.length()) / 2;

    for(int i = 0; i < espacoesquerda; i++) {
        cout << " ";
    }

    cout << texto << endl;
}
