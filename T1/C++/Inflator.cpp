#include "inflator.h"
#include <iostream>

// responsabilidade:
// - chama files pra abrir o arquivo
// - descobrir a letra inicial
// - calcular o tamanho final
// - devolver o resultado pro main
//As trocas são feitas referentes a string da PRIMEIRA linha apenas, as outras linhas são auxiliares e não serão necessariamente utilizadas.

Inflator::Inflator() {
    quantidadeRegras = 0;
    simboloInicial = '\0';
    sequenciaInicial = "";
    inicializarRegras();
}

Inflator::~Inflator() {}

bool Inflator::carregarRegras(ifstream &arquivo) {
    if (!arquivo.is_open()) {
        cout << "arquivo nao esta aberto\n";
        return false;
    }
    string linha;
    bool primeiraLinha = true;

    while (getline(arquivo, linha)) {
        if (linha.empty()) {
            continue;
        }
        char letra = linha[0];

        if (!letraValida(letra)) {
            cout << "invalida: " << letra << endl;
            continue;
        }
        string sequencia = "";

        if (linha.size() > 2) {
            sequencia = linha.substr(2);
        }
        adicionarRegra(letra, sequencia);

        if (primeiraLinha) {
            simboloInicial = letra;
            sequenciaInicial = sequencia;
            primeiraLinha = false;
        }
    }

    return true;
}

string Inflator::inflar() {
    string atual = sequenciaInicial;

    while (possuiExpansao(atual)) {
        atual = expandirUmaVez(atual);
    }
    return atual;
}

int Inflator::indiceDaLetra(char c) const {
    return c - 'a';
}

bool Inflator::letraValida(char c) const {
    return (c >= 'a' && c <= 'z');
}

void Inflator::inicializarRegras() {
    for (int i = 0; i < ALFABETO; i++) {
        regras[i].letra = 'a' + i;
        regras[i].sequencia = "";
    }
}

void Inflator::adicionarRegra(char letra, const string &sequencia) {
    int indice = indiceDaLetra(letra);
    regras[indice].letra = letra;
    regras[indice].sequencia = sequencia;
    quantidadeRegras++;
}

string Inflator::buscarSequencia(char letra) const {
    if (!letraValida(letra)) {
        return "";
    }
    int indice = indiceDaLetra(letra);
    return regras[indice].sequencia;
}

bool Inflator::possuiExpansao(const string &texto) const {
    for (char c : texto) {
        if (!letraValida(c)) {
            continue;
        }
        int indice = indiceDaLetra(c);

        if (!regras[indice].sequencia.empty()) {
            return true;
        }
    }
    return false;
}

string Inflator::expandirUmaVez(const string &texto) const {
    string resultado = "";

    for (char c : texto) {
        if (!letraValida(c)) {
            continue;
        }
        string seq = buscarSequencia(c);

        if (!seq.empty()) {
            resultado += seq;
        } 

        else {
            resultado += c;
        }
    }
    return resultado;
}
