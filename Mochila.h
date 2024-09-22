// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

#include "Elemento.h"

class Mochila{
    public:
        Mochila();
        ~Mochila();
        void MochilaPush(Elemento x);
        void MochilaPop(Elemento &x);
        bool MochilaFull ();
        bool MochilaEmpty ();
        void MochilaClear();
        void MochilaTop(Elemento &x);
        int MochilaSize();
        Elemento AcessarItem(int index);
        void RemoveItem(int index);
    
    private:
    //Mochila não tem tamnho
        struct SlotMochila{
                Elemento Item;
                SlotMochila *ProximoItem; // equivalente ao NextNode
            };
            typedef SlotMochila *PonteiroMochila;

        PonteiroMochila topo; // mostra o item do topo
        int quantidade; // quantidade de itens na mochila, para teste
};