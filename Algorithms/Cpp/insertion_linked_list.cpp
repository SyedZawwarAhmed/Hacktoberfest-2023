#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* takeInput(){
    int data;
    cout<<"enter linked list data: ";
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node * n= new Node(data);
      if(head==NULL){
        head=n; tail=n;
     }
        else{
            tail->next=n;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
Node* insertNode(Node* head, int data,int i){
    Node * newNode=new Node(data);
    int count =0;
    Node*temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(count<i-1 && temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node*a=temp->next;
        temp->next= newNode;
        newNode->next=a;
    }
}
int main()
{
    int index,data;
    Node*head= takeInput();
     print(head);
    cout<<endl<<"enter index ";
    cin>>index;
    cout<<"enter data ";
    cin>>data;
    insertNode(head,data,index);
    print(head);
    return 0;
}

