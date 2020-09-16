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
            return head;
        
        // iterate through the list 
        // - create new nodes and insert them in between the existing nodes (modify the list)
        Node* iter = head;
        
        while(iter != NULL)
        {
            Node* newNode = new Node(iter->val);
            newNode->next = iter->next;
            iter->next = newNode;
            
            iter = newNode->next;
        }
        
        // after 1st iteration - list of 2 * size with new nodes interleaved and random pointers of new nodes = NULL
        
        // iterate through the list
        // - fix random pointer of duplicate to point to next node of random pointer pointed by current original node
        iter = head;
        
        while(iter != NULL)
        {
            Node* copyNode = iter->next;
            
            if(iter->random == NULL)
                copyNode->random = NULL;
            else
                copyNode->random = iter->random->next;
            
            iter = copyNode->next;
        }
        
        // iterate through the list
        // - fix original and duplicate lists' next pointer
        iter = head;
        Node* copyHead = head->next;
        
        while(iter != NULL)
        {
            Node* copyNode = iter->next;
            
            iter->next = copyNode->next;
            
            iter = iter->next;
            
            if(iter == NULL)
                copyNode->next = NULL;
            else
                copyNode->next = iter->next;
        }
        
        return copyHead;
    }
};