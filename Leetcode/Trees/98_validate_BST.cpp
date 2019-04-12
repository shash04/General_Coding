// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, NULL, NULL);
    }
    
    bool isValidBSTUtil(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(root == nullptr)
            return true;
        else if((minNode && minNode->val >= root->val) ||
                (maxNode && maxNode->val <= root->val))
            return false;
        return (
           isValidBSTUtil(root->right, root, maxNode) &&
           isValidBSTUtil(root->left, minNode, root) );
    }
};