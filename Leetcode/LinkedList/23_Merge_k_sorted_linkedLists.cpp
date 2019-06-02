// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

// https://leetcode.com/problems/merge-k-sorted-lists/

// Solution 1: Time complexity: nlog(k) + K^2. Erase function takes time.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        while(lists.size()>1)
        {
            lists.push_back(merge_two_lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    
    ListNode* merge_two_lists(ListNode* head_1, ListNode* head_2)
    {
        ListNode* result = NULL;

        if(head_1 == NULL)
            return head_2;
        else if(head_2 == NULL)
            return head_1;

        if(head_1->val <= head_2->val){
            result = head_1;
            result->next = merge_two_lists(head_1->next, head_2);
        }
        else{
            result = head_2;
            result->next = merge_two_lists(head_1, head_2->next);
        }
        return result;
    }
};


// Solution 2: Time Complexity = nlog(k)
// ***** BEST SOLUTION *****
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        int count = lists.size(), interval = 1;
        
        while (interval < count)
        {
            for (int i = 0; i < count - interval; i += interval *2)
            {
                lists[i] = merge_two_lists(lists[i], lists[i + interval]);
            }
            interval = interval * 2;
        }
        
        return lists[0];
    }
    
    ListNode* merge_two_lists(ListNode* head_1, ListNode* head_2)
    {
        ListNode* result = NULL;

        if(head_1 == NULL)
            return head_2;
        else if(head_2 == NULL)
            return head_1;

        if(head_1->val <= head_2->val){
            result = head_1;
            result->next = merge_two_lists(head_1->next, head_2);
        }
        else{
            result = head_2;
            result->next = merge_two_lists(head_1, head_2->next);
        }
        return result;
    }
};