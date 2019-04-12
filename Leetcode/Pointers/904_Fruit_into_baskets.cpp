// In a row of trees, the i-th tree produces fruit with type tree[i].
// You start at any tree of your choice, then repeatedly perform the following steps:
// Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
// Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
// Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
// You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.
// What is the total amount of fruit you can collect with this procedure?

// Example 1:
// Input: [0,1,2,2]
// Output: 3
// Explanation: We can collect [1,2,2].
// If we started at the first tree, we would only collect [0, 1].

// Example 2:
// Input: [1,2,3,2,2]
// Output: 4
// Explanation: We can collect [2,3,2,2].
// If we started at the first tree, we would only collect [1, 2].

// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int fruit_iter1 = 0;
        int fruit_type = tree[0];
        unordered_map<int, int> fTypes;
        
        int max_count = 0;
        int ind_count = 0;
        
        for(int i=0; i<tree.size(); i++)
        {
            fTypes[tree[i]]++;
            if(fTypes.size() > 2)
            {
                ind_count = i - fruit_iter1 + 1;
                fTypes.erase(tree[fruit_iter1-1]);
            }
            else
            {
                ind_count++;
            }
            
            if(ind_count > max_count)
                    max_count = ind_count;
            
            if(tree[i] != fruit_type)
            {
                fruit_iter1 = i;
                fruit_type = tree[i];
            }
        }
        
        return max_count;
    }
};