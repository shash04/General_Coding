// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        vector<int> vec;
        vector<vector<int>> ret;
        
        if(!root)
            return ret;
        
        q1.push(root);
        
        while(!q1.empty() || !q2.empty())
        {
            while(!q1.empty())
            {
                TreeNode* curr = q1.front();
                q1.pop();
                if(curr->left) q2.push(curr->left);
                if(curr->right) q2.push(curr->right);
                vec.push_back(curr->val);
            }
            if(vec.size())
            {
                ret.push_back(vec);
                vec.clear();
            }        
            while(!q2.empty())
            {
                TreeNode* curr = q2.front();
                q2.pop();
                if(curr->left) q1.push(curr->left);
                if(curr->right) q1.push(curr->right);
                vec.push_back(curr->val);
            }
            if(vec.size())
            {
                ret.push_back(vec);
                vec.clear();
            }
        }
        return ret;
    }
};

