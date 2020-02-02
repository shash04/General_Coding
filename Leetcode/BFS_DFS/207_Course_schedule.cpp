// There are a total of n courses you have to take, labeled from 0 to n-1.
// Some courses may have prerequisites, for e.g to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:
// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
// You may assume that there are no duplicate edges in the input prerequisites.

// https://leetcode.com/problems/course-schedule/

// *******************************************************************************************
// Concept : Populate adj list which has courses that could be done once key is done
// Keep track of pre req course num required for each course
// if pre req num is zero => that course can be done. Add to queue for bfs.
// *******************************************************************************************
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0 || prerequisites.size() == 0)
            return true;
        
        // graph contains key = pre req course ; val = vector of courses that could be done once key is done.
        // preNum maintains number of preReq courses left to do.
        // n keeps track of how many courses are done. Used in the end to check if all done.
        vector<vector<int>> graph (numCourses, vector<int>());
        vector<int> preNum (numCourses, 0);
        int n = numCourses;
        
        for(auto entry : prerequisites)
        {
            graph[entry[1]].push_back(entry[0]);
            preNum[entry[0]]++;
        }
        
        queue<int> q1;
        
        for(int i=0; i < numCourses; i++)
        {
            if(preNum[i] == 0)
                q1.push(i);
        }
        
        while(!q1.empty())
        {
            int curr = q1.front();
            q1.pop();
            n--;
            for(auto next : graph[curr])
            {
                preNum[next]--;
                if(preNum[next] == 0)
                    q1.push(next);
            }
        }
        
        return n == 0;
    }
};

// *******************************************************************************************
// Time Limit Exceeded
// *******************************************************************************************
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0 || prerequisites.size() == 0)
            return true;
        
        unordered_map<int, unordered_set<int>> graph;
        for(auto entry : prerequisites)
        {
            graph[entry[0]].insert(entry[1]);
        }
        
        vector<bool> visited (numCourses, false);
        vector<bool> visiting (numCourses, false);
        
        for(auto v : graph)
        {
            if(hasCycle(v.first , graph, visiting, visited))
                return false;
        }
        
        return true;
    }
    
    bool hasCycle(int v, unordered_map<int, unordered_set<int>> graph, vector<bool>& visiting, vector<bool>& visited)
    {
        if(visited[v])
            return false;
        
        // Current vertex is marked as visiting
        visiting[v] = true;
        
        // Explore all children for current vertex
        for(auto nextV : graph[v])
        {
            // Cycle found
            if(visiting[nextV])
                return true;
            
            if(hasCycle(nextV, graph, visiting, visited))
                return true;
        }
        
        visiting[v] = false;
        visited[v] = true;
        
        return false;
    }
};