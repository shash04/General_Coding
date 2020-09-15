// We are given a binary tree (with root node root), a target node, and an integer value K.

// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

// Output: [7,4,1]

// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.

// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.

// Note:
// The given tree is non-empty.
// Each node in the tree has unique values 0 <= node.val <= 500.
// The target node is a node in the tree.
// 0 <= K <= 1000.

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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
    unordered_map<TreeNode*, TreeNode*> parentChildMap;
    unordered_set<TreeNode*> visited;
    
    void fillParentChildMap(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        if(root->left)
        {
            parentChildMap[root->left] = root;
            fillParentChildMap(root->left);
        }
        
        if(root->right)
        {
            parentChildMap[root->right] = root;
            fillParentChildMap(root->right);
        }
    }
    
    void DFS(TreeNode* root, int K, vector<int>& retVec)
    {
        if(root == NULL || visited.count(root) || K < 0)
            return;
        
        visited.insert(root);
        
        if(K == 0)
            retVec.push_back(root->val);
        
        // DFS for both the child sub trees
        DFS(root->left, K - 1, retVec);
        DFS(root->right, K - 1, retVec);
        
        // DFS also for parent
        DFS(parentChildMap[root], K - 1, retVec);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> retVec;
        
        if(root == NULL)
            return retVec;
        
        // Parent child map helps in doing DFS for parents
        fillParentChildMap(root);
        
        // DFS starting from target node
        // Inside DFS, recursively call it for parent node too
        DFS(target, K, retVec);
        
        return retVec;
    }
};