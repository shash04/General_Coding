#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

/////////////////////////////////////////////////////////////////////////
// Iterative reverse Linked List
// curr->next | store next int tmep | current->next = prev | curr = temp

void reverseIterative(node **head)
{
    node *curr = *head;
    node *prev, *next;
    prev = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

/////////////////////////////////////////////////////////////////////////
// Recursive Reverse Linked List

void recRevUtil(node **head, node *curr, node *prev)
{
    if (!curr)
    {
        *head = prev;
        return;
    }
    node *next = curr->next;
    curr->next = prev;
    recRevUtil(head, next, curr);
}

void recursiveReverse(node **head)
{
    if (!head)
        return;
    recRevUtil(head, *head, NULL);
}