// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
// lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    bool findNode(TreeNode* root, int num, vector<TreeNode*> &v)
    {
        if(root == NULL)
            return false;
        v.push_back(root);
        if(root->val == num)
            return true;
        else if(num < root->val)
            return findNode(root->left, num, v);
        else
            return findNode(root->right, num, v);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        
        if(findNode(root, p->val, v1) && findNode(root, q->val, v2))
        {
            for(auto rev_iter1 = v1.rbegin(); rev_iter1 != v1.rend(); rev_iter1++)
            {
                for(auto rev_iter2 = v2.rbegin(); rev_iter2 != v2.rend(); rev_iter2++)
                {
                    if(*rev_iter1 == *rev_iter2)
                        return *rev_iter1;
                }
            }
        }
        return NULL;
    }
};