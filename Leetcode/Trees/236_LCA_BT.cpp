// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
// lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

// Note:
// All of the nodes' values will be unique.
// p and q are different and both values will exist in the binary tree.

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // One node can be ancestor of other, that case is handled on its own as
        // as it is checked before that both nodes exist in the tree
        if(root == NULL || root == p || root == q)
            return root;

        // Check if p and q present in left and right subtrees
        TreeNode* presentInLeft  = findLCA(root->left, p, q);
        TreeNode* presentInRight = findLCA(root->right, p, q);
        
        // if both left and right subtree returned with valid pointer
        // each present in individual subtrees and cur node is LCA
        if(presentInLeft && presentInRight)
            return root;
        
        // Return either of the subtrees where the nodes are present
        // NULL will be returned if both are false
        if(presentInLeft)
            return presentInLeft;
        else
            return presentInRight;
        
    }
    
    bool findNode(TreeNode* root, TreeNode* n)
    {
        if(root == NULL)
            return false;
        
        return ((root == n) || findNode(root->left, n) || findNode(root->right, n));
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Return NULL if root is NULL or either of the nodes are not present in the tree
        if(root == NULL || !findNode(root, q) || !findNode(root, p))
            return NULL;
        
        return findLCA(root, p, q);
    }
};
