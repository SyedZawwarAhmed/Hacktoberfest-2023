#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// function to create an empty node and returning it to the "head" node.

Node *createnode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;

    return node;
}

// function to insert nodes in a linked list starting with head or after head.

Node *insert(Node *head, int data)
{
    if (head == NULL)
    {
        head = createnode(data);
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = createnode(data);
    }
    return head;
}

// function to display the whole linked list.

void disp(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// function to shift a linked list by a specific number 
// (positive means numbers from the end right will shift to left and vice versa)

Node* shift(Node **head, int k)
{
    Node* HEAD = *head;
    if(k < 0)
    {
        k = k*(-1);
        for (int i = 0; i < k; i++)
        {
            Node* newnode = createnode(HEAD->data);
            HEAD = HEAD->next;
            Node* temp = HEAD;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            Node* temp = HEAD;
            while(temp->next->next!=nullptr)
            {
                temp = temp->next;
            }
            Node* newnode = createnode(temp->next->data);
            temp->next = nullptr;
            newnode->next = HEAD;
            HEAD = newnode;
        }
    }
    return HEAD;

}

int main()
{
    Node *head = nullptr; // intializing the head with nullptr
    head = insert(head, 0);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    // with postive values

    // Linked List before : 0 1 2 3 4 5

    head = shift(&head,2);

    // Linked List after : 4 5 0 1 2 3

    // with negative values

    // Linked List before : 0 1 2 3 4 5

    head = shift(&head,-2);

    // Linked List after : 2 3 4 5 0 1

    disp(head);
}


