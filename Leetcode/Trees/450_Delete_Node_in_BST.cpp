// Given a root node reference of a BST and a key, delete the node with the given key in the BST.
// Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
// Note: Time complexity should be O(height of tree).

// https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if(root->left == NULL && root->right == NULL)               // Case 1: No children
            {
                delete root;
                root = NULL;
            }
            else if(root->right == NULL)                                // Case 2: 1 Child
            {
                TreeNode* temp = root->left;
                delete root;
                root = temp;
            }
            else if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                root = temp;
            }
            else                                                        // Case 3: Both children
            {
                TreeNode* temp = findMaxInLeft(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
    
    TreeNode* findMaxInLeft(TreeNode* root)
    {
        if(root->right == NULL)
            return root;
        
        return findMaxInLeft(root->right);
    }
};