#ifndef INFLATOR_H
#define INFLATOR_H

#include <string>
#include <fstream>

using namespace std;

class Inflator {
private:
    static const int ALFABETO = 26;

    struct Regra {
        char letra;
        string sequencia;
    };

    Regra regras[ALFABETO];
    int quantidadeRegras;

    char simboloInicial;
    string sequenciaInicial;

    int indiceDaLetra(char c) const;
    bool letraValida(char c) const;

    void inicializarRegras();
    void adicionarRegra(char letra, const string& sequencia);
    string buscarSequencia(char letra) const;

    bool possuiExpansao(const string& texto) const;
    string expandirUmaVez(const string& texto) const;

public:
    Inflator();
    ~Inflator();

    bool carregarRegras(ifstream& arquivo);
    string inflar();
};

#endif