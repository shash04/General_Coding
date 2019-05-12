// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes
// is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

// Note:
// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.

// https://leetcode.com/problems/reverse-nodes-in-k-group/

// My Logic:
// 1) Split list into smaller lists with k size
// 2) Reverse the small lists
// 3) Store the heads of reversed smaller lists
// 4) Connect all stored heads
// FYI) dont forget to add the incomplete (size<k) at end of original list

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k <= 1)
            return head;
        ListNode* currHead = head;
        ListNode* nextHead;
        ListNode* iter = head;
        vector<ListNode*> headPtrs;
        
        while(iter != NULL)
        {
            for(int i=0; i<k-1 && iter != NULL; i++)
            {
                iter = iter->next;
            }
            if(!iter)
            {
                headPtrs.push_back(currHead);               // FYI step
                break;
            }
            nextHead = iter->next;
            iter->next = NULL;                              // Split into small sublists
            ListNode* revHead = reverseList(currHead);      // Reverse sublist
            headPtrs.push_back(revHead);                    // Store head of reversed sublist
            currHead = nextHead;
            iter = nextHead;
        }
        
        for(int i=0; i<headPtrs.size()-1; i++)              // Connect all stored heads
        {
            ListNode* curr = headPtrs[i];
            while(curr->next)
            {
                curr = curr->next;
            }
            curr->next = headPtrs[i+1];
        }       
        return headPtrs[0];                                 // Return first head stored
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};