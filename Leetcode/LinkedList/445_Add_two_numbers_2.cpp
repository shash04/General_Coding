// You are given two non-empty linked lists representing two non-negative integers.
// The most significant digit comes first and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

// https://leetcode.com/problems/add-two-numbers-ii/

class Solution {
public:
    void printStack(stack<int> s1){
        while(!s1.empty()){
            cout<<s1.top()<<endl;
            s1.pop();
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        stack<int> s1;
        stack<int> s2;
        stack<int> ans;
        ListNode* retHead;
        
        ListNode *iter1, *iter2;
        iter1 = l1;
        iter2 = l2;
        
        while(iter1){
            s1.push(iter1->val);
            iter1 = iter1->next;
        }
        
        while(iter2){
            s2.push(iter2->val);
            iter2 = iter2->next;
        }
        
        int rem = 0;
        int sum = 0;
        
        while(!s1.empty() && !s2.empty()){
            sum = s1.top() + s2.top() + rem;
            rem = sum / 10;
            sum = sum % 10;
            ans.push(sum);
            s1.pop();
            s2.pop();
        }
        
        while(!s2.empty()){
            sum = s2.top() + rem;
            rem = sum / 10;
            sum = sum % 10;
            ans.push(sum);
            s2.pop();
        }
        
        while(!s1.empty()){
            sum = s1.top() + rem;
            rem = sum / 10;
            sum = sum % 10;
            ans.push(sum);
            s1.pop();
        }
        
        if(rem)
            ans.push(rem);
        
        retHead = new ListNode(ans.top());
        ans.pop();
        ListNode* temp = retHead;
        
        while(!ans.empty())
        {
            ListNode* newNode = new ListNode(ans.top());
            temp->next = newNode;
            ans.pop();
            temp = temp->next;
        }
        
        return retHead;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */