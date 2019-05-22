// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

// https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        // Idea is to split the list midway in two sub lists and then recursively call sortList
        ListNode* l1End = head;
        ListNode* l2Start = head;
        ListNode* l2End = head;
        
        // At the end of this while loop l2Start will point to second sub list
        while(l2End && l2End->next)
        {
            l1End = l2Start;
            l2Start = l2Start->next;
            l2End = l2End->next->next;
        }
        
        // Break the link for first list
        l1End->next = NULL;
        
        // Recursively call sortList for two sublists
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(l2Start);
        
        // Return merged list from two sorted sub lists
        return Merge(l1, l2);
    }
    
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next = Merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = Merge(l1, l2->next);
            return l2;
        }
    }
};