// Given a complete binary tree, count the number of nodes.
// Note:
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the
// last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Example:
// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

// https://leetcode.com/problems/count-complete-tree-nodes/

// Walk all the way left and right to determine the height and whether it's a full tree, meaning the last row is full
// If so, then the answer is just 2^height-1
// And since always at least one of the two recursive calls is such a full tree, at least one of the two calls immediately stops
// Runtime complexity is O(log(n)^2)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        TreeNode* leftTree = root;
        TreeNode* rightTree = root;
        int leftHeight = 0, rightHeight = 0;
        
        while(leftTree)
        {
            leftHeight++;
            leftTree = leftTree->left;
        }
        
        while(rightTree)
        {
            rightHeight++;
            rightTree = rightTree->right;
        }

        if(leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};