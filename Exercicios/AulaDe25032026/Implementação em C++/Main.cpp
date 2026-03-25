#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TabelaHash.h"

using namespace std;

int main() {
    int capacidade = 10;
    int quantidadeInsercoes = 25;
    TabelaHash hash(capacidade);

    srand(time(nullptr));

    cout << "--- Inserindo " << quantidadeInsercoes << " valores aleatorios ---\n";

    for (int i = 0; i < quantidadeInsercoes; i++) {
        int valor = rand() % 100; // gera valores entre 0 e 99
        cout << valor << " ";
        hash.put(valor);
    }

    cout << "\n\n--- Estado Atual da Tabela Hash ---\n";
    hash.printTable();

    int valorBusca = 50;
    cout << "\n--- Testes de Busca ---\n";
    cout << "Contem o valor " << valorBusca << "? "
              << (hash.contains(valorBusca) ? "true" : "false") << "\n";

    cout << "\n--- Teste de Remocao ---\n";
    cout << "Limpando os indices (se existirem)...\n";

    for (int i = 0; i < 5; i++) {
        int alvo = rand() % 100;
        if (hash.contains(alvo)) {
            cout << "Removendo: " << alvo << "\n";
            hash.remove(alvo);
        }
    }

    cout << "\n--- Estado Final da Tabela ---\n";
    hash.printTable();

    return 0;
}