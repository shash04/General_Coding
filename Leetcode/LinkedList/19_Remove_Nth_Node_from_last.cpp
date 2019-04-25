// Given a linked list, remove the n-th node from the end of list and return its head.
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

// Note:
// Given n will always be valid.

// Follow up:
// Could you do this in one pass?

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* nextnode = NULL;
        
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        if(fast == NULL){
            nextnode = slow->next;
            delete slow;
            head = nextnode;
        }
        else{
            nextnode = slow->next->next;
            delete slow->next;
            slow->next = nextnode;  
        }
        
        return head;
    }
};