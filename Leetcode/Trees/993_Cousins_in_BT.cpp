// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are cousins.

// Example 1:
// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false

// Example 2:
// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true

// Example 3:
// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false

// Note:
// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.

// https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
    // cousinDepth keeps track of depth at which any of the two nodes found
    // isCousin is final ans
    int cousinDepth = -1;
    bool isCousin = false;
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        
        DFS(root, x, y, 0);
        
        return isCousin;
    }
    
    bool DFS(TreeNode* root, int x, int y, int currDepth)
    {
        if(root == NULL)
            return false;
        
        // checking currDepth with cousinDepth avoids going beyond first node depth
        if(cousinDepth != -1 && currDepth > cousinDepth)
            return false;
        
        if(root->val == x || root->val == y)
        {
            if(cousinDepth == -1)
                cousinDepth = currDepth;
            
            // Return true if second node found is at same depth
            return cousinDepth == currDepth;
        }
        
        // left and right indicate if nodes were found in either of the subtrees
        bool left = DFS(root->left, x, y, currDepth + 1);
        bool right = DFS(root->right, x, y, currDepth + 1);
        
        // For the two nodes to be cousins , they need to be present in two different subtrees and at same depth
        // cousinDepth will be equal to currDepth + 1 for siblings (same parent). Avoid that case.
        if(left && right && cousinDepth != currDepth + 1)
            isCousin = true;
        
        // Indicates that the node was found in either of the subtrees
        return left || right;
    }
};