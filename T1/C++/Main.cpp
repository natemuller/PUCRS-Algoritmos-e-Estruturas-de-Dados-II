#include <iostream>
#include <fstream>
#include "inflator.h"
#include "files.h"

using namespace std;

int main() {
    Inflator inflator;
    Files files;

    files.setNomeArquivo("entrada.txt");

    if (!files.lerArquivo(inflator)) {
        cout << "Erro" << endl;
        return 1;
    }

    inflator.descobrirLetraInicial();

    cout << inflator.getLetraInicial() << endl;
    cout << inflator.calcularTamanhoFinal() << endl;

    return 0;
}
