package DataStructures.Stack.Java;

public class linkedListStack {
    public static void main(String[] args) {
        MyStack s=new MyStack();
        s.push(10);
        s.push(20);
        System.out.println(s.pop());
        System.out.println(s.peek());

    }
}
class Node{
    int data;
    Node next;
    Node(int x){
        data=x;
        next=null;
    }
}
class MyStack{
    Node head;
    int sz;
    MyStack(){
        head=null;
        sz=0;
    }
    int size(){
        return sz;
    }
    boolean isEmpty(){
        return (head==null);
    }
    void push(int x){
        Node temp=new Node(x);
        temp.next=head;
        head=temp;
        sz++;
    }
    int pop(){
        if(head==null){
            return -1;
        }
        int res=head.data;
        head=head.next;
        sz--;
        return res;
    }
    int peek(){
        if(head==null){
            return -1;
        }
        return head.data;
    }
}

