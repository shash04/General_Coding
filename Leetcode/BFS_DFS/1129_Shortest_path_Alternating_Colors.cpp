// Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or blue,
// and there could be self-edges or parallel edges.
// Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j] in blue_edges
// denotes a blue directed edge from node i to node j.
// Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X
// such that the edge colors alternate along the path (or -1 if such a path doesn't exist).

// Example 1:
// Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
// Output: [0,1,-1]

// Example 2:
// Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
// Output: [0,1,-1]

// Example 3:
// Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
// Output: [0,-1,-1]

// Example 4:
// Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
// Output: [0,1,2]

// Example 5:
// Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
// Output: [0,1,1]
 

// Constraints:
// 1 <= n <= 100
// red_edges.length <= 400
// blue_edges.length <= 400
// red_edges[i].length == blue_edges[i].length == 2
// 0 <= red_edges[i][j], blue_edges[i][j] < n

// https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
    vector<vector<int>> redGraph;
    vector<vector<int>> blueGraph;
    
    void BFS(vector<int>& result, int n, bool red)
    {
        vector<bool> visitedRed(n, false);
        vector<bool> visitedBlue(n, false);
        
        int dist = 0;
        
        queue<int> bfsQ;
        bfsQ.push(0);
        
        while(!bfsQ.empty())
        {
            int qSize = bfsQ.size();
            
            while(qSize--)
            {
                int curNode = bfsQ.front();
                bfsQ.pop();
                
                result[curNode] = min(result[curNode], dist);
                
                if(red)
                {
                    visitedRed[curNode] = true;
                    
                    for(int nextNode : redGraph[curNode])
                    {
                        if(visitedBlue[nextNode])
                            continue;
                        
                        bfsQ.push(nextNode);
                    }
                }
                else
                {
                    visitedBlue[curNode] = true;
                    
                    for(int nextNode : blueGraph[curNode])
                    {
                        if(visitedRed[nextNode])
                            continue;
                        
                        bfsQ.push(nextNode);
                    }
                }
            }
            
            red = !red;
            dist++;
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> result (n, INT_MAX);
        
        redGraph.resize(n);
        blueGraph.resize(n);
        
        for(auto& entry : red_edges)
        {
            redGraph[entry[0]].push_back(entry[1]);
        }
        
        for(auto& entry : blue_edges)
        {
            blueGraph[entry[0]].push_back(entry[1]);
        }
        
        result[0] = 0;
        
        BFS(result, n, true);
        BFS(result, n, false);
        
        for(int i = 0; i < n; i++)
        {
            if(result[i] == INT_MAX)
                result[i] = -1;
        }
        
        return result;
    }
};