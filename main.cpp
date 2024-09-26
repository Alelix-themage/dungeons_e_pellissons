// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040"

#include <iostream>
#include <chrono> // tempo atual do pc
#include <limits>
#include <string>
#include <random>
#include <cstdlib> // abort
#include "Heroi.h"
#include "Elemento.h"
#include "Monstro.h"
using namespace std;


// VARIAVEIS
const int larguradisplay = 52;
const int tamanho_mapa = 5;
const int num_niveis = 5;
const string RED = "\033[1;31m";
const string RESET = "\033[0m";

// LISTAS COM DADOS
static const string frasesInimigo[5] = { // frases quando encontrar um inimigo
    "Voce encontrou um inimigo feroz...",
    "Um inimigo apareceu magicamente...",
    "Cuidado! Um inimigo esta a espreita...",
    "Um inimigo bloqueia seu caminho...",
    "A sombra de um inimigo surge na sua frente..."
};
static const string frasesNada[5] = { // frases quando n encontrar nada
    "O caminho esta vazio, voce descansa.",
    "Voce nao encontrou nada de interessante,.",
    "Nada a vista. Voce toma uma agua e continua explorando.",
    "Parece que nao ha nada aqui, voce da uma esticada nas pernas.",
    "Tudo quieto. Pode tomar um ar."
};
static const string frasesTesouro[5] = { // frases quando encontrar elemento
    "Voce encontrou um bau de tesouro!",
    "Parabens! Um tesouro esta a sua frente!",
    "Tesouro descoberto! O que sera que tem dentro?",
    "Um brilho dourado revela um tesouro escondido!",
    "Incrivel! Um tesouro misterioso!"
};
const string nomesniveis[5] = {
    "Estrada da Main", 
    "Floresta Binaria", 
    "Montanha Pilha de Neve", 
    "Vulcao Recursivo", 
    "Fortaleza dos Dados"
};

// GERADOR NUMEROS RANDOM
random_device rd;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // gerar numero random a partir do tempo atual

// FUNÇÕES
void Logo();
void Centralizar(int largura, string text);
void Display(int &nivelatual, int &sqmatual, Heroi &player);
void SortearEvento(short int &tipo);
void AnunciarEvento(short int tipo);

// g++ main.cpp Heroi.cpp Elemento.cpp Mochila.cpp Monstro.cpp Cinto.cpp -o jogo.exe  <=== COMPILAR
// g++ -std=c++11 main.cpp Heroi.cpp Elemento.cpp Mochila.cpp Monstro.cpp Cinto.cpp -o jogo.exe

// .\jogo.exe                <=== RODAR

int main(){

    int nivelatual = 1;
    int sqmatual = 1;
    bool fim = false;
    int dano;

    Heroi player;
    Elemento elemento;

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
        

        // Switch entre batalha, vazio e elemento
        switch (tipoevento) {
            case 1: { // BATALHA
                Monstro inimigo(nivelatual, num_niveis); // cria o objeto inimigo
                cout << "Voce encontrou um " << RED << inimigo.Nome() << RESET << "! Prepare-se para a batalha!" << endl;
                cout << RED << '\n';
                Centralizar(larguradisplay,"PRESSIONE 'ENTER' PARA ENTRAR NA BATALHA...");
                char next = cin.get(); // enter para avançar
                cout << RED << "\n----------------------------------------------------\n" << RESET;

                // LOOP DA BATALHA
                bool fimbatalha = false;
                while(!fimbatalha){
                    Display(nivelatual, sqmatual, player); // func q mostra nivel, vida, nome, progresso
                    cout << RED << "INIMIGO: " << RESET << inimigo.Nome() << RED << " | HP: " << RESET << inimigo.RetornarHP() << "/" << inimigo.MaxHP() << endl; // mostrar HP monstro
                    cout << RED << "----------------------------------------------------\n" << RESET;
                    char op;
                    do{
                        cout << RED << "\n-" << RESET << " O que deseja fazer?" << endl;
                        cout << RED << "[1] -" << RESET << " Atacar" << endl;
                        cout << RED << "[2] -" << RESET << " Pegar um item da mochila" << endl;
                        cout << RED << "[3] -" << RESET << " Pegue um item do cinto" << endl;
                        cout << RED << "----> ";
                        cin >> op;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer

                        // verificando se o player digitou uma opção valida
                        if (op != '1' && op != '2' && op != '3') { //diferente de 1,2,3
                            cout << RED << "\nOpcao invalida! Tente novamente." << RESET << endl;
                        }
                    } while (op != '1' && op != '2' && op != '3');
                    cout << RED << "\n----------------------------------------------------\n";
                    switch (op)
                    {
                    case  '1':
                        inimigo.TomarDano(player.RetornarDano());
                        if(inimigo.RetornarHP() <= 0){
                            cout << RED << inimigo.Nome() << " foi derrotado!" << RESET << endl;
                            fimbatalha = true;
                        }
                        break;
                    case  '2':
                        Centralizar(larguradisplay, "MENU MOCHILA");
                        player.MenuMochila(player);
                        break;
                    case '3':
                        Centralizar(larguradisplay, "MENU CINTO");
                        player.MenuCinto(player);
                        break;
                    default:
                        cout << "Opcao invalida!" << endl;
                        continue;
                    }    

                    //Condicional responsável pelo Ataque do Monstro, se o player atacar
                    if (op == '1') {
                        if (inimigo.RetornarHP() > 0) {
                        int danoMonstro = inimigo.Atacar(); //variável responsável por armazenar o dano do monstro
                        player.TomarDano(danoMonstro); 
                        cout << RED << inimigo.Nome() << RESET << " atacou e causou " << RED << danoMonstro << RESET << " de dano!" << endl;
                        }
                        // Verifica se o usuário foi derrotado
                        if (player.RetornarHP() <= 0) {
                            cout << RED << player.Nome() << " foi derrotado em combate." << endl;
                            break; 
                        }
                    }
                    // proximo round da batalha, se alguem tiver morto, ja pula pro prox
                    if (!fimbatalha) {
                        cout << RED << "\n----------------------------------------------------\n";
                        Centralizar(larguradisplay,"\nPRESSIONE 'ENTER' PARA CONTINUAR A BATALHA...");
                        char next = cin.get(); // enter para avançar
                    }
                }
                cout << RED << "----------------------------------------------------\n\n" << RESET;
                break;
            }
            case 2: { // SQM VAZIO
                player.Descansar();
                bool fimdescanso = false;
                while (!fimdescanso){
                    char op;
                    do{
                        cout << RED << "\n-" << RESET << " O que deseja fazer?" << endl;
                        cout << RED << "[1] -" << RESET << " Continuar aventura" << endl;
                        cout << RED << "[2] -" << RESET << " Acessar mochila" << endl;
                        cout << RED << "[3] -" << RESET << " Acessar cinto" << endl;
                        cout << RED << "----> ";
                        cin >> op;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer

                        // verificando se o player digitou uma opção valida
                        if (op != '1' && op != '2' && op != '3') { //diferente de 1,2,3
                            cout << RED << "\nOpcao invalida! Tente novamente." << RESET << endl;
                        }
                    } while (op != '1' && op != '2' && op != '3');
                    cout << RED << "\n----------------------------------------------------\n";
                    switch (op)
                    {
                    case '1':
                        cout << "Voce avança em sua jornada!" << endl;
                        fimdescanso = true;
                        break;
                    case '2':
                        Centralizar(larguradisplay, "MENU MOCHILA");
                        player.MenuMochila(player);
                        break;
                    case '3':
                        Centralizar(larguradisplay, "MENU CINTO");
                        player.MenuCinto(player);
                        break;
                    default:
                        cout << "Opcao invalida!" << endl;
                        continue;
                    }
                }

                break;
            }
            case 3: {
                // caso o tipo gerado for elemento
                // gerar se vai ser poção ou arma aleatoriamente
                int tipo_elemento;
                uniform_int_distribution<> distr(1, 2);
                tipo_elemento = distr(gen);
                Elemento item_temp;


                if (tipo_elemento == 1) { // 1 = Arma 2 = Pocao
                    criarArma(item_temp, nivelatual, num_niveis);
                    cout << "Item encontrado: " << RED << item_temp.nome << RESET << " que da " << RED << item_temp.dano << RESET << " pontos de HP de dano." << endl;
                } else {
                    criarPocao(item_temp, nivelatual, num_niveis);
                    cout << "Item encontrado: " << RED << item_temp.nome << RESET << " que cura " << RED << item_temp.cura << RESET << " pontos de HP." << endl;
                }


                // menu de opçoes
                char op; // variavel da escolha
                do {
                    cout << RED << "\n----------------------------------------------------\n" << RESET;
                    cout << RED << "-" << RESET << " O que deseja fazer com o item encontrado?" << endl;
                    cout << RED << "[1] -" << RESET << " Colocar na Mochila" << endl;
                    cout << RED << "[2] -" << RESET << " Colocar no Cinto" << endl;
                    cout << RED << "[3] -" << RESET << " Descartar" << endl;
                    cout << RED << "----> ";
                    cin >> op;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer

                    // verificando se o player digitou uma opção valida
                    if (op != '1' && op != '2' && op != '3') { //diferente de 1,2,3
                        cout << RED << "\nOpcao invalida! Tente novamente." << RESET << endl;
                    }

                } while (op != '1' && op != '2' && op != '3');
                cout << RED << "\n----------------------------------------------------\n\n" << RESET;
                if (op == '1'){
                    player.AcessarMochila().MochilaPush(item_temp); // adicionar o item na mochila do player
                    cout << RED << item_temp.nome << RESET << " adicionado a mochila!" << endl;
                    // cout << "Itens na mochila: " << player.AcessarMochila().MochilaSize() << endl; <---- TESTE
                } else if (op == '2') {
                    // colocar no cinto
                    // IMPLEMENTAR ESCOLHA POSIÇÃO
                    player.AcessarCinto().InserirItem(item_temp, player.AcessarCinto().TamanhoCinto() + 1); // adicionar o item na mochila do player
                    cout << RED << item_temp.nome << RESET << " adicionado ao cinto" << endl;
                } else {
                    cout << RED << item_temp.nome << RESET << " descartado(a)!" << endl;
                }

                // fim do sqm de item
                break;
            }
        }
        
        // Finalizar "SQM"
        if (nivelatual == num_niveis && sqmatual == tamanho_mapa){ // se acabou, ganhou o jogo
            fim = true;
        }
        if (sqmatual == tamanho_mapa){
            nivelatual++;
            sqmatual = 1;
        } else {
            sqmatual++;
        }
        // Verificador de morte
        if (player.RetornarHP() <= 0){ // se o player morreu, fim do jogo
            fim = true;
        } else {
            cout << "\n" << RED;
            Centralizar(larguradisplay,"PRESSIONE 'ENTER' PARA AVANCAR...");
            next = cin.get();
        }
    }
    // FIM DO JOGO
    cout << "\n\n" << RED;
    if (player.RetornarHP() <= 0){
        Centralizar(larguradisplay, "VOCE MORREU! FIM DO JOGO!");
    } else {
        Centralizar(larguradisplay, "PARABÉNS! FIM DO JOGO");
    }
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

void Display(int &nivelatual, int &sqmatual, Heroi &player){
    cout << RED << "\n\n\n\n\n\n\n\n----------------------------------------------------\n";
    Centralizar(larguradisplay, "-= DUNGEONS & PELLISSONS =-");
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "NIVEL: " << RESET << nivelatual << RED << " | " << nomesniveis[nivelatual-1] << " | PROGRESSO: " << RESET << sqmatual << "/" << tamanho_mapa << endl;
    cout << RED << "----------------------------------------------------\n" << RESET;
    cout << RED << "HEROI: " << RESET << player.Nome() << RED << " | HP: " << RESET << player.RetornarHP() << "/100" << endl;
    cout << RED << "----------------------------------------------------\n" << RESET;
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
    cout << "\n";

    // recebe qual o tipo de evento e imprime uma frase random do vetor
    switch (evento)
        {
        case 1:
            cout << frasesInimigo[random] << endl;;
            break;
        case 2:
            cout << frasesNada[random] << endl;
            break;
        case 3:
            cout << frasesTesouro[random] << endl;;
            break;
        default:
            break;
        }
}