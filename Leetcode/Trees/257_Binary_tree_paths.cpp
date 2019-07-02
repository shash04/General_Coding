// Given a binary tree, return all root-to-leaf paths.
// Note: A leaf is a node with no children.

// Example:
// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

// https://leetcode.com/problems/binary-tree-paths/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)
            return ans;
        getAllPaths(root, ans, "");
        return ans;
    }
    
    void getAllPaths(TreeNode* root, vector<string>& ans, string curr_str)
    {
        if(!curr_str.size())
            curr_str += to_string(root->val);
        else
            curr_str += "->" + to_string(root->val);
        
        if(!root->left && !root->right)
        {
            ans.push_back(curr_str);
            return;
        }
        
        if(root->left)
            getAllPaths(root->left, ans, curr_str);
        if(root->right)
            getAllPaths(root->right, ans, curr_str);
    }
};