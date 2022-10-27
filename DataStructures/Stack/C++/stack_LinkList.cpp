#include<iostream>
using namespace std;

class node{
    public:
        int val;
        node* next;
        node(){
            this->next = NULL;
        }
        node(int val){
            this->val = val;
            this->next = NULL;
        }
};

node* push(node* root, int val);
node* pop(node* root);
void display(node* root);

int main(){
    node* root;
    root = push(root, 1);
    root = push(root, 2);
    root = push(root, 3);
    root = pop(root);
    root = pop(root);
    display(root);

   return 0; 
}

node* push(node* root, int val){
    if(root == NULL){
        root = new node(val);
    }
    else{
        root->next = push(root->next, val);
    }
    return root;
}
void display(node* root){
    if(root->next == NULL){
        cout<<root->val<<" ";
        return;
    }
    display(root->next);
    cout<<root->val<<" ";
}
node* pop(node* root){
    if(root->next == NULL){
        delete root;
        return NULL;
    }
    root->next = pop(root->next);
    return root;
}