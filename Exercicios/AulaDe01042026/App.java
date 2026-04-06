public class App {

  // --- Método Main ---
    public static void main(String[] args) {
        String input = "exercicio huffman - algoritmos e programacao ii";

        // fazer "a mao" para esta entrada primeiro para testar
        input = "aeaeaeaeaeaeaeaeae-aiaiaiaiaii-aoaoo-auu-";

        Huffman huffman = new Huffman(input);

        System.out.println("=== Compressão de Huffman ===");
        System.out.println("Entrada: \"" + input + "\"");
        
        // Exibição da Tabela de Frequências
        System.out.println("\n--- Tabela de Frequências ---");
        System.out.printf("%-10s | %-10s%n", "Caractere", "Frequência");
        System.out.println("---------------------------");
        huffman.getFrequencyTable().forEach((k, v) -> {
            String label = (k == ' ') ? "' '" : k.toString();
            System.out.printf("%-10s | %-10d%n", label, v);
        });

        // Codificação
        // Atenção - vale como exercício, normalmente huffman é construído
        //           sobre o texto de entrada e é utilizado apenas para este texto
        //           alternativa seria ter uma árvore geral com as frequencias
        //           de uma determinada língua ou tipo de entrada
        String encoded = huffman.encode(input);
        System.out.println("\n--- Resultados ---");
        System.out.println("Dicionário: " + huffman.getDictionary());
        System.out.println("Texto Codificado: " + encoded);
        
        // Decodificação
        String decoded = huffman.decode(encoded);
        System.out.println("Texto Decodificado: " + decoded);
        
        // Cálculo de economia (opcional para os alunos)
        int bitsOriginais = input.length() * 8; // Assumindo ASCII 8 bits
        int bitsHuffman = encoded.length();
        System.out.printf("\nTamanho original (ASCII): %d bits\n", bitsOriginais);
        System.out.printf("Tamanho Huffman: %d bits\n", bitsHuffman);
        System.out.printf("Economia: %.2f%%\n", (1.0 - (double)bitsHuffman/bitsOriginais) * 100);
    }

}