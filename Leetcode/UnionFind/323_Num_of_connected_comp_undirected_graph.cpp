// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
// write a function to find the number of connected components in an undirected graph.

// Example 1:
// Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

//      0          3
//      |          |
//      1 --- 2    4 

// Output: 2

// Example 2:
// Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

//      0           4
//      |           |
//      1 --- 2 --- 3

// Output:  1
// Note:
// You can assume that no duplicate edges will appear in edges.
// Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

// **************************************************************************************************************
// Concept = Populate a graph and try to visit all nodes
// DFS - connected components will be visited in one call
// number of times DFS called = num of components in undirected graph
// **************************************************************************************************************
class Solution {
    unordered_map<int, vector<int>> graph;
    
    void DFS(int node, int depth, vector<bool>& visited)
    {        
        visited[node] = true;
        
        for(int& next : graph[node])
        {
            if(visited[next])
                continue;
            
            DFS(next, depth + 1, visited);
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {        
        int result = 0;
        
        vector<bool> visited (n, false);
        
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            
            result++;
    
            DFS(i, 0, visited);
        }
        
        return result;
    }
};

// **************************************************************************************************************
// Concept - UNION FIND - Use parent vector to keep track of disjoint sets
// Every node begins as parent of its own. With every edge, if parent isn't same, make one parent of other
// Thus union of two nodes (sets). In the end, ans = number of disjoint nodes (sets)
// *************************************************************************************************************
class Solution {
    int findParent(vector<int>& parentVec, int node)
    {
        // If the node is its own parent, return the node
        if(parentVec[node] == node)
            return node;
        
        // If the node has a different parent than itself, it is part of a union with a differnt parent
        // Recusive call to find the parent. NOTE: Last Node will be its own parent and thus returned.
        return findParent(parentVec, parentVec[node]);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {    
        vector<int> parentVec;
        
        // Every node is its own parent in the beginning
        for(int i = 0; i < n; i++)
            parentVec.push_back(i);
        
        int result = 0;
        
        for(auto& edge : edges)
        {
            int x = findParent(parentVec, edge[0]);
            int y = findParent(parentVec, edge[1]);
            
            // If parents of both nodes are not same, make one parent of other
            // This step is basically union of two sets
            if(x != y)
                parentVec[y] = x;
        }
        
        for(int i = 0; i < n; i++)
        {
            // If the node is its own parent, it is in disjoint set
            if(parentVec[i] == i)
                result++;
        }
        
        return result;
    }
};