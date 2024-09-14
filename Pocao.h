// INTEGRANTES:
// Alessandro Luis Pinheiro da Rocha Junior - 223087
// Felipe Ferreira Rangel de Almeida - 2208490
// Mateus Tiraboschi de Castro - 2200040

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