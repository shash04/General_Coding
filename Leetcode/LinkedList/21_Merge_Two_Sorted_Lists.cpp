// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

// https://leetcode.com/problems/merge-two-sorted-lists/

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
        else if(l2 == NULL)
            return l1;
        
        ListNode *ret_head, *ret;
        
        if(l1->val < l2->val)
        {
            ret = l1;
            l1 = l1->next;
        }
        else
        {
            ret = l2;
            l2 = l2->next;
        }
        ret_head = ret;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ret->next = l1;
                ret = ret->next;
                l1 = l1->next;
            }
            else
            {
                ret->next = l2;
                ret = ret->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL)
        {
            ret->next = l2;
        }
        else if(l2 == NULL)
        {
            ret->next = l1;
        }
        return ret_head;
    }
};

// Alternate solution - recursive 
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

