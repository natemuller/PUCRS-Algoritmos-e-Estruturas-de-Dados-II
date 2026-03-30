#ifndef INFLATOR_H
#define INFLATOR_H

// responsabilidade:
// - receber os dados já lidos
// - descobrir a letra inicial
// - calcular o tamanho final
// - devolver o resultado pro main
using namespace std;

class Inflator {
    private:
        string regras[26];
        bool temRegra[26];
        bool apareceDireita[26];

        long long memo[26];
        bool calculado[26];
        int estado[26];

        int inicial;

        int charParaIndice(char c);
        char indiceParaChar(int i);
        
        long long calcularTamanhoIndice(int idx);

    public:
        Inflator();
        ~Inflator();

        void adicionarRegra(char letra, const string& expansao);

        void descobrirLetraInicial();
        long long calcularTamanhoLetra(char letra);
        long long calcularTamanhoFinal();

        char getLetraInicial();
};


#endif