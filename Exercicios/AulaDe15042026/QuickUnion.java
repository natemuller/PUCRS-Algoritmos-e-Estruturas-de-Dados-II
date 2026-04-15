/*
O objetivo deste trabalho é gerenciar grupos de pessoas que se conhecem. Se A é amigo de B, e B é amigo de C, 
    então A e C pertencem ao mesmo grupo social. Para isto:
- Execute e analise o código inicial fornecido (QuickUnion).
- Altere o código para implementar alguma das otimizações sugeridas no material teórico
    Otimização escolhida: weighted QU + path compression

- Altere o método main para conectar elementos aleatoriamente (sugestão: 85% das pessoas pertencem a algum grupo)
    Conexões foram feitas aleatoriamente até que 85% dos elementos estivessem em grupos.

- Informe quantos grupos foram criados e analise como ficou sua estrutura
    A estrutura ficou com menos profundidade devido a otimização implementada.
    
Autores: 
    Emile Vargas - 23111271
    Natan Müller - 23104739
*/

package Exercicios.AulaDe15042026;

import java.util.Random;

public class QuickUnion {
    private int[] pai;
    private int totalGrupos;
    private int[] tam;

    public QuickUnion(int n) {
        pai = new int[n];
        tam = new int[n];
        totalGrupos = n;
        for (int i = 0; i < n; i++) {
            pai[i] = i;
            tam[i] = 1;
        }
    }

    public int encontrar(int i) {
        while (i != pai[i]) {
            pai[i] = pai[pai[i]];
            i = pai[i];
        }
        // System.out.println("Acessos para encontrar: " + acessos);
        return i;
    }

    public void adicionarAmizade(int p1, int p2) {
        int raiz1 = encontrar(p1);
        int raiz2 = encontrar(p2);

        if (raiz1 != raiz2) {
            if (tam[raiz1] < tam[raiz2]) {
                pai[raiz1] = raiz2;
                tam[raiz2] += tam[raiz1];
            }
            else {
                pai[raiz2] = raiz1;
                tam[raiz1] += tam[raiz2];
            }
            totalGrupos--;
        }
    }

    public static void main(String[] args) {
        int N = 20;
        QuickUnion rede = new QuickUnion(N);
        Random rand = new Random();

        int meta = (int) Math.ceil(0.85 * N);

        while ((N - rede.totalGrupos) < meta - 1) {
            int p = rand.nextInt(N);
            int q = rand.nextInt(N);

            if (rede.encontrar(p) != rede.encontrar(q)) {
            rede.adicionarAmizade(p, q);
            }
        }

        System.out.println("Total de grupos: " + rede.totalGrupos);
        System.out.println("Pessoas em grupos (aprox.): " + (N - rede.totalGrupos + 1));

        int maxProf = 0;
        int somaProf = 0;

        for (int i = 0; i < N; i++) {
            int atual = i;
            int prof = 0;

            while (atual != rede.pai[atual]) {
                atual = rede.pai[atual];
                prof++;
            }

            somaProf += prof;
            if (prof > maxProf) {
                maxProf = prof;
            }
        }

        System.out.println("Profundidade máxima: " + maxProf);
        System.out.println("Profundidade média: " + (somaProf / (double) N));

        System.out.println("\nEstado final do array 'pai':");
        for (int i = 0; i < N; i++) {
            System.out.print(i + ":" + rede.pai[i] + " | ");
        }
    }
}