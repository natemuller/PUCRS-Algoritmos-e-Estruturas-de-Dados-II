#include "inflator.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Inflator::Inflator() {
    for (int i = 0; i < M; i++) {
        table[i] = nullptr;
    }
    inicial = '\0';
}

Inflator::~Inflator() {
    for (int i = 0; i < M; i++) {
        Node* atual = table[i];

        while (atual != nullptr) {
            Node* prox = atual->next;
            delete atual;
            atual = prox;
        }
        table[i] = nullptr;
    }
}

int Inflator::hash(char key) {
    return (unsigned char) key % M;
}

void Inflator::put(char key, string val) {
    int i = hash(key);

    Node* x = table[i];
    while (x != nullptr) {
        if (x->key == key) {
            x->val = val;
            return;
        }
        x = x->next;
    }
    Node* novo = new Node{key, val, table[i]};
    table[i] = novo;
}

string Inflator::get(char key) {
    int i = hash(key);

    Node* x = table[i];
    while (x != nullptr) {
        if (x->key == key) {
            return x->val;
        }
        x = x->next;
    }

    return "";
}

void Inflator::carregarArquivo(ifstream& arquivo) {
    string linha;

    bool ehChave[256] = {false};
    bool apareceNoValor[256] = {false};

    while (getline(arquivo, linha)) {
        if (linha.empty()) {
            continue;
        }

        char chave = linha[0];
        ehChave[(unsigned char)chave] = true;

        string valor = "";
        if (linha.size() > 2) {
            valor = linha.substr(2);
        }

        for (char c : valor) {
            apareceNoValor[(unsigned char)c] = true;
        }

        put(chave, valor);
    }
    
    for (int i = 0; i < 256; i++) {
        if (ehChave[i] && !apareceNoValor[i]) {
            inicial = (char)i;
            break;
        }
    }
}

unsigned long long Inflator::inflar(char c) {
    string valor = get(c);

    if (valor == "") {
        return 1;
    }

    unsigned long long soma = 0;

    for (char ch : valor) {
        soma += inflar(ch);
    }
    return soma;
}

unsigned long long Inflator::calculaTamFinal() {
        if (inicial == '\0') {
        cout << "letra inicial nao encontrada\n";
        return 0;
    }
     return inflar(inicial);
}