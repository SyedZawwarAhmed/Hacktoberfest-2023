#include <iostream>
using namespace std;

class stack{
    public:
    int top = -1;
    int *ptr;
    stack(){
        ptr = new int(top+1);
    }

    void push(int val){
        this->top += 1;
        ptr = newArr(ptr, top, val);

    }
    int pop(){
        int t_val = ptr[top];
        this->top -= 1;
        int* t_arr = new int(top);
        for(int i=0; i < top; i++){
            t_arr[i] = this->ptr[i];
        }
        delete[] this->ptr;
        this->ptr = t_arr;
        return t_val;
    }
    int* newArr(int* ptr, int top, int val){
        if(top == 0){
            *ptr = val;
            return ptr;
        }
        int* t_ptr = new int(top);
        for(int i = 0; i < top; i++){
            t_ptr[i] = ptr[i];
        }
        t_ptr[top] = val;
        delete ptr;
        return t_ptr;
    }
    void display(){
        for(int i = 0; i <= this->top; i++){
            cout<<ptr[i]<<endl;
        }
    }
    ~stack(){
        delete ptr;
    }

};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    // cout<<s.pop()<<endl;
    s.display();

    return 0;
}