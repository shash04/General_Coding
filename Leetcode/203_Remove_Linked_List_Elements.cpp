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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        
        ListNode* temp;
        
        while(head && head->val == val){
            temp = head->next;
            delete head;
            head = temp;
        }
        
        if(head == NULL)
            return NULL;
        
        temp = head;
        while(temp->next){
            if(temp->next->val == val){
                ListNode* nextNext = temp->next->next;
                delete temp->next;
                temp->next = nextNext;                
            }
            else
                temp = temp->next;
        }
        
        return head;
    }
};