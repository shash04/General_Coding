// Print a binary tree in an m*n 2D string array following these rules:
// 1) The row number m should be equal to the height of the given binary tree.
// 2) The column number n should always be an odd number.
// 3) The root node's value (in string format) should be put in the exactly middle of the first row it can be put.
// The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and
// right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the
// right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree
// is none while the other is not, you don't need to print anything for the none subtree but still need to leave the
// space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space
// for both of them.
// 4) Each unused space should contain an empty string "".
// 5) Print the subtrees following the same rules.

// Example 1:
// Input:
//      1
//     /
//    2
// Output:
// [["", "1", ""],
//  ["2", "", ""]]

// Example 2:
// Input:
//      1
//     / \
//    2   3
//     \
//      4
// Output:
// [["", "", "", "1", "", "", ""],
//  ["", "2", "", "", "", "3", ""],
//  ["", "", "4", "", "", "", ""]]

// https://leetcode.com/problems/print-binary-tree/

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
    int getHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    void fillVector(TreeNode* root, int row, int low, int high, vector<vector<string>>& result) {
        if(root == NULL)
            return;
        
        int mid = low + (high-low)/2;
        result[row][mid] = to_string(root->val);
        fillVector(root->left, row + 1, low, mid - 1, result);
        fillVector(root->right, row + 1, mid + 1, high, result);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int num_rows = height;
        int num_col = pow(2, height) - 1;
        
        vector<vector<string>> result(num_rows, vector<string>(num_col, ""));
        fillVector(root, 0, 0, num_col - 1, result);
        
        return result;
    }
};