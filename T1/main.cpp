#include <iostream>
#include <fstream>
#include "inflator.h"
#include "files.h"

using namespace std;

int main() {
    Files files;
    Inflator inflator;

    files.setNomeArquivo("casos de teste/caso-12");
    ifstream arquivo = files.abrirArquivo();
    if (!arquivo.is_open()) {
        return 1;
    }

    inflator.carregarArquivo(arquivo);

    cout << inflator.calculaTamFinal() << endl;

    arquivo.close();
    return 0;
}


/*
Explicação para auxiliar no artigo final:
    Inicialmente, a main apenas cria uma instância de Files e uma de Inflator.
    Em seguida, definte o nome do arquivo e abre-o.
    Carrega o arquivo e exibe o tamanho final da string já inflada.
*/