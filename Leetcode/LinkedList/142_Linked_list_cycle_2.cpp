// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the
// linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool cyclePresent = false;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast)
            {
                cyclePresent = true;
                break;
            }
        }
        
        if(!cyclePresent)
            return NULL;
        
        
        // Let L1 = num nodes from head to start of cycle
        // L2 = num nodes from start of cycle to meeting point of slow and fast
        // C = num nodes in cycle
        // As fast ptr has covered twice the distance as slow -
        // 2(L1 + L2) = L1 + L2 + nC    ( n = number of cycles covered by fast ptr )
        // L1 + L2 = nC
        // L1 = nC - L2
        // L1 = (n-1)C + (C - L2)
        // Thus we need to start one ptr from head to cover L1 nodes and other ptr to
        // conitnue for (C - L2) nodes. Then both the ptrs will reach the intersection node
        
        fast = head;
        
        while(fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};
