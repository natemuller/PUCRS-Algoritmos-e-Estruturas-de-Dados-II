#ifndef INFLATOR_H
#define INFLATOR_H

// responsabilidade:
// - receber os dados já lidos
// - descobrir a letra inicial
// - calcular o tamanho final
// - devolver o resultado pro main
using namespace std;

class Inflator {
    private:
        struct Node {
            int key;
            Node* next;
            Node(int key) : key(key), next(nullptr) {}
        };

        Node** table;
        int capacity;
        int size;
        
    public:
        Inflator();
        ~Inflator();

};


#endif