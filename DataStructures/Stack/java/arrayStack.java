package DataStructures.Stack.Java;

import java.util.ArrayList;

public class arrayStack {
    public static void main(String[] args) {
        Stack s=new Stack();
        s.push(12);
        s.push(13);
        System.out.println(s.peek());
        
    }
}


class Stack{
    ArrayList<Integer> al=new ArrayList<>();
    void push(int x){
        al.add(x);
    }
    int pop(){
        int res=al.get(al.size()-1);
        al.remove(al.size()-1);
        return res;

    }
    int peek(){
        return al.get(al.size()-1);

    }
    boolean isEmpty(){
        return al.isEmpty();
    }
    int size(){
        return al.size();
    }
}
