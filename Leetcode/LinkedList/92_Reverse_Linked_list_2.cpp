// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

// https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next)
            return head;
        
        ListNode* p1 = head;
        
        for(int i=1; i<m-1; i++)
        {
            p1 = p1->next;
        }
        
        ListNode* p2;
        if(m == 1)
            p2 = p1;
        else
            p2 = p1->next;

        ListNode* curr = p2;
        ListNode* prev = NULL;
        for(int i=0; i<n-m+1; i++)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(m == 1)
        {
            head = prev;
            p2->next = curr;
        }    
        else
        {
            p1->next = prev;
            p2->next = curr;
        }           
        
        return head;
    }
};