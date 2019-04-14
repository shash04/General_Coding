// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is
// the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// Example:
// Given a binary tree 
//           1
//          / \
//         2   3
//        / \     
//       4   5    
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int DFS(TreeNode* root, int &longestPath) {
        if(root == nullptr)
            return 0;
        
        int leftLongestPath = DFS(root->left, longestPath);
        int rightLongestPath = DFS(root->right, longestPath);
        longestPath = max(leftLongestPath + rightLongestPath, longestPath);
        return max(leftLongestPath + 1, rightLongestPath + 1);
    }
    
    int diameterOfBinaryTree(TreeNode* root)
    {
        int longestPath = 0;
        DFS(root, longestPath);
        return longestPath;
    }
};