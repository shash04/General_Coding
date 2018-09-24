// Generic code for testing Linked List functions

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void printList(node *temp)
{
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void recRevUtil( node** head, node *curr, node *prev){
    if(!curr)
    {
        *head = prev;
        return;
    }
    node* next = curr->next;
    curr->next = prev;
    recRevUtil(head, next, curr);
}

void recursiveReverse(node **head)
{
    if(!head)
        return;
    recRevUtil(head, *head, NULL);    
}

int main()
{
    node *head                          = createNode(0);
    head->next                          = createNode(1);
    head->next->next                    = createNode(2);
    head->next->next->next              = createNode(3);
    head->next->next->next->next        = createNode(4);
    head->next->next->next->next->next  = createNode(5);
    printList(head);
    recursiveReverse(&head);
    printList(head);
    return 0;
}