// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
// lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// ************************************************************************************
// Non-recursive approach = p and q will be on one side of tree till common ancestor
// ************************************************************************************
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
    bool findNode(TreeNode* root, TreeNode* n)
    {
        if(root == NULL || root == n)
            return true;
        else if(n->val < root->val)
            return findNode(root->left, n);
        else
            return findNode(root->right, n);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Return NULL if root is NULL or either of the nodes are not present in the tree
        if(root == NULL || !findNode(root, p) || !findNode(root, q))
            return NULL;
        
        while(root)
        {
            // both p and q lie in left subtree
            if((p->val < root->val) && (q->val < root->val))
                root = root->left;
            // both p and q lie in right subtree
            else if((p->val > root->val) && (q->val > root->val))
                root = root->right;
            // either current node is p OR q
            // OR both nodes present in different subtrees
            else
                break;
        }
        
        return root;
    }
};

// ************************************************************************************
// Classic approach = Populate vectors while finding nodes and reverse search common
// ************************************************************************************

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
