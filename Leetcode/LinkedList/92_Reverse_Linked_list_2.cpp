// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

// https://leetcode.com/problems/reverse-linked-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// ***************************************************************************************
// Iterative approach
// ***************************************************************************************
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next)
            return head;
        
        ListNode* p1 = head;
        
        for(int i=1; i<m-1; i++)
        {
            p1 = p1->next;
        }
        
        ListNode* p2;
        if(m == 1)
            p2 = p1;
        else
            p2 = p1->next;

        ListNode* curr = p2;
        ListNode* prev = NULL;
        for(int i=0; i<n-m+1; i++)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(m == 1)
        {
            head = prev;
            p2->next = curr;
        }    
        else
        {
            p1->next = prev;
            p2->next = curr;
        }           
        
        return head;
    }
};

// ***************************************************************************************
// Recursive approach with separating list into 3 parts
// ***************************************************************************************

class Solution {
    void reverseList(ListNode** head, ListNode* curr, ListNode* prev)
    {
        if(curr == NULL)
        {
            *head = prev;
            return;
        }
        
        ListNode* next = curr->next;
        curr->next = prev;
        
        reverseList(head, next, curr);
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || (n == 1))
            return head;
        
        ListNode* iter1 = head;
        ListNode* iter2 = head;
        
        // move iter1 and iter2
        // assuming iter1 and iter2 are less than len of list
        for(int i = 1; i < m - 1; i++)
            iter1 = iter1->next;
        
        for(int i = 1; i < n; i++)
            iter2 = iter2->next;
        
        // seperating list from iter2 
        ListNode* tmp = iter2->next;
        iter2->next = NULL;
        iter2 = tmp;
        
        // seperate iter1 from list to be reversed
        ListNode* revHead;
        
        // Check if list to be reversed starts from head - special case
        if(m == 1)
        {
            revHead = head;
        }
        else
        {
            revHead = iter1->next;
            iter1->next = NULL;
        }
        
        reverseList(&revHead, revHead, NULL);
        
        if(m == 1)
        {
            head = revHead;
        }
        else
        {
            iter1->next = revHead;
        }
        
        // Join curr list with iter2
        ListNode* iter = head;
        
        while(iter->next != NULL)
            iter = iter->next;
        
        iter->next = iter2;
        
        return head;
    }
};
