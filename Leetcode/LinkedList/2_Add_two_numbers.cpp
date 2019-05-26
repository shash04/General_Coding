// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
// and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* resultHead = NULL;
        ListNode* resultIter = NULL;
        int sum = 0, carry = 0;
        
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            ListNode* currSum = new ListNode(sum % 10);
            if(!resultHead)
            {
                resultHead = currSum;
                resultIter = resultHead;
            }
            else
            {
                resultIter->next = currSum;
                resultIter = resultIter->next;
            }
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            sum = l1->val + carry;
            ListNode* currSum = new ListNode(sum % 10);
            resultIter->next = currSum;
            resultIter = resultIter->next;
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2)
        {
            sum = l2->val + carry;
            ListNode* currSum = new ListNode(sum % 10);
            resultIter->next = currSum;
            resultIter = resultIter->next;
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode* currSum = new ListNode(carry);
            resultIter->next = currSum;
        }
        return resultHead;
    }
};