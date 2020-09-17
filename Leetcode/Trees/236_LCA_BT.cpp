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
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q, bool& found1, bool& found2)
    {
        if(root == NULL)
            return NULL;
        
        // if root == p node, set found1 to true and return p
        // Note - if q is in subtree of p, then p is LCA - as returning no recursive call for q
        // thus found2 will not be set to true - thus important to check later on if q actually is present in tree
        if(root == p)
        {
            found1 = true;
            return root;
        }
        
        if(root == q)
        {
            found2 = true;
            return root;
        }
        
        // Check if p and q present in left and right subtrees
        TreeNode* presentInLeft  = findLCA(root->left, p, q, found1, found2);
        TreeNode* presentInRight = findLCA(root->right, p, q, found1, found2);
        
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
        if(root == NULL)
            return root;
        
        bool found1 = false, found2 = false;
        
        TreeNode* lca = findLCA(root, p, q, found1, found2);
        
        if( (found1 && found2) || (found1 && findNode(root, q)) || (found2 && findNode(root, p)) )
           return lca;
           
       return NULL;
    }
};