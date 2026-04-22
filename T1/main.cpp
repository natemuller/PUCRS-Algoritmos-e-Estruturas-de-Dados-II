#include <iostream>
#include <fstream>
#include <chrono>
#include "inflator.h"
#include "files.h"

using namespace std;

int main() {
    Files files;
    Inflator inflator;

    files.setNomeArquivo("casos de teste/caso-10");
    ifstream arquivo = files.abrirArquivo();
    if (!arquivo.is_open()) {
        return 1;
    }

    inflator.carregarArquivo(arquivo);

    auto inicio = std::chrono::high_resolution_clock::now();

    cout << inflator.calculaTamFinal() << endl;

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    cout << "tempo de execucao: " << duracao.count() << " ms" << endl;

    arquivo.close();
    return 0;
}


/*
Explicação para auxiliar no artigo final:
    Inicialmente, a main apenas cria uma instância de Files e uma de Inflator.
    Em seguida, definte o nome do arquivo e abre-o.
    Carrega o arquivo e exibe o tamanho final da string já inflada.
*/