class Mochila{
    
    public:
        Mochila();
        ~Mochila();
        int mochila;
        void Push(int x);
        void Pop(int &x);
        bool Full ();
        bool Empty ();
    


    private: //alek bocó 
    // amor, to morrendo de saudade de voce

    int *itens; // ponteiro para mostrar itens da mochila
    int topo; // mostra o item do topo
    int capacidade; // capacidade maxima da mochila
};