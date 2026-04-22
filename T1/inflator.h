#ifndef INFLATOR_H
#define INFLATOR_H

#include <string>
#include <fstream>

using namespace std;

class Inflator {
    private:
        #define M 31 

        struct Node {
            char key;
            string val;
            Node* next;
        };

        Node* table[M];
        char inicial;

        unsigned long long chamadasInflar; //remover depois

        int hash(char key);

        void put(char key, string val);
        string get(char key);
        unsigned long long inflar(char c);

    public:
        Inflator();
        ~Inflator();

        void carregarArquivo(ifstream& arquivo);
        unsigned long long calculaTamFinal();
};

#endif