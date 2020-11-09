// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes),
// write a function to check whether these edges make up a valid tree.

// Example 1:
// Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
// Output: true

// Example 2:
// Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
// Output: false
// Note: you can assume that no duplicate edges will appear in edges.
// Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

// https://leetcode.com/problems/graph-valid-tree/

// *********************************************************************************************************
// To tell whether a graph is a valid tree, we have to:
// Make sure there is no cycle in the graph - this has to be a none-cyclic graph
// Make sure every node is reached - this has to be a connected graph
// *********************************************************************************************************
class Solution {
    int findParent(const vector<int>& parentVec, int node)
    {
        if(parentVec[node] == node)
            return node;
        
        return findParent(parentVec, parentVec[node]);
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parentVec (n, 0);
        
        // every node is its own parent
        for(int i = 0; i < n; i++)
        {
            parentVec[i] = i;
        }
        
        for(auto& edge : edges)
        {
            // For every edge, get parent and check if same
            // if yes, then is will be a cycle - return false
            int x = findParent(parentVec, edge[0]);
            int y = findParent(parentVec, edge[1]);
            
            if(x == y)
                return false;
            
            // else make one node as other's parent
            parentVec[y] = x;
        }
        
        // For a valid tree, there can be only one parent
        int parents = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(parentVec[i] == i)
                parents++;
        }
        
        return parents == 1;
    }
};