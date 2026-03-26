#include <iostream>
#include <cmath>
#include "TabelaHash.h"

using namespace std;

TabelaHash::TabelaHash(int capacity) {
    this->capacity = capacity;
    table = new Node*[capacity];

    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

TabelaHash::~TabelaHash() {
    for (int i = 0; i < capacity; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

int TabelaHash::hash(int key) {
    return abs(key) % capacity;
}

void TabelaHash::put(int key) {
    int index = hash(key);
    // TODO: Implementar inserção no início da lista (ou verificar se já existe)
    Node* current = table[index];
    
    while (current != nullptr) {
        if (current->key == key) {
            return;
        }
        current = current->next;
    }
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
}

bool TabelaHash::contains(int key) {
    int index = hash(key);
    // TODO: Implementar busca na lista encadeada do índice
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void TabelaHash::remove(int key) {
    int index = hash(key);
    // TODO: Implementar remoção na lista encadeada
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if(prev == nullptr) {
                table[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void TabelaHash::printTable() {
    for (int i = 0; i < capacity; i++) {
        cout << "[" << i << "]: ";
        Node* current = table[i];

        while (current != nullptr) {
            cout << current->key << " -> ";
            current = current->next;
        }

        cout << "nullptr" << endl;
    }
}

void TabelaHash::heHash() {
    int oldCapacity = capacity;
    int newCapacity = capacity * 2 + 1;
    Node** newTabelaHash = new Node*[newCapacity]();

    for (int i = 0; i < oldCapacity; ++i)
    {
        Node *n = TabelaHash[i];
        while (n != nullptr) {
            Node *temp = n;
            n = n->next;

            Node*& bucket = newTabelaHash[default_hash_function(temp->key) % capacity];
            temp->next = bucket;
            bucket = temp;
        }
    }
    delete [] TabelaHash;
    TabelaHash = newTabelaHash;
}