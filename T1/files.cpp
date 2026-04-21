#include "files.h"
#include <iostream>
#include <fstream>

using namespace std;

Files::Files() {
    nomeArquivo = "";
}

Files::~Files() {}

void Files::setNomeArquivo(const string & nome) {
    nomeArquivo = nome;
}

ifstream Files::abrirArquivo() {
    if (nomeArquivo.empty()) {
        cout << "nome do arquivo nao definido\n";
        return ifstream();
    }
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "erro ao abrir " << nomeArquivo << endl;
    }
    return arquivo;
}
