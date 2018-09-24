#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int getLength(node *head)
{
    int ans = 0;
    node *temp = head;
    while (temp)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}

node *getIntersectionNode(node *headA, node *headB)
{
    int L1 = getLength(headA);
    int L2 = getLength(headB);

    node *bigList, *smallList;
    int diff = 0;
    if (L1 > L2)
    {
        bigList = headA;
        smallList = headB;
        diff = L1 - L2;
    }
    else
    {
        bigList = headB;
        smallList = headA;
        diff = L2 - L1;
    }

    for (int i = 0; i < diff; i++)
        bigList = bigList->next;

    while (bigList != NULL && smallList != NULL)
    {
        if (bigList == smallList)
            return bigList;
        else
        {
            bigList = bigList->next;
            smallList = smallList->next;
        }
    }

    return NULL;
}