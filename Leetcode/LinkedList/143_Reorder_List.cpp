// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:
// Given 1->2->3->4, reorder it to 1->4->2->3.

// Example 2:
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:
// Given 1->2->3->4, reorder it to 1->4->2->3.

// Example 2:
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
class Solution {
    void reverse(ListNode** head, ListNode* curr, ListNode* prev)
    {
        if(curr == NULL)
        {
            *head = prev;
            return;
        }
        
        ListNode* next = curr->next;
        curr->next = prev;
        
        reverse(head, next, curr);
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        
        // Find middle node and split into two lists
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = NULL;
        
        // Reverse the second half
        reverse(&list2, list2, NULL);
        
        // Merge two lists
        while(list1 && list2)
        {
            ListNode* nextL1 = list1->next;
            list1->next = list2;
            
            list2 = list2->next;
            list1 = list1->next;
            
            list1->next = nextL1;
            list1 = list1->next;
        }
    }
};
