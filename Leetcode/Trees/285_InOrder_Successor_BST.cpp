// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

// The successor of a node p is the node with the smallest key greater than p.val.

// Example 1:
// Input: root = [2,1,3], p = 1
// Output: 2
// Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

// Example 2:
// Input: root = [5,3,6,2,4,null,null,1], p = 6
// Output: null
// Explanation: There is no in-order successor of the current node, so the answer is null.
 

// Note:
// If the given node has no in-order successor in the tree, return null.
// It's guaranteed that the values of the tree are unique.

// https://leetcode.com/problems/inorder-successor-in-bst/

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
    TreeNode* findNode(TreeNode* root, TreeNode* p)
    {
        if(root == NULL)
            return NULL;
        else if(p->val < root->val)
            return findNode(root->left, p);
        else if(p->val > root->val)
            return findNode(root->right, p);
        else
            return root;
    }
    
    TreeNode* findMinInRight(TreeNode* root)
    {
        TreeNode* iter = root;
        
        while(iter->left)
            iter = iter->left;
        
        return iter;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* cur = findNode(root, p);
        
        // If no node matches in tree matches p
        if(cur == NULL)
            return NULL;
        
        // if curr node has right subtree - successor will be min in right subtree
        if(cur->right != NULL)
            return findMinInRight(cur->right);
        
        // If no right subtree, then find a node for which cur lies in left subtree
        TreeNode* parent = root;
        TreeNode* successor = NULL;
        
        while(parent != cur)
        {
            // cur lies in left subtree for iter - update successor
            if(cur->val < parent->val)
            {
                successor = parent;
                parent = parent->left;
            }
            else
            {
                parent = parent->right;
            }
        }
        
        return successor;
    }
};

/*
parent node
update parent if we go to left subtree
root = ancestor
find p in left subtree with ancestor as root
*/