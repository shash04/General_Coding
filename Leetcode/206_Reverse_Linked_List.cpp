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
    void reverseUtil(ListNode** head, ListNode* curr, ListNode* prev){
        if(curr == NULL){
            *head = prev;
            return;
        }            
        ListNode* next = curr->next;
        curr->next = prev;
        
        reverseUtil(head, next, curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;        
        reverseUtil(&head, head, prev);
        return head;
    }
};