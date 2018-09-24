#include <iostream>
#include <stack>
using namespace std;
struct node
{
    int data;
    node *next;
};

void revListUsingStack(node **head)
{
    if (!head)
        return;

    stack<node *> s1;
    node *temp = *head;

    while (temp)
    {
        s1.push(temp);
        temp = temp->next;
    }

    *head = s1.top();
    s1.pop();
    node *curr = *head;

    while (!s1.empty())
    {
        node *next = s1.top();
        curr->next = next;
        s1.pop();
        curr = curr->next;
    }
    curr->next = NULL;
}