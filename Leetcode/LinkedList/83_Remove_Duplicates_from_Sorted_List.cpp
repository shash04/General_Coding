// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:
// Input: 1->1->2
// Output: 1->2

// Example 2:
// Input: 1->1->2->3->3
// Output: 1->2->3

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* iter = head;
        
        while(iter->next != NULL)
        {
            if(iter->val == iter->next->val)
                removeNode(iter);
            else
                iter = iter->next;
        }
        
        return head;
    }
    
    void removeNode(ListNode* &iter)
    {
        ListNode* nextNode = iter->next->next;
        delete iter->next;
        iter->next = nextNode;
    }
};
