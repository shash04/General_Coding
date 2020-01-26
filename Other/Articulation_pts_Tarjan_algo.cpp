// Given an undirected graph containing N vertices and M edges, find all the articulation points and all the bridges in the graph.

// Input:
// First line consists of two space separated integers denoting N and M. M lines follow,
// each containing two space separated integers X and Y denoting there is an edge between X and Y.

// Output:
// If the number of articulation points in the graph is p and that of bridges is q , then print as shown below:
// p
// p space separated integers, the articulation points, sorted in increasing order
// q
// q lines, each containing two space separated integers, the bridges in the graph.

// For a bridge u-v, print u first if u < v,otherwise print v first.
// Print all the bridges in increasing order of first vertex, and if first vertex is same, then in increasing order of second vertex.

// Constraints:
// 1 ≤ N, M ≤ 10
// 0 ≤ X, Y ≤ N-1

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void DFS(unordered_map<int, vector<int>>& conMap,
    int& timer,
    int currNode,
    unordered_set<int>& visitedNodes,
    vector<int>& visitedTime,
    vector<int>& parent,
    vector<int>& lowTime,
    vector<int>& childCnt,
    vector<int>& articulationPts)
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
            childCnt[currNode]++;
            
            DFS(conMap, timer, adj, visitedNodes, visitedTime, parent, lowTime, childCnt, articulationPts);
            
            if(visitedTime[currNode] <= lowTime[adj])
            {
                isCurrArticulationPt = true;
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
    
    if((parent[currNode] == -2 && childCnt[currNode] >= 2) || (parent[currNode] != -2 && isCurrArticulationPt))
    {
        articulationPts.push_back(currNode);
    }
}

vector<int> findAllArticulationPoints(int n, vector<vector<int>> connections)
{
    // Map for populating all connections
	unordered_map<int, vector<int>> conMap;
	
	for(auto entry : connections)
    {
       conMap[entry[0]].push_back(entry[1]);
       conMap[entry[1]].push_back(entry[0]);
    }
	    
    unordered_set<int> visitedNodes;
    vector<int> visitedTime (n);
    vector<int> parent (n, -2);
    vector<int> lowTime (n);
    vector<int> childCnt (n, 0);
    int timer = 0;
    
    vector<int> articulationPts;
    
    DFS(conMap, timer, 0, visitedNodes, visitedTime, parent, lowTime, childCnt, articulationPts);
    
    return articulationPts;
}

int main() {
	int N, M;
	cin >> N;										    
	cout << "Number of Vertices = " << N << endl;		
	cin >> M;										    
	cout << "Number of Edges = " << M << endl;
	
	vector<vector<int>> connections;

	for(int i=0; i<M; i++)
	{
	    int a; cin >> a;
	    int b; cin >> b;
	    connections.push_back({a,b});
	}
	
	vector<int> ans = findAllArticulationPoints(N, connections);
	
	cout<<"All the articulations points in the graph/network are = "<<endl;
	
	for(auto entry : ans)
	    cout<<entry<<" ";
	    
    cout<<endl;

    return 0;
}
