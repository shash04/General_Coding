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