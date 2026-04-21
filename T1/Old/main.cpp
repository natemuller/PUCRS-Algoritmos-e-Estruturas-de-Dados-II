#include <iostream>
#include <fstream>
#include "inflator.h"
#include "files.h"

using namespace std;

int main() {
    Files files;
    Inflator inflator;

    files.setNomeArquivo("caso-13");
    ifstream arquivo = files.abrirArquivo();

    if (!arquivo.is_open()) {
        return 1;
    }

    if (!inflator.carregarRegras(arquivo)) {
        return 1;
    }
    string resposta = inflator.inflar();
    long long tamanhoStringGerada = resposta.size();
    cout << tamanhoStringGerada << "\n" << endl;
}


/*
O programa foi desenvolvido com foco em simplicidade e eficiência, utilizando estruturas de dados diretas para representar as regras de substituição e realizar o processo de expansão de cadeias de caracteres.
A principal estrutura adotada é um array estático de tamanho fixo (26 posições), utilizado para representar um “dicionário” de regras associadas às letras do alfabeto (a a z). Cada posição do array corresponde a uma letra específica, permitindo acesso em tempo constante (O(1)). Esse mapeamento é feito por meio de uma função que converte o caractere em índice numérico, baseada na diferença entre o código ASCII da letra e o caractere 'a'.
Cada elemento do array armazena uma estrutura composta por:

um caractere (char), representando a letra;
uma string (string), representando a sequência associada àquela letra.

Essa abordagem elimina a necessidade de estruturas mais complexas, como tabelas hash dinâmicas ou árvores, mantendo o acesso rápido e a implementação simples, já que o domínio de dados é conhecido e limitado.
Além disso, a estrutura std::string foi utilizada para representar as sequências de caracteres, permitindo manipulação dinâmica do tamanho das cadeias durante o processo de expansão. Essa escolha facilita operações como concatenação e substituição, fundamentais para a lógica do algoritmo.
O processo de expansão é realizado de forma iterativa, utilizando:

uma string auxiliar para armazenar o estado atual da expansão;
um loop que percorre cada caractere da string, substituindo-o conforme as regras definidas.

Durante esse processo, letras que não possuem sequência associada (ou possuem sequência vazia) são tratadas como símbolos terminais, sendo mantidas na string final.
Por fim, a leitura do arquivo de entrada é feita utilizando ifstream, permitindo o processamento sequencial das regras e a construção do dicionário inicial.
Essa combinação de estruturas — array fixo para acesso rápido, strings para manipulação dinâmica e leitura sequencial de arquivo — resulta em uma solução eficiente, de fácil entendimento e adequada ao escopo do problema proposto.

Bem resumido:
    array → rápido e simples
    string → fácil de manipular
    loop → resolve o problema

*/