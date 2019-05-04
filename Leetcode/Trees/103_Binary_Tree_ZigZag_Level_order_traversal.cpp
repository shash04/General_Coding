// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
// right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root)
            return vec;
        
        stack<TreeNode*> goRight;
        stack<TreeNode*> goLeft;
        
        goRight.push(root);
        
        while(!goRight.empty() || !goLeft.empty())
        {
            vector<int> v1;
            vector<int> v2;
            
            while(!goRight.empty())
            {
                TreeNode* curr = goRight.top();
                goRight.pop();
                v1.push_back(curr->val); 
                if(curr->left) goLeft.push(curr->left);
                if(curr->right) goLeft.push(curr->right);
            }
            
            while(!goLeft.empty())
            {
                TreeNode* curr = goLeft.top();
                goLeft.pop();
                v2.push_back(curr->val);
                if(curr->right) goRight.push(curr->right);
                if(curr->left) goRight.push(curr->left);
            }
            
            if(!v1.empty()) vec.push_back(v1);
            if(!v2.empty()) vec.push_back(v2);
        }
        
        return vec;
    }
};

// Optimal time solution
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        bool forward = false;
        while (!q.empty()) {
            int size = q.size();
            forward = !forward;
            vector<int> vec;
            while (size) {
                TreeNode *t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                size--;
            }
            if (!forward) reverse(vec.begin(), vec.end());
            res.push_back(vec);
        }
        
        return res;
    }
};
