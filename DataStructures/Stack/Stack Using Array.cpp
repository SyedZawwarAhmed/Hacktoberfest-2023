#include <iostream>
using namespace std;

int sizeOfArray = 4;

int *arr = new int(sizeOfArray);

int top = -1;
void push(int x)
{
    if (top == sizeOfArray - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        arr[++top] = x;
    }
};

void pop()
{
    if (top == -1)
    {
        cout << "Error: No element to pop" << endl;
        return;
    }
    top--;
}

int main()
{

    // Taking the input in the array.
    for (int i = 0; i < sizeOfArray; i++)
    {
        int num;
        cout << "Enter Elemens :";
        cin >> num;
        push(num);
    };
    pop();

    // Printing the elements in the array.
    for (int j = 0; j < sizeOfArray; j++)
    {
        cout << arr[j];
    }
};