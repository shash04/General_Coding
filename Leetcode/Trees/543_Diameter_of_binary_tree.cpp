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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int longestPath = 0;
        
        findDiameter(root, longestPath);
        
        return longestPath;
    }
    
    int findDiameter(TreeNode* root, int &longestPath)
    {
        if(root == NULL)
            return 0;
        
        // Calculate left and right longest paths
        int leftLongestPath = findDiameter(root->left, longestPath);
        int rightLongestPath = findDiameter(root->right, longestPath);
        
        // Add and update max
        longestPath = max(leftLongestPath + rightLongestPath, longestPath);
        
        // Return the max of left and right longest paths + 1 (current node height)
        return max(leftLongestPath + 1, rightLongestPath + 1);
    }
};
