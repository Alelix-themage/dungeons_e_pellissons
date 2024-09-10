// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040"

#include <iostream>
#include <string>
#include <random>
#include "Heroi.h"
#include "Pocao.h"
using namespace std;


// VARIAVEIS
const int larguradisplay = 52;
const int tamanho_mapa = 15;
const int num_niveis = 2;
const string RED = "\033[1;31m";
const string RESET = "\033[0m";

// ANUNCIAR EVETNO
static const string frasesInimigo[5] = {
    "Voce encontrou um inimigo feroz!",
    "Um inimigo apareceu magicamente!",
    "Cuidado! Um inimigo esta a espreita!",
    "Um inimigo bloqueia seu caminho!",
    "A sombra de um inimigo surge na sua frente!"
};
static const string frasesNada[5] = {
    "O caminho esta vazio.",
    "Você nao encontrou nada de interessante.",
    "Nada a vista. Continue explorando.",
    "Parece que nao ha nada aqui.",
    "Tudo quieto. Pode tomar um ar."
};
static const string frasesTesouro[5] = {
    "Você encontrou um bau de tesouro!",
    "Parabens! Um tesouro esta a sua frente!",
    "Tesouro descoberto! O que será que tem dentro?",
    "Um brilho dourado revela um tesouro escondido!",
    "Incrivel! Um tesouro misterioso!"
};

// NOMES NIVEIS
const string nomesniveis[5] = {
    "Estrada da Main", 
    "Floresta Binaria", 
    "Montanha Pilha de Neve", 
    "Vulcao Recursivo", 
    "Fortaleza dos Dados"
};

// GERADOR NUMEROS RADNOM
random_device rd;
mt19937 gen(rd());

// FUNÇÕES
void Logo();
void Centralizar(int largura, string text);
void Display(int &nivelatual, int &sqmatual, Heroi player);
void SortearEvento(short int &tipo);
void AnunciarEvento(short int tipo);


// g++ main.cpp Heroi.cpp Pocao.cpp -o jogo.exe  <=== COMPILAR
// g++ -std=c++11 main.cpp Heroi.cpp Pocao.cpp -o jogo.exe

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
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << " - Nome do seu heroi -----> " << RESET;
    string n;
    getline(cin, n);
    player.DefinirNome(n);
    

    while(!fim){
        //Display
        Display(nivelatual, sqmatual, player);
        
        // Iniciar Round
        short int tipoevento;
        SortearEvento(tipoevento);
        AnunciarEvento(tipoevento);
        start = cin.get();

        // Switch entre batalha, vazio e elemento
        switch (tipoevento)
        {
        case 1:
            // BATALHA

            break;
        case 2:
            // VAZIO

            break;
        case 3:
            // ELEMENTO

            break;
        default:
            break;
        }

        
        // Finalizar "Round"
        if (nivelatual == num_niveis && sqmatual == tamanho_mapa){
            fim = true;
        }
        if (sqmatual == tamanho_mapa){
            nivelatual++;
            sqmatual = 1;
        } else {
            sqmatual++;
        }
    }

    // FIM DO JOGO
    cout << "\n\n" << RED;
    Centralizar(larguradisplay, "FIM DO JOGO");
    Logo();
    

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
}

void Display(int &nivelatual, int &sqmatual, Heroi player){
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "NIVEL: " << RESET << nivelatual << RED << " | " << nomesniveis[nivelatual-1] << " | PROGRESSO: " << RESET << sqmatual << "/" << tamanho_mapa << endl;
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "HEROI: " << RESET << player.Nome() << RED << " | HP: " << RESET << player.RetornarHP() << endl;
    cout << RED << "----------------------------------------------------\n\n" << RESET;
}

void Centralizar(int largura, string texto){
    int espacoesquerda = (largura - texto.length()) / 2;

    for(int i = 0; i < espacoesquerda; i++) {
        cout << " ";
    }

    cout << texto << endl;
}

void SortearEvento(short int &tipo){
    uniform_int_distribution<> distr(1, 3);
    tipo = distr(gen);
}

void AnunciarEvento(short int evento){
    uniform_int_distribution<> distr(0, 4);
    int random = distr(gen);

    switch (evento)
        {
        case 1:
            cout << RED << frasesInimigo[random] << endl;;
            break;
        case 2:
            cout << RED << frasesNada[random] << endl;;
            break;
        case 3:
            cout << RED << frasesTesouro[random] << endl;;
            break;
        default:
            break;
        }
}