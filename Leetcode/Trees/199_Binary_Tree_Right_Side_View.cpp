// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        
        queue<TreeNode*> q1;
        TreeNode* curr;
        q1.push(root);
        int l1 = 1;         // Number of nodes in current level
        int l2 = 0;         // Count for number of nodes to be added in next level
        
        while(!q1.empty())
        {
            while(l1--)
            {
                curr = q1.front();
                q1.pop();
                if(curr->left)
                {
                    q1.push(curr->left);
                    l2++;   
                }
                if(curr->right)
                {
                    q1.push(curr->right);
                    l2++;
                }
                if(l1 == 0)
                    ret.push_back(curr->val);
            }
            l1 = l2;
            l2 = 0;
        }
        return ret;
    }
};