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

    int *itens; // ponteiro para mostrar itens da mochila
    int topo; // mostra o item do topo
    int capacidade; // capacidade maxima da mochila
};