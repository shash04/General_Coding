// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:
// Given 1->2->3->4, reorder it to 1->4->2->3.

// Example 2:
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        
        // Find middle node and split into two lists
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        
        // Reverse the second half
        reverseList(&secondHalf, secondHalf, nullptr);
        
        // Merge two lists
        ListNode* l1 = head;
        ListNode* l2 = secondHalf;
        while(l1->next && l2)
        {
            ListNode* l1Next = l1->next;
            l1->next = l2;
            ListNode* l2Next = l2->next;
            l2->next = l1Next;
            l1 = l1Next;
            l2 = l2Next;
        }
        if(l2)
            l1->next = l2;
    }
    
    void reverseList(ListNode** head, ListNode* curr, ListNode* prev)
    {
        if(!curr->next)
        {
            *head = curr;
            curr->next = prev;
            return;
        }
        ListNode* next = curr->next;
        curr->next = prev;
        reverseList(head, next, curr);
    }
};