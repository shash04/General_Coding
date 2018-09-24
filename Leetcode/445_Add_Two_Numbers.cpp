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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        stack<int> s1;
        stack<int> s2;
        stack<int> ans;
        
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
            rem = sum/10;
            sum = sum%10;
            ans.push(sum);
            s1.pop();
            s2.pop();
        }
        
        while(!s2.empty()){
            sum = s2.top() + rem;
            rem = sum/10;
            sum = sum%10;
            ans.push(sum);
            s2.pop();
        }
        
        while(!s1.empty()){
            sum = s1.top() + rem;
            rem = sum/10;
            sum = sum%10;
            ans.push(sum);
            s1.pop();
        }
        
        if(rem)
            ans.push(rem);
        
        ListNode* retHead = new ListNode(ans.top());
        ans.pop();
        ListNode* temp = retHead;
        while(!ans.empty()){
            ListNode* newNode = new ListNode(ans.top());
            temp->next = newNode;
            ans.pop();
            temp = temp->next;
        }
        
        return retHead;
    }
};