// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of
// the two subtrees of every node never differ by more than 1.

// Example:
// Given the sorted array: [-10,-3,0,5,9],
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//       0
//      / \
//    -3   9
//    /   /
//  -10  5

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        
        TreeNode* root = createTree(nums, 0, nums.size()-1);
        return root;
    }
    
    TreeNode* createTree(vector<int>& nums, int low, int high)
    {
        if(low>high)
            return NULL;
        
        int mid = low + (high-low)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = createTree(nums, low, mid-1);
        newNode->right = createTree(nums, mid+1, high);
        return newNode;
    }
};