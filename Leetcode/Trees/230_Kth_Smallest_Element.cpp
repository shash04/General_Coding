// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Example 1:
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1

// Example 2:
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
// How would you optimize the kthSmallest routine?

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

// *****************************************************************************************************************
// Iterative approach with Stack
// *****************************************************************************************************************
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sStack;
        bool rootNode = true;
        
        while(root != NULL)
        {
            sStack.push(root);
            root = root->left;
        }
        
        while(k--)
        {
            TreeNode* currNode = sStack.top();
            sStack.pop();

            if(k == 0)
                return currNode->val;
            
            TreeNode* rightSubTree = currNode->right;
            
            while(rightSubTree != NULL)
            {
                sStack.push(rightSubTree);
                rightSubTree = rightSubTree->left;
            }
        }
        
        return -1;
    }
};

// *****************************************************************************************************************
// Recursive approach with building in order vector
// *****************************************************************************************************************
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrderVec;
        
        helper(root, inOrderVec, k);
        
        if(k > inOrderVec.size())
            return -1;
        
        return inOrderVec[k - 1];
    }
    
    void helper(TreeNode* root, vector<int>& inOrderVec, int k)
    {
        if(root == NULL)
            return;
        
        helper(root->left, inOrderVec, k);
        
        inOrderVec.push_back(root->val);
        
        helper(root->right, inOrderVec, k);
    }
};