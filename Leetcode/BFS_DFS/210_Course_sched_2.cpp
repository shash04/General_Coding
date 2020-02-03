// There are a total of n courses you have to take, labeled from 0 to n-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// Example 1:
// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .

// Example 2:
// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.

// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        // Graph with key = course and val = all pre req courses
        for(auto entry: prerequisites)
        {
            graph[entry[0]].push_back(entry[1]);
        }
        
        vector<int> retVec;
        
        // visit status : 0 = not visited ; 1 = visiting ; 2 = visited
        vector<int> visitStatus (numCourses,0);
        
        for(int i=0; i < numCourses; i++)
        {
            if(!canFinish(graph, visitStatus, i, retVec))
                return {};
        }
        
        // Add courses without any dependencies
        for(int i=0; i < numCourses; i++)
        {
            if(!visitStatus[i])
                retVec.push_back(i);
        }
        
        return retVec;
    }
    
    bool canFinish(vector<vector<int>>& graph, vector<int>& visitStatus, int v, vector<int>& retVec)
    {
        // If completely visited
        if(visitStatus[v] == 2)
            return true;
        
        // Explore all pre requisite courses for current course
        for(auto i : graph[v])
        {
            if(visitStatus[i] == 1)
                return false;
            
            if(visitStatus[i] == 2)
                continue;
            
            visitStatus[i] = 1;
            
            if(!canFinish(graph, visitStatus, i, retVec))
                return false;
            
            if(visitStatus[i] == 1)
                visitStatus[i] = 0;
        }
        
        visitStatus[v] = 2;
        retVec.push_back(v);
        return true;
    }
};