#ifndef TABELAHASH_H
#define TABELAHASH_H

class TabelaHash {
private:
    struct Node {
        int key;
        Node* next;

        Node(int key) : key(key), next(nullptr) {}
    };

    Node** table;
    int capacity;

    int hash(int key);

public:
    TabelaHash(int capacity);
    ~TabelaHash();

    void put(int key);
    bool contains(int key);
    void remove(int key);
    void printTable();
    void heHash();
};

#endif