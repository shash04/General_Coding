// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the
// linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

// https://leetcode.com/problems/linked-list-cycle-ii/

// Solution: using two pointers, one of them one step at a time. another pointer each take two steps. Suppose the first meet at step k,the length of the Cycle is r. so..2k-k=nr,k=nr
// Now, the distance between the start node of list and the start node of cycle is s. the distance between the start of list and the first meeting node is k(the pointer which wake one 
// step at a time waked k steps).the distance between the start node of cycle and the first meeting node is m, so...s=k-m,
// s=nr-m=(n-1)r+(r-m),here we takes n = 1..so, using one pointer start from the start node of list, another pointer start from the first meeting node, all of them wake one step at a time, 
// the first time they meeting each other is the start of the cycle.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        
        while(fast && fast->next)
        {
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            return NULL;
        else
        {
            fast = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }            
        return slow;        
    }
};