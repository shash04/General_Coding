// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.
// For example, given
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]

// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

//  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        // for every preorder[preIdx] node in inorder, all nodes to left of preorder[preIdx] will be in left subtree
        // and all nodes to right of preorder[preIdx] will be in right subtree
        // create node for preorder[preIdx] and recursively call helper by splitting inorder in left and right subtrees
        return buildTreeHelper(preorder, inMap, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inMap, int preIdx, int inStart, int inEnd)
    {
        if(preIdx >= preorder.size() || inStart > inEnd)
            return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[preIdx]);
        
        int inIdx = inMap[preorder[preIdx]];
        
        // preorder visits all left nodes before first right node. Thus for right node recursive call,
        // preIdx = preIdx + numNodesOnLeft + 1 = preIdx + (inIdx - inStart) + 1
        
        newNode->left = buildTreeHelper(preorder, inMap, preIdx + 1, inStart, inIdx - 1);
        newNode->right = buildTreeHelper(preorder, inMap, preIdx + (inIdx - inStart) + 1, inIdx + 1, inEnd);
        
        return newNode;
    }
};