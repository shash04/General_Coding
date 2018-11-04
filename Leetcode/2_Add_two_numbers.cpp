// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        
        int sum     = l1->val + l2->val;
        int carry   = sum / 10;
        int rem     = sum % 10;
        
        ListNode* res = new ListNode(rem);
        ListNode* ansList = res;
        list1 = list1->next;
        list2 = list2->next;
        
        while(list1 != NULL || list2 != NULL)
        {
            if(list1 == NULL)
            {
                sum = list2->val + carry;
                list2 = list2->next;
            }
            else if(list2 == NULL)
            {
                sum = list1->val + carry;
                list1 = list1->next;
            }
            else
            {
                sum = list1->val + list2->val + carry;
                list1 = list1->next;
                list2 = list2->next;
            }
            carry   = sum / 10;
            rem     = sum % 10;
            ansList->next = new ListNode(rem);
            ansList = ansList->next;
        }
        if(carry)
            ansList->next = new ListNode(carry);
        
        return res;
    }
};