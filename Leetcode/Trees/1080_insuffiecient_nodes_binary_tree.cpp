// Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.
// A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.
// Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

// Example 1:
// Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
// Output: [1,2,3,4,null,null,7,8,9,null,14]

// Example 2:
// Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
// Output: [5,4,8,11,null,17,4,7,null,null,null,5]

// Example 3:
// Input: root = [1,2,-3,-5,null,4,null], limit = -1
// Output: [1,null,-3,4]

// Note:
// The given tree will have between 1 and 5000 nodes.
// -10^5 <= node.val <= 10^5
// -10^9 <= limit <= 10^9

// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // If at leaf node, check if the path sum satisfies condition
        // If not, return NULL ptr
        if(!root->left && !root->right)
        {
            if(root->val < limit)
                return NULL;
            else
                return root;
        }
        
        // Recursively call for left and right subtrees
        if(root->left)
            root->left = sufficientSubset(root->left, limit - root->val);
        if(root->right)
            root->right = sufficientSubset(root->right, limit - root->val);
        
        // Both left and right nodes are insufficient, thus current node is also insufficient
        if(!root->left && !root->right)
            return NULL;
        
        return root;
    }
};