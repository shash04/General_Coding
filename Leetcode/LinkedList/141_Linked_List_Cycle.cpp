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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode* speed1 = head;
        ListNode* speed2 = head->next;
        
        while(speed1 && speed2 && speed2->next){
            if(speed1 == speed2)
                return true;
            else{
                speed1 = speed1->next;
                speed2 = speed2->next->next;
            }
        }
        
        return false;
    }
};