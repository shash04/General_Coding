// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    unordered_map<int, int> inMap;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        // for every postorder[postIdx] node in inorder, all nodes to left of postorder[postIdx] will be in left subtree
        // and all nodes to right of postorder[postIdx] will be in right subtree
        // create node for postorder[postIdx] and recursively call helper by splitting inorder in left and right subtrees
        return buildTreeHelper(postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& postorder, int postIdx, int inStart, int inEnd)
    {
        if(postIdx >= postorder.size() || inStart > inEnd)
            return NULL;
        
        TreeNode* newNode = new TreeNode(postorder[postIdx]);
        
        int inIdx = inMap[postorder[postIdx]];
        
        // postorder visits all right nodes before any left node. Thus for left node recursive call,
        // postIdx = postIdx - 1 - (Number of Nodes to right of inIdx till inEnd) = postIdx - 1 - (inEnd - inIdx)

        newNode->left = buildTreeHelper(postorder, postIdx - 1 - (inEnd - inIdx), inStart, inIdx - 1);
        newNode->right = buildTreeHelper(postorder, postIdx - 1, inIdx + 1, inEnd);
        
        return newNode;
    }
};