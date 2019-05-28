// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node inthe tree along
// the parent-child connections. The path must contain at least one node and does not need to go through the root.

// Example 1:
// Input: [1,2,3]
//        1
//       / \
//      2   3
// Output: 6

// Example 2:
// Input: [-10,9,20,null,null,15,7]
//    -10
//    / \
//   9  20
//     /  \
//    15   7
// Output: 42

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return INT_MIN;
        
        int maxSum = root->val;
        getMaxSum(root, maxSum);
        return maxSum;
    }
    
    int getMaxSum(TreeNode* root, int& maxSum)
    {
        if(root == NULL)
            return 0;
        
        // Taking max with 0 as if returned value is -ve, it can be ignored
        int leftSum = max(0, getMaxSum(root->left, maxSum));
        int rightSum = max(0, getMaxSum(root->right, maxSum));
        
        int curr_sum = root->val + leftSum + rightSum;
        // Update max if curr_sum is > maxSum
        maxSum = max(curr_sum, maxSum);
        // Return max from left subtree and right subtree
        return max(root->val + leftSum, root->val + rightSum);
    }
};