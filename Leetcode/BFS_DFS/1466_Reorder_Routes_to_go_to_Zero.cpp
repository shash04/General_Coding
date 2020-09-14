// There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities (this network form a tree).
// Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach the city 0 after reorder.

// Example 1:
// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// Output: 3
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

// Example 2:
// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// Output: 2
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

// Example 3:
// Input: n = 3, connections = [[1,0],[2,0]]
// Output: 0
 
// Constraints:
// 2 <= n <= 5 * 10^4
// connections.length == n-1
// connections[i].length == 2
// 0 <= connections[i][0], connections[i][1] <= n-1
// connections[i][0] != connections[i][1]

// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

// **************************************************************************************************************
// OPTIMIZED SOLUTION
// Why we need to traverse both incoming as well as outgoing edges?
// Ans. 
// We want all edges to come towards 0. Reversing outgoing edges
// from 0 is necessary - you can understand this easily.
// Then you need to recursively orient all outgoing edges from 
// those connected nodes too.
// But why do we need to recursively call dfs() even for incoming
// edges? 
// The answer is, we don't know the orientation of edges that are 
// connected to that neighbor node.
// For example - say 0 has an incoming edge from 1 and 1 has one other
// outgoing edge to 2. i.e. graph is like 0 <-- 1 --> 2.
// Although, you don't need to reverse 0 <-- 1 edge, you still have to 
// make sure that all other edges are coming towards 1. When you call
// dfs with node 1, you will then recognize the incorrect orientation
// of 1 --> 2 edge. This is why traversing incoming edges is important.

// Why do we need to erase edges?
// Ans.
// To avoid double counting. 
// We increment the count everytime we see an outgoing edge. We don't 
// increment for incoming. However, an incoming edge for one node is 
// the outgoing edge for the other.
// In the previous example, 0 <-- 1 --> 2.
// For node 0, we won't increment the count because there are no outgoing
// edges. But when we are at 1, there are two outgoing edges. But 1 --> 0 
// is already oriented towards 0 and we don't want to reverse that. How 
// will we distiguish between correctly oriented edges vs incorrectly 
// oriented ones in general? Easier approach is to remove those correctly 
// oriented edges immediately when we know their orientation is correct.
// **************************************************************************************************************

class Solution {
    unordered_map<int, set<int>> out, in;
    
    void DFS(int currNode, int& minEdgesChanged)
    {
        for(int i : out[currNode])
        {
            minEdgesChanged++;
            
            in[i].erase(currNode);
            
            DFS(i, minEdgesChanged);
        }
        
        for(int i : in[currNode])
        {
            out[i].erase(currNode);
            
            DFS(i, minEdgesChanged);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        if(connections.size() == 0 || connections[0].size() == 0)
            return 0;
        
        int minEdgesChanged = 0;
        
        // Populate outgoing and incoming connections
        for(auto& connection : connections)
        {
            out[connection[0]].insert(connection[1]);
            in[connection[1]].insert(connection[0]);
        }
        
        DFS(0, minEdgesChanged);
        
        return minEdgesChanged;
    }
};

// **************************************************************************************************************
// TIME LIMIT EXCEEDED
// **************************************************************************************************************
class Solution {
    bool DFS(unordered_map<int, vector<int>>& graph, int src, vector<int>& visited)
    {
        if(src == 0)
            return true;
        
        if(visited[src])
            return false;
        
        visited[src]= true;
        
        for(int& dst : graph[src])
        {
            if(DFS(graph, dst, visited))
                return true;
        }
        
        return false;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        if(connections.size() == 0 || connections[0].size() == 0)
            return 0;
        
        int minEdgesChanged = 0;
        
        unordered_map<int, vector<int>> graph;
        
        for(auto& connection : connections)
        {
            graph[connection[0]].push_back(connection[1]);
        }
        
        // all outgoing roads from 0 should be converted to incoming
        for(int j = 0; j < graph[0].size(); j++)
        {
            int dst = graph[0][j];
            int src = 0;
            
            minEdgesChanged++;
            
            graph[dst].push_back(src);
        }
        
        // remove all outward roads from 0th city
        graph[0].clear();
        
        // If DFS from any node has 0 in its path, reverse all other connections
        for(int i = 1; i < n; i++)
        {
            vector<int> visited(n, false);
            
            for(int& neighbor : graph[i])
            {
                if(DFS(graph, neighbor, visited))
                {
                    // Zero found in neighbor's path, reverse all other directions
                    // tmp vec to keep track of all nodes except the one which returned true for DFS
                    vector<int> tmpVec;
                    
                    // reverse the dirs
                    for(int& dst : graph[i])
                    {
                        if(dst == neighbor)
                            continue;

                        minEdgesChanged++;
                        
                        tmpVec.push_back(dst);

                        graph[dst].push_back(i);
                    }
                    
                    // remove the curr node connections
                    for(int& k : tmpVec)
                        graph[i].erase(find(graph[i].begin(), graph[i].end(), k));
                    
                    // break as current node is done
                    break;
                }
            }
        }
        
        return minEdgesChanged;
    }
};