#include <iostream>
using namespace std;

class Queue{
    public:
    int n, head, tail;
    int* arr;
    Queue(){
        cout<<"Enter Queue Size: ";
        cin>>n;
        arr = new int[n];
        tail = 0;
        head = -1;
    }
    void enqueue(int val){
        head++;
        if(head == n){
            cout<<"Queue Overflowed";
            return;
        }
        for(int i=head; i>= 0; i--){
            if(i == 0){
                arr[i] = val;
                continue;
            }
            arr[i] = arr[i - 1];
        }
    }
    void dequeue(){
        if(head == -1){
            cout<<"Queue is Empty";
            return;
        }
        head--;
    }
    void display(){
        for(int i = 0; i<=head; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}