#include <iostream>

//Classe responsável pelo cinto do Heroi

const int MAX_CINTO = 10;

class Cinto{
    public:
        Cinto();
        ~Cinto();
        bool CintoVazio();
        bool CintoCheio();
        void InserirItem(int x, int p); // x é o elemento, e p é o índice (posição)
        void DeletarItem(int &x, int p);
        int TamanhoCinto();
        void LimparCinto();
        void RetornaItem(int &x, int p);
        void SubstituiItem(int x, int p);

        private:
            int Entry[MAX_CINTO + 1];
            int count;

};