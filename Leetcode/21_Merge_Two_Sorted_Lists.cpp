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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode* head;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        
        ListNode* newList = head;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                newList->next = l1;
                l1 = l1->next;
            }
            else{
                newList->next = l2;
                l2 = l2->next;
            }
            newList = newList->next;
        }
            
        while(l1){
            newList->next = l1;
            l1 = l1->next;
            newList = newList->next;
        }
        
        while(l2){
            newList->next = l2;
            l2 = l2->next;
            newList = newList->next;
        }
        
        return head;
    }
};


// Alternate solution - recursive 
/*
ListNode* merge_lists(ListNode* head_1, ListNode* head_2)
{
	ListNode* result = NULL;
    
	if(head_1 == NULL)
		return head_2;
	else if(head_2 == NULL)
		return head_1;

	if(head_1->data <= head_2->data){
		result = head_1;
		result->next = merge_lists(head_1->next, head_2);
	}
	else{
		result = head_2;
		result->next = merge_lists(head_1, head_2->next);
	}
	return result;
}

*/

