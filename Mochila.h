class Mochila{
    
    public:
        Mochila();
        ~Mochila();
        void MochilaPush(int x);
        void MochilaPop(int &x);
        bool MochilaFull ();
        bool MochilaEmpty ();
    


    private:
    //Mochila não tem tamnho
    

    int *itens; // ponteiro para mostrar itens da mochila
    int topo; // mostra o item do topo
    int capacidade; // capacidade maxima da mochila
};