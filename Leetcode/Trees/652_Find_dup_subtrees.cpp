// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees,
// you only need to return the root node of any one of them.
// Two trees are duplicate if they have the same structure with same node values.

// Example 1:

//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// The following are two duplicate subtrees:

//       2
//      /
//     4
// and
//     4
// Therefore, you need to return above trees' root in the form of a list.

// https://leetcode.com/problems/find-duplicate-subtrees/

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
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m1;
        vector<TreeNode*> retVec;
        
        findDupsHelper(root, m1, retVec);
        
        return retVec;
    }
    
    string findDupsHelper(TreeNode* root, unordered_map<string, int>& m1, vector<TreeNode*>& retVec)
    {
        if(root == NULL)
            return "";
        
        string str = to_string(root->val) + " " +
                    findDupsHelper(root->left, m1, retVec) + " " +
                    findDupsHelper(root->right, m1, retVec);
        
        if(++m1[str] == 2)
            retVec.push_back(root);
        
        return str;
    }
};