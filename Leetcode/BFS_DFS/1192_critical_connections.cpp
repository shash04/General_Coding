// There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where
// connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server
// directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some server unable to reach some other server.
// Return all critical connections in the network in any order.

// Example 1:
// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// Constraints:
// 1 <= n <= 10^5
// n-1 <= connections.length <= 10^5
// connections[i][0] != connections[i][1]
// There are no repeated connections.

// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    
    unordered_set<int> visitedNodes;
    vector<int> visitedTime;
    vector<int> parent;
    vector<int> lowTime;
    unordered_map<int, vector<int>> children;
    int timer;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(n == 0 || connections.size() == 0)
            return connections;
        
        vector<int> articulationPts;
        vector<vector<int>> articulationLinks;
        
        // Map for populating all connections
        unordered_map<int, vector<int>> conMap;

        for(auto entry : connections)
        {
           conMap[entry[0]].push_back(entry[1]);
           conMap[entry[1]].push_back(entry[0]);
        }

        visitedTime = vector<int> (n);
        parent = vector<int> (n, -2);
        lowTime = vector<int> (n);
        timer = 0;

        DFS(conMap, 0, articulationPts, articulationLinks);
        
        return articulationLinks;
    }
    
    void DFS(unordered_map<int, vector<int>>& conMap,
        int currNode,
        vector<int>& articulationPts,
        vector<vector<int>>& articulationLinks)
    {
        visitedNodes.insert(currNode);
        visitedTime[currNode] = timer;
        lowTime[currNode] = timer;
        timer++;
        bool isCurrArticulationPt = false;

        // Loop over all adjacent nodes for curr node
        for(auto adj : conMap[currNode])
        {
            // Continue if adjcent is parent
            if(parent[currNode] == adj)
                continue;

            // if adj node is not yet visited, DFS on it
            if(visitedNodes.count(adj) == 0)
            {
                parent[adj] = currNode;
                children[currNode].push_back(adj);

                DFS(conMap, adj, articulationPts, articulationLinks);

                if(visitedTime[currNode] <= lowTime[adj])
                {
                    isCurrArticulationPt = true;

                    // If currNode is parent of adj and is the source of low time
                    if((visitedTime[currNode] < lowTime[adj]) && (parent[adj] == currNode))
                    {
                        articulationLinks.push_back({currNode, adj});
                    }
                }
                else
                {
                    lowTime[currNode] = min(lowTime[currNode], lowTime[adj]);
                }
            }
            // adj node is already visited. Update low time if possible => indicates another back edge present
            else
            {
                lowTime[currNode] = min(lowTime[currNode], lowTime[adj]);
            }
        }

        if((parent[currNode] == -2 && children[currNode].size() >= 2) ||
            (parent[currNode] != -2 && isCurrArticulationPt))
        {
            articulationPts.push_back(currNode);
        }
    }
};


