#include <iostream>
#include <string>
using namespace std;

const int larguradisplay = 50;

void Logo();
void Centralizar(int largura, string text);

int main(){
    // formatação
    const string RED = "\033[31m";
    const string BOLDRED = "\033[31m";
    const string GREEN = "\033[32m";
    const string BLUE = "\033[34m";
    const string RESET = "\033[0m";
    

    Logo();

    return 0;
}

void Logo(){
    const string RED = "\033[1;31m";
    const string RESET = "\033[0m";

    cout << RED << "--------------------------------------------------\n";
    cout << "                          ,    ,    /\\   /\\\n";
    cout << "     ____                /( /\\ )\\  _\\ \\_/ /_\n";
    cout << "    /\\' .\\    _____      |\\_||_/| < \\_   _/ >\n";
    cout << "   /: \\___\\  / .  /\\     \\______/ \\| 0   0 |/\n";
    cout << "   \\' / . / /____/..\\      _\\/__  _(_  ^  _)_\n";
    cout << "    \\/___/  \\'  '\\  /     ( () ) /`\\|V\"\"\"V|/`\\\n";
    cout << "             \\'__'\\/        {}   \\  \\_____\\/  /\n";
    cout << "                            ()   /\\   )=(   /\\\n";
    cout << "                            {}  /  \\_/\\=/\\_/  \\\n";
    cout << "--------------------------------------------------\n";
    Centralizar(larguradisplay, "-= DUNGEONS & PELLISSONS =-");
    cout << "--------------------------------------------------" << RESET << endl;;
}

void Centralizar(int largura, string texto){
    int espacoesquerda = (largura - texto.length()) / 2;

    for(int i = 0; i < espacoesquerda; i++) {
        cout << " ";
    }

    cout << texto << endl;
}
