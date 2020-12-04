// Given a binary search tree, return a balanced binary search tree with the same node values.

// A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

// If there is more than one answer, return any of them.

// Example 1:
// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.

// Constraints:
// The number of nodes in the tree is between 1 and 10^4.
// The tree nodes will have distinct values between 1 and 10^5.

// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    void inOrder(TreeNode* root, vector<int>& nums)
    {
        if(root == NULL)
            return;
        
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    
    TreeNode* createBalancedBST(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int mid = start + (end - start) / 2;
        int curVal = nums[mid];
        
        TreeNode* newNode = new TreeNode(curVal);
        newNode->left  = createBalancedBST(nums, start, mid - 1);
        newNode->right = createBalancedBST(nums, mid + 1, end);
        
        return newNode;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        
        return createBalancedBST(nums, 0, nums.size() - 1);
    }
};