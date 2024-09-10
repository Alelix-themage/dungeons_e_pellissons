//Classe responsável pelas funcionalidades da poção

class Pocao {
    public:
        Pocao();
        ~Pocao();
        void CriarPocao(int dificuldade); // parametro dificuldade, quanto maior o nivel, melhor as pocoes
        int Curar();
    private:
        int cura;
};