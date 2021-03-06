// Given a binary tree, return the sum of values of nodes with even-valued grandparent.
// (A grandparent of a node is the parent of its parent, if it exists.)

// If there are no nodes with an even-valued grandparent, return 0.

// Example 1:
// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 18
// Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

// Constraints:
// The number of nodes in the tree is between 1 and 10^4.
// The value of nodes is between 1 and 100.

// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int helper(TreeNode* cur, TreeNode* parent, TreeNode* grandParent)
    {
        if(cur == NULL)
            return 0;
        
        int result = 0;
        
        if(grandParent != NULL && grandParent->val % 2 == 0)
            result += cur->val;
        
        result += helper(cur->left, cur, parent) + helper(cur->right, cur, parent);
        
        return result;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};