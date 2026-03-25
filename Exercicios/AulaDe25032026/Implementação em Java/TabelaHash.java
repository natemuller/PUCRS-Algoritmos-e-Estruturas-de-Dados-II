public class TabelaHash {
    private Node[] table;
    private int capacity;

    // Classe interna para o nó da lista encadeada
    private static class Node {
        int key;
        Node next;

        Node(int key) {
            this.key = key;
        }
    }

    public TabelaHash(int capacity) {
        this.capacity = capacity;
        this.table = new Node[capacity];
    }

    private int hash(int key) {
        return Math.abs(key) % capacity;
    }

    public void put(int key) {
        int index = hash(key);
        // TODO: Implementar inserção no início da lista (ou verificar se já existe)
    }

    public boolean contains(int key) {
        int index = hash(key);
        // TODO: Implementar busca na lista encadeada do índice
        return false;
    }

    public void remove(int key) {
        int index = hash(key);
        // TODO: Implementar remoção na lista encadeada
    }

    public void printTable() {
        for (int i = 0; i < capacity; i++) {
            System.out.print("[" + i + "]: ");
            Node current = table[i];
            while (current != null) {
                System.out.print(current.key + " -> ");
                current = current.next;
            }
            System.out.println("null");
        }
    }
}