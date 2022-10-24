#include <iostream>
using namespace std;

int arr[10];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        cout << "The queue is empty" << endl;
        return true;
    }
    else
    {
        return false;
    }
};

int enqueue(int x)
{
    if (rear == ((sizeof(arr) / sizeof(arr[0])) - 1))
    {
        cout << "Queue is full" << endl;
        return true;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear = (rear + 1);
        arr[rear] = x;
    }
    arr[rear] = x;
};

int dequeue()
{
    if (isEmpty())
    {
        return true;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        arr[front] = 0;
        front = front + 1;
    }
};

void print(){
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " "
             << " ->" << i << "index" << endl;
    }
}

int main()
{
    enqueue(43);
    enqueue(44);
    enqueue(45);
    enqueue(46);
    enqueue(47);
    enqueue(48);
    enqueue(49);


    dequeue();
    dequeue();
    dequeue();
    dequeue();


    print();
    
};