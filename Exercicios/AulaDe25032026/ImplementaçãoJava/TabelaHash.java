package Exercicios.AulaDe25032026.ImplementaçãoJava;

public class TabelaHash {
    private TabelaHash.Node[] table;
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

    private int defaultHashFunction(int key) {
        return Math.abs(key);
    }

    public void put(int key) {
        int index = hash(key);
        // TODO: Implementar inserção no início da lista (ou verificar se já existe)
        Node current = table[index];
        
        while (current != null) {
            if(current.key == key){
                return;
            }
            current = current.next;
        }
        Node newNode = new Node(key);
        newNode.next = table [index];
        table[index] = newNode;
    }

    public boolean contains(int key) {
        int index = hash(key);
        // TODO: Implementar busca na lista encadeada do índice
        Node current = table[index];

        while(current != null){
            if(current.key == key){
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public void remove(int key) {
        int index = hash(key);
        // TODO: Implementar remoção na lista encadeada
        Node current = table [index];
        Node prev = null;

        while(current != null){
            if(current.key == key){
                if(prev == null){
                    table[index] = current.next;
                } else{
                    prev.next = current.next;
                }
                return;
            }
            prev = current;
            current = current.next;
        }
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

    public void reHash() {
        int oldCapacity = capacity;
        int newCapacity = capacity * 2 + 1;
        Node[] newTable = new Node[newCapacity];

        for (int i = 0; i < oldCapacity; i++) {
            Node n = table[i];

            while (n != null) {
                Node temp = n;
                n = n.next;

                int newIndex = defaultHashFunction(temp.key) % capacity;
                temp.next = newTable[newIndex];
                newTable[newIndex] = temp;
            }
        }
        table = newTable;
    }
}