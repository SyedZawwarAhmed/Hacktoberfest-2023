package LinkedList;

public class Main {
    public static void main(String[] args) {
        var head = new Node(2);
        var node1 = new Node(12);
        var node2 = new Node(24);

        head.next = node1;
        node1.next = node2;

        traverse(head);
    }

    static void traverse(Node head) {
        Node temp = head;

        while (temp != null) {
            System.out.println(temp.data + " ");
            temp = temp.next;
        }
    }
}
