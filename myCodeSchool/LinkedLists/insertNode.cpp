// Insert node at beginning if head == NULL or pos == 0
// Insert node at any given position
// Assumption: pos < end of list

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
        cout << temp->data << endl;
        temp = temp->next;
    }
}

node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *insertNode(node *head, int data, int pos)
{
    if (head == NULL)
    {
        head = createNode(data);
        return head;
    }

    node *temp = head;

    if (pos == 0)
    {
        head = createNode(data);
        head->next = temp;
        return head;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    node *nextNode = temp->next;
    temp->next = createNode(data);
    temp->next->next = nextNode;
    return head;
}

int main()
{
    node *head = insertNode(NULL, 1, 0);
    head = insertNode(head, 2, 1);
    head = insertNode(head, 3, 1);
    printList(head);
    return 0;
}