// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL

// https://leetcode.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reverseUtil(ListNode** head, ListNode* curr, ListNode* prev)
    {
        if(curr == NULL)
        {
            *head = prev;
            return;
        }
        ListNode* next = curr->next;
        curr->next = prev;
        
        reverseUtil(head, next, curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;

        reverseUtil(&head, head, NULL);
        return head;
    }
};