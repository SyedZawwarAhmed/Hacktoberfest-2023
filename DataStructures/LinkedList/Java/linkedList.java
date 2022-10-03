package DataStructures.LinkedList.Java;

public class linkedList {
    public static void main(String[] args) {
        var head = new node(2);
        var node1 = new node(12);
        var node2 = new node(24);

        head.next = node1;
        node1.next = node2;

        traverse(head);
    }

    static void traverse(node head) {
        node temp = head;

        while (temp != null) {
            System.out.println(temp.data + " ");
            temp = temp.next;
        }
    }
}
