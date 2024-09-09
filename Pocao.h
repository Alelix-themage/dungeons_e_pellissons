//Classe responsável pelas funcionalidades da poção

class Pocao {
    public:
        Pocao();
        ~Pocao();
        int RetornarCura();
    private:
        int cura = 10;
};