// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:
// Input: 1->1->2
// Output: 1->2

// Example 2:
// Input: 1->1->2->3->3
// Output: 1->2->3

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* nextNode;
        ListNode* curr = head;
        
        while(curr->next != NULL){
            if(curr->next->val == curr->val){
                nextNode = curr->next->next;
                delete curr->next;
                curr->next = nextNode;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};