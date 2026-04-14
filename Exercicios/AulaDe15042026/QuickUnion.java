/*
O objetivo deste trabalho é gerenciar grupos de pessoas que se conhecem. Se A é amigo de B, e B é amigo de C, 
    então A e C pertencem ao mesmo grupo social. Para isto:
- Execute e analise o código inicial fornecido (QuickUnion).
- Altere o código para implementar alguma das otimizações sugeridas no material teórico
- Altere o método main para conectar elementos aleatoriamente (sugestão: 85% das pessoas pertencem a algum grupo)
- Informe quantos grupos foram criados e analise como ficou sua estrutura

Autores: 
    Emile Vargas - 23111271
    Natan Müller - 23104739
*/

package Exercicios.AulaDe15042026;

import java.util.Random;

public class QuickUnion {
    private int[] pai;
    private int totalGrupos;

    public QuickUnion(int n) {
        pai = new int[n];
        totalGrupos = n;
        for (int i = 0; i < n; i++) {
            pai[i] = i;
        }
    }

    public int encontrar(int i) {
        int acessos = 0;
        while (i != pai[i]) {
            i = pai[i];
            acessos++;
        }
        // System.out.println("Acessos para encontrar: " + acessos);
        return i;
    }

    public void adicionarAmizade(int p1, int p2) {
        int raiz1 = encontrar(p1);
        int raiz2 = encontrar(p2);

        if (raiz1 != raiz2) {
            pai[raiz1] = raiz2; 
            totalGrupos--;
        }
    }

    public static void main(String[] args) {
        int N = 20;
        QuickUnion rede = new QuickUnion(N);

        for (int i = 0; i < N - 1; i++) {
            rede.adicionarAmizade(i, i+1);
        }

        System.out.println("\nEstado final do array 'pai':");
        for (int i = 0; i < N; i++) {
            System.out.print(i + ":" + rede.pai[i] + " | ");
        }

        System.out.println("\n\nTestando o pior caso:");
        // Para encontrar a raiz do elemento 0, o algoritmo terá que 
        // percorrer todos os N elementos.
        long inicio = System.nanoTime();
        int raiz = rede.encontrar(0);
        long fim = System.nanoTime();

        System.out.println("Raiz do elemento 0: " + raiz);
        System.out.println("Tempo para encontrar(0): " + (fim - inicio) + " ns");
    }
}