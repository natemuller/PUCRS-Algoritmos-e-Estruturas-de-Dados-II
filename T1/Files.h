#ifndef FILES_H
#define FILES_H
#include <string>
#include "inflator.h"

using namespace std;

class Files {
    private:
        string nomeArquivo;

    public:
        Files();
        ~Files();

        void setNomeArquivo(const string& nome);

        bool lerArquivo(Inflator& inflator);
};

#endif