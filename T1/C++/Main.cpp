#include <iostream>
#include <fstream>
#include "inflator.h"
#include "files.h"

using namespace std;

int main() {
    Files files;
    Inflator inflator;

    files.setNomeArquivo("entrada.txt");
    ifstream arquivo = files.abrirArquivo();

    if (!arquivo.is_open()) {
        return 1;
    }

    if (!inflator.carregarRegras(arquivo)) {
        return 1;
    }
    string resposta = inflator.inflar();
    long long tamanhoStringGerada = resposta.size();
    cout << tamanhoStringGerada << "\n" << endl;
}
