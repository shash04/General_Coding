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

// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

unordered_set<int> visitedNodes;
vector<int> visitedTime;
vector<int> parent;
vector<int> lowTime;
unordered_map<int, vector<int>> children;
int timer;

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
    
    if((parent[currNode] == -2 && children[currNode].size() >= 2) || (parent[currNode] != -2 && isCurrArticulationPt))
    {
        articulationPts.push_back(currNode);
    }
}

void findAllArticulationPoints(int n, vector<vector<int>> connections, vector<int>& articulationPts, vector<vector<int>>& articulationLinks)
{
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
}

int main() {
	int N, M;
	cin >> N;										    
// 	cout << "Number of Vertices = " << N << endl;		
	cin >> M;										    
// 	cout << "Number of Edges = " << M << endl;
	
	vector<vector<int>> connections;

	for(int i=0; i<M; i++)
	{
	    int a; cin >> a;
	    int b; cin >> b;
	    connections.push_back({a,b});
	}
	
    vector<int> articulationPts;
    vector<vector<int>> articulationLinks;

	findAllArticulationPoints(N, connections, articulationPts, articulationLinks);
	
	//cout<<"All the articulations points and links in the graph/network are = "<<endl;
	
	sort(articulationPts.begin(), articulationPts.end());
	sort(articulationLinks.begin(), articulationLinks.end());
	
	cout<<articulationPts.size()<<endl;
	
	for(auto entry : articulationPts)
	    cout<<entry<<" ";

    cout<<endl;
    
    cout<<articulationLinks.size()<<endl;

    for(auto entry : articulationLinks)
	    cout<<entry[0]<<" "<<entry[1]<<endl;

    return 0;
}
