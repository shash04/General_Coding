// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values
// with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants.
// The tree s could also be considered as a subtree of itself.

// Example 1:
// Given tree s:
//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.

// Example 2:
// Given tree s:
//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

// https://leetcode.com/problems/subtree-of-another-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {   
    bool isEqual(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL)
            return false;
        
        if(root1->val == root2->val)
            return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
        
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};