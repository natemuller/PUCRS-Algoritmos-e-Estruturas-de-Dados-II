package Exercicios.AulaDe25032026.ImplementaçãoJava;

import java.util.Random;

public class App {
    public static void main(String[] args) {
        int capacidade = 10;
        int quantidadeInsercoes = 25;
        TabelaHash hash = new TabelaHash(capacidade);
        Random random = new Random();

        System.out.println("--- Inserindo " + quantidadeInsercoes + " valores aleatórios ---");
        
        for (int i = 0; i < quantidadeInsercoes; i++) {
            // Gera valores entre 0 e 99
            int valor = random.nextInt(100);
            System.out.print(valor + " ");
            hash.put(valor);
            hash.reHash();
        }

        System.out.println("\n\n--- Estado Atual da Tabela Hash ---");
        hash.printTable();

        // Teste de busca com um valor fixo e um aleatório
        int valorBusca = 50; 
        System.out.println("\n--- Testes de Busca ---");
        System.out.println("Contém o valor " + valorBusca + "? " + hash.contains(valorBusca));

        // Teste de remoção
        System.out.println("\n--- Teste de Remoção ---");
        System.out.println("Limpando os índices (se existirem)...");
        for (int i = 0; i < 5; i++) {
            int alvo = random.nextInt(100);
            if (hash.contains(alvo)) {
                System.out.println("Removendo: " + alvo);
                hash.remove(alvo);
            }
        }
        
        System.out.println("\n--- Estado Final da Tabela ---");
        hash.printTable();
    }
}