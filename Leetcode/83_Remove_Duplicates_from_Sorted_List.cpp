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