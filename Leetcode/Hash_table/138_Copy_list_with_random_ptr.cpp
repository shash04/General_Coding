// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

// Refer this video for explanation - https://www.youtube.com/watch?v=OvpKeraoxW0

// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        
        Node *l1, *l2, *ret_head;
        l1 = head;

        while(l1)
        {
            l2 = new Node(l1->val, l1->next, NULL);
            l1->next = l2;
            l1 = l1->next->next;
        }
        
        l1 = head;
        ret_head = head->next;
        
        while(l1)
        {
            l2 = l1->next;
            if(l1->random)
                l2->random = l1->random->next;
            else
                l2->random = NULL;
            
            l1 = l1->next->next;
        }
        
        l1 = head;
        while(l1)
        {
            l2 = l1->next;
            l1->next = l2->next;
            
            if(l2->next)
                l2->next = l2->next->next;

            l1 = l1->next;
        }
        return ret_head;
    }
};