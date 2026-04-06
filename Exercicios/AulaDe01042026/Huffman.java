import java.util.*;

public class Huffman {

    // Classe interna para representar os nós da árvore
    private static class Node implements Comparable<Node> {
        char ch;
        int freq;
        Node left, right;

        Node(char ch, int freq, Node left, Node right) {
            this.ch = ch;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }

        boolean isLeaf() {
            return left == null && right == null;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.freq, other.freq);
        }
    }

    private Node root;

    // por facilidade vamos utilizar classes de dicionário da API Java
    private Map<Character, String> charToCode;
    private Map<Character, Integer> frequencyTable;

    public Huffman(String text) {
        this.charToCode = new HashMap<>();
        this.frequencyTable = new HashMap<>();
        this.root = buildTree(text);
        generateCodes(this.root, "");
    }

    // Método privado para construir a árvore e preencher a tabela de frequências
    private Node buildTree(String text) {
        //
        // TODO: este é o código mais importante e difícil
        //       discuta a implementação com seus colegas antes de escrever o código
        //
        // Passo 1. Calcular frequências e popular o dicionário de frequências
        //
        // ...
        //
        // Passo 2. Fila de prioridade - inserir os dados da tabela de frequencina 
        //                               em uma minHeap (lembre que precisamos retirar
        //                               a cada iteração as duas menores frequências)
        //
        // Novamente vamos usar a API Java por simplicidade
        PriorityQueue<Node> pq = new PriorityQueue<>();
        //
        // ...
        //
        // Passo 3. Finalmente montar a árvore de Huffman
        //
        while (pq.size() > 1) {
            // ...
        }
        return pq.poll();
    }

    // Percorre a árvore e gera o dicionário de codificação (charToCode)
    private void generateCodes(Node node, String code) {

        // TODO ...

    }

    // Retorna o texto codificado, utilizando o dicionário de codificação
    public String encode(String text) {
        StringBuilder sb = new StringBuilder();
        
        // TODO ...

        return sb.toString();
    }

    // Descodifica uma string de bits, utilizando a árvore de Huffman
    public String decode(String bits) {
        StringBuilder sb = new StringBuilder();

       // TODO ...

       return sb.toString();
    }

    // Métodos para o Main acessar os dados internos
    public Map<Character, Integer> getFrequencyTable() {
        return Collections.unmodifiableMap(frequencyTable);
    }

    public Map<Character, String> getDictionary() {
        return Collections.unmodifiableMap(charToCode);
    }

}