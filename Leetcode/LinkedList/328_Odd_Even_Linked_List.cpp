// Given a singly linked list, group all odd nodes together followed by the even nodes.
// Please note here we are talking about the node number and not the value in the nodes.
// You should try to do it in place. The program should run in O(1) space complexity and O(N) time complexity.

// Example 1:
// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL

// Example 2:
// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL

// Note:
// The relative order inside both the even and odd groups should remain as it was in the input.
// The first node is considered odd, the second node even and so on ...

// https://leetcode.com/problems/odd-even-linked-list/

// **************************************************************************************
// Solution 1 - create another linked list with even head and point odd list to even head
// **************************************************************************************

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* iterOdd = head;
        ListNode* iterEven = head->next;
        
        ListNode* evenHead = head->next;
        
        while(iterEven != NULL && iterEven->next != NULL)
        {
            iterOdd->next = iterEven->next;
            iterOdd = iterOdd->next;
            
            iterEven->next = iterOdd->next;
            iterEven = iterEven->next;
        }
        
        iterOdd->next = evenHead;
        return head;
    }
};

// **************************************************************************************
// Solution 2 - Attach even nodes at back of main list and go to next odd node
// **************************************************************************************
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* iterEven = head;
        ListNode* iterOdd = head;
        
        while(iterEven->next != NULL)
        {
            iterEven = iterEven->next;
        }
        
        ListNode* evenHead = head->next;
        bool headNode = true;
        
        while(iterOdd != evenHead && (iterOdd->next != evenHead || headNode))
        {
            
            if(headNode == true)
                headNode = false;
            
            ListNode* oddNext = iterOdd->next;
            iterEven->next = iterOdd->next;
            iterOdd->next = iterOdd->next->next;
            
            iterEven = iterEven->next;
            iterEven->next = NULL;
            iterOdd = iterOdd->next;
        }
        
        return head;
    }
};