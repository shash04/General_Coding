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

class Solution {
    unordered_map<int, int> inMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        // for every preorder[preIdx] node in inorder, all nodes to left of preorder[preIdx] will be in left subtree
        // and all nodes to right of preorder[preIdx] will be in right subtree
        // create node for preorder[preIdx] and recursively call helper by splitting inorder in left and right subtrees
        return buildTreeHelper(preorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int preIdx, int inStart, int inEnd)
    {
        if(preIdx >= preorder.size() || inStart > inEnd)
            return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[preIdx]);
        
        int inIdx = inMap[preorder[preIdx]];
        
        // preorder visits all left nodes before first right node. Thus for right node recursive call,
        // preIdx = preIdx + 1 + numNodesOnLeft= preIdx + 1 + (inIdx - inStart)
        
        newNode->left = buildTreeHelper(preorder, preIdx + 1, inStart, inIdx - 1);
        newNode->right = buildTreeHelper(preorder, preIdx + 1 + (inIdx - inStart), inIdx + 1, inEnd);
        
        return newNode;
    }
};