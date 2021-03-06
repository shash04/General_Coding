// Given a binary tree, return the vertical order traversal of its nodes values.
// For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
// Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the
// values of the nodes in order from top to bottom (decreasing Y coordinates).
// If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
// Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

// Example 1:
// Input: [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation: 
// Without loss of generality, we can assume the root node is at position (0, 0):
// Then, the node with value 9 occurs at position (-1, -1);
// The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
// The node with value 20 occurs at position (1, -1);
// The node with value 7 occurs at position (2, -2).

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// ********************************************************************************
// Using map and custom sort
// ********************************************************************************
class Solution {
    map<int, vector<pair<int,int>>> xMap;
    
    void fillMap(TreeNode* root, int x, int y)
    {
        if(root == NULL)
            return;
        
        xMap[x].push_back({y, root->val});
        
        fillMap(root->left, x - 1, y - 1);
        fillMap(root->right, x + 1, y - 1);
    }
    
    static bool mySort(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.first != b.first)
            return a.first > b.first;
        
        return a.second < b.second;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> retVec;
        
        if(root == NULL)
            return retVec;
        
        fillMap(root, 0, 0);
        
        for(auto entry : xMap)
        {
            auto& currVec = entry.second;
            
            sort(currVec.begin(), currVec.end(), mySort);
            
            vector<int> temp;
            
            for(auto& currPair : currVec)
            {
                temp.push_back(currPair.second);
            }
            
            retVec.push_back(temp);
        }
        
        return retVec;
    }
};

// ********************************************************************************
// Alternate Solution using BFS - Queue
// ********************************************************************************
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        
        map<int, vector<pair<int, int>>> m1;

        BFS(m1, root, 0, 0);
    
        for( auto xIter : m1 )
        {
            vector<int> v1;
            auto nodeVec = xIter.second;
            sort(nodeVec.begin(), nodeVec.end());
            
            for(auto iterNode: nodeVec)
            {
                v1.push_back(iterNode.second);
            }
            result.push_back(v1);
        }
        return result;
    }
    
    void BFS(map<int, vector<pair<int, int>>> &m1, TreeNode* root, int x, int y)
    {
        queue<pair<TreeNode*, pair<int, int>>> q1;
        q1.push(make_pair(root, make_pair(x, y)));
        
        while(!q1.empty())
        {
            auto currPair = q1.front();
            q1.pop();
            
            auto currNode = currPair.first;
            auto currCoord = currPair.second;
            
            int currX = currCoord.first;
            int currY = currCoord.second;
            
            m1[currX].push_back(make_pair(currY, currNode->val));
            
            if(currNode->left)
                q1.push(make_pair(currNode->left, make_pair(currX-1, currY+1)));
            if(currNode->right)
                q1.push(make_pair(currNode->right, make_pair(currX+1, currY+1)));
        }
    }
    
    // Driver function to sort the vector elements by  
    // first element of pair in descending order 
    // bool sortRev(const pair<int,int> &a, const pair<int,int> &b) 
    // { 
    //        return (a.first > b.first); 
    // }
};