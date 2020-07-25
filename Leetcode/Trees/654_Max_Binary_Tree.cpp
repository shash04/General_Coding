// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
// Note:
// The size of the given array will be in the range [1,1000].

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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* retHead = NULL;
        
        if(nums.size() == 0)
            return retHead;
        
        retHead = constructTree(nums, 0, nums.size() - 1);
        
        return retHead;
    }
    
    TreeNode* constructTree(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int max = nums[start];
        int maxIdx = start;
        
        findMax(nums, start, end, max, maxIdx);
        
        TreeNode* newNode = new TreeNode(max);
        
        newNode->left = constructTree(nums, start, maxIdx - 1);
        newNode->right = constructTree(nums, maxIdx + 1, end);
        
        return newNode;
    }
    
    void findMax(vector<int>& nums, int start, int end, int& max, int& maxIdx)
    {
        for(int i=start; i <= end; i++)
        {
            if(max < nums[i])
            {
                max = nums[i];
                maxIdx = i;
            }
        }
    }
};