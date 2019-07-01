// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr_node = root;
        
        while(curr_node)
        {
            if(curr_node->left && curr_node->right)         // curr node has both sub trees
            {
                TreeNode* pre = curr_node->left;            // Go to right most node of left child
                while(pre->right)
                    pre = pre->right;
                pre->right = curr_node->right;              // Right child will become right sub tree of rightmost node of pre
            }
            
            if(curr_node->left)
                curr_node->right = curr_node->left;         // Modify right child to left child
            
            curr_node->left = NULL;
            curr_node = curr_node->right;
        }
    }
};