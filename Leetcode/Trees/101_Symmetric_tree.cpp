// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3

// https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        bool ret = isSymmetric(root->left, root->right);
        return ret;
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        
        return ((left->val == right->val) &&
                isSymmetric(left->left, right->right) &&
                isSymmetric(left->right, right->left));
    }
};