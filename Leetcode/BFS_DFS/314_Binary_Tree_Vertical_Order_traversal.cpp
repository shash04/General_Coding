// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

// Examples 1:
// Input: [3,9,20,null,null,15,7]

//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7 

// Output:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]

// Examples 2:
// Input: [3,9,8,4,0,1,7]

//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7 

// Output:

// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]

// Examples 3:
// Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2

// Output:

// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]

// https://leetcode.com/problems/binary-tree-vertical-order-traversal/


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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> retVec;
        
        if(root == NULL)
            return retVec;
        
        // map<int, vector<pair<int, int>>> colNodesMap;
        map<int, map<int, vector<int>>> colNodesMap;
        
        int currCol = 0;
        int currHeight = 0;
        
        // DFS(root, colNodesMap, currCol, currHeight);
        BFS(root, currCol, currHeight, retVec);
        
//         for(auto& colMap : colNodesMap)
//         {
//             vector<int> tempVec;
            
//             for(auto& currHeightMap : colMap.second)
//             {
//                 vector<int> vec = currHeightMap.second;
//                 copy(vec.begin(), vec.end(), back_inserter(tempVec));
//             }
            
//             retVec.push_back(tempVec);
//         }
        
        return retVec;
    }
    
    void DFS(TreeNode* root, map<int, map<int, vector<int>>>& colNodesMap, int currCol, int currHeight)
    {
        if(root == NULL)
            return;
        
        colNodesMap[currCol][currHeight].push_back(root->val);
        
        DFS(root->left, colNodesMap, currCol - 1, currHeight + 1);
        DFS(root->right, colNodesMap, currCol + 1, currHeight + 1);
    }
    
    void BFS(TreeNode* root, int currCol, int currHeight,  vector<vector<int>>& retVec)
    {
        map<int, vector<int>> colNodesMap;
        
        queue<pair<TreeNode* , int>> colNodeslQueue;
        
        colNodeslQueue.push({root, 0});
        
        while(!colNodeslQueue.empty())
        {
            auto currPair = colNodeslQueue.front();
            
            colNodeslQueue.pop();
            
            TreeNode* currNode = currPair.first;
            
            int currCol = currPair.second;
                        
            colNodesMap[currCol].push_back(currNode->val);
            
            if(currNode->left)
                colNodeslQueue.push({currNode->left, currCol - 1});
            
            if(currNode->right)
                colNodeslQueue.push({currNode->right, currCol + 1});
        }
        
        for(auto& entry : colNodesMap)
        {
            retVec.push_back(entry.second);
        }
    }
};