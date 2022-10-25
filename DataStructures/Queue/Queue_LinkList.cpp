#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(){
        next = NULL;
    }
    node(int val){
        this->val = val;
        next = NULL;
    }
};

node* enqueue(node* root, int val);
node* dequeue(node* root);
void display(node* root);

int main(){
    node* root;
    root = enqueue(root, 1);
    root = enqueue(root, 2);
    root = enqueue(root, 3);
    root = enqueue(root, 4);
    root = dequeue(root);
    display(root);

    return 0;
}
node* enqueue(node* root, int val){
    node* temp_node;
    temp_node = root;
    root = new node(val);
    root->next = temp_node;
    return root;
}
node* dequeue(node* root){
    if(root->next != NULL){
        root->next = dequeue(root->next);
    }
    else{
        delete root;
        return NULL;
    }
    return root;
}
void display(node* root){
    while(root != NULL){
        cout<<root->val<<" ";
        root = root->next;
    }
}