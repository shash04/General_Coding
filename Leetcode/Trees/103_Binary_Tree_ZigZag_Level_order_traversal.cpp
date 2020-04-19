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

// ********************************************************************************
// Queue approach with normal traversal and reversing vector for alternate dirs
// ********************************************************************************

#define RIGHTDIR 0
#define LEFTDIR 1

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> retVec;
        
        if(root == NULL)
            return retVec;
        
        queue<TreeNode*> q1;
        int dir = LEFTDIR;
        
        q1.push(root);
        
        while(!q1.empty())
        {
            vector<int> currVec;
            int currQSize = q1.size();
            
            while(currQSize--)
            {
                TreeNode* currNode = q1.front();
                currVec.push_back(currNode->val);
                q1.pop();
                
                if(currNode->left) q1.push(currNode->left);
                if(currNode->right) q1.push(currNode->right);
            }
            
            if(dir == LEFTDIR)
            {
                retVec.push_back(currVec);
                dir = RIGHTDIR;
            }
            else
            {
                reverse(currVec.begin(), currVec.end());
                retVec.push_back(currVec);
                dir = LEFTDIR;
            }
        }
        
        return retVec;
    }
};

// ********************************************************************************
// Two stack approach
// ********************************************************************************
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
