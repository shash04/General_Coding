// Return the root node of a binary search tree that matches the given preorder traversal.

// Example 1:
// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]

// Note: 
// 1 <= preorder.length <= 100
// The values of preorder are distinct.

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return NULL;
        
        int start = 0;
        return getBST(preorder, start, INT_MAX);
    }
    
    TreeNode* getBST(vector<int>& preorder, int& idx, int maxVal)
    {        
        if(idx >= preorder.size() || preorder[idx] > maxVal)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        
        root->left = getBST(preorder, idx, root->val);
        root->right = getBST(preorder, idx, maxVal);
        
        return root;
    }
};