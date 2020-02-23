// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i],
// return true if and only if all the given nodes form exactly one valid binary tree.

// If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

// Note that the nodes have no values and that we only use the node numbers in this problem.

// Example 1:
// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
// Output: true

// Example 2:
// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
// Output: false

// Example 3:
// Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
// Output: false

// Example 4:
// Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
// Output: false

// https://leetcode.com/contest/weekly-contest-177/problems/validate-binary-tree-nodes/

class Solution {
    bool helper(vector<bool>& visited, vector<int>& leftChild, vector<int>& rightChild, int n, int& idx)
    {
        if(visited[idx])
            return false;
        
        visited[idx] = true;
        
        bool flag = true;
        
        if(leftChild[idx] != -1)
            flag = helper(visited, leftChild, rightChild, n, leftChild[idx]);
        if(flag && rightChild[idx] != -1)
            flag = helper(visited, leftChild, rightChild, n, rightChild[idx]);
        
        return flag;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited (n, false);
        
        int idx = 0;
        bool retFlag = helper(visited, leftChild, rightChild, n, idx);
        
        for(int i=0; i<visited.size(); i++)
        {
            if(visited[i] == false)
                 retFlag = false;
        }
        
        return retFlag;
    }
};
