// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example 1:
// Given the following tree [3,9,20,null,null,15,7]:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(calcHeight(root->left) - calcHeight(root->right)) > 1)
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    
    int calcHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return 1 + max(calcHeight(root->left), calcHeight(root->right));
    }
};