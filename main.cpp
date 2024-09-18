// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040"

#include <iostream>
#include <string>
#include <random>
#include <cstdlib> // abort
#include "Heroi.h"
#include "Elemento.h"
using namespace std;


// VARIAVEIS
const int larguradisplay = 52;
const int tamanho_mapa = 15;
const int num_niveis = 2;
const string RED = "\033[1;31m";
const string RESET = "\033[0m";

// ANUNCIAR EVENTO
static const string frasesInimigo[5] = { // frases quando encontrar um inimigo
    "Voce encontrou um inimigo feroz!",
    "Um inimigo apareceu magicamente!",
    "Cuidado! Um inimigo esta a espreita!",
    "Um inimigo bloqueia seu caminho!",
    "A sombra de um inimigo surge na sua frente!"
};
static const string frasesNada[5] = { // frases quando n encontrar nada
    "O caminho esta vazio.",
    "Voce nao encontrou nada de interessante.",
    "Nada a vista. Continue explorando.",
    "Parece que nao ha nada aqui.",
    "Tudo quieto. Pode tomar um ar."
};
static const string frasesTesouro[5] = { // frases quando encontrar elemento
    "Voce encontrou um bau de tesouro!",
    "Parabens! Um tesouro esta a sua frente!",
    "Tesouro descoberto! O que sera que tem dentro?",
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

// GERADOR NUMEROS RANDOM
random_device rd;
mt19937 gen(rd());

// FUNÇÕES
void Logo();
void Centralizar(int largura, string text);
void Display(int &nivelatual, int &sqmatual, Heroi player);
void SortearEvento(short int &tipo);
void AnunciarEvento(short int tipo);


// g++ main.cpp Heroi.cpp Elemento.cpp Mochila.cpp -o jogo.exe  <=== COMPILAR
// g++ -std=c++11 main.cpp Heroi.cpp Elemento.cpp Mochila.cpp -o jogo.exe

// .\jogo.exe                <=== RODAR

int main(){

    int nivelatual = 1;
    int sqmatual = 1;
    bool fim = false;

    Heroi player;

    Logo();
    Centralizar(larguradisplay,"PRESSIONE 'ENTER' PARA INICIAR...");
    char next = cin.get(); // enter para avançar
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << " - Nome do seu heroi -----> " << RESET;
    string n;
    getline(cin, n);
    player.DefinirNome(n);
    
    // LOOP PRINCIPAL DO JOGO
    while(!fim){
        //Display
        Display(nivelatual, sqmatual, player); // func q mostra nivel, vida, nome, progresso
        
        // Iniciar Round
        short int tipoevento; // variavel pra setar o q vai ser no nivel
        SortearEvento(tipoevento); // funcao pra gerar aleatorimente o q vai ser
        AnunciarEvento(tipoevento); // imprimir pro player o que e
        
        Elemento item_temp;

        // Switch entre batalha, vazio e elemento
        switch (tipoevento) {
            case 1: {
                // IMPLEMENTAR BATALHA
                player.TomarDano(5); // teste
                break;
            }
            case 2: {
                // IMPLEMENTAR VAZIO
                break;
            }
            case 3: {
                int tipo_elemento;
                uniform_int_distribution<> distr(1, 2);
                tipo_elemento = distr(gen);
                if (tipo_elemento == 1) {
                    criarArma(item_temp, nivelatual, num_niveis);
                    cout << "Arma encontrada: " << item_temp.nome << ", Dano: " << item_temp.dano << "\n";
                } else {
                    criarPocao(item_temp, nivelatual, num_niveis);
                    cout << "Pocao encontrada: " << item_temp.nome << ", Cura: " << item_temp.cura << "\n";
                    player.TomarPocao(item_temp.cura);
                }
                break;
            }
            default: {
                break;
            }
        }

        cout << "\n" << RED;
        Centralizar(larguradisplay,"PRESSIONE 'ENTER' PARA AVANCAR...");
        next = cin.get();
        
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
    cout << "\n\n";

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
    cout << RED << "\n\n\n\n\n\n\n\n----------------------------------------------------\n";
    Centralizar(larguradisplay, "-= DUNGEONS & PELLISSONS =-");
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "NIVEL: " << RESET << nivelatual << RED << " | " << nomesniveis[nivelatual-1] << " | PROGRESSO: " << RESET << sqmatual << "/" << tamanho_mapa << endl;
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "HEROI: " << RESET << player.Nome() << RED << " | HP: " << RESET << player.RetornarHP() << "/100" << endl;
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

    // recebe qual o tipo de evento e imprime uma frase random do vetor
    switch (evento)
        {
        case 1:
            cout << frasesInimigo[random] << endl;;
            break;
        case 2:
            cout << frasesNada[random] << endl;;
            break;
        case 3:
            cout << frasesTesouro[random] << endl;;
            break;
        default:
            break;
        }
}