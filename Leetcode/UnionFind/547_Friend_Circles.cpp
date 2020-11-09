// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
// For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
// And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class.
// If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
// And you have to output the total number of friend circles among all the students.

// Example 1:
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.

// Example 2:
// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
// so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

// Constraints:
// 1 <= N <= 200
// M[i][i] == 1
// M[i][j] == M[j][i]

// https://leetcode.com/problems/friend-circles/

class Solution {
    int N;
    
    int findParent(const vector<int>& parentVec, int node)
    {
        if(parentVec[node] == node)
            return node;
        
        return findParent(parentVec, parentVec[node]);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0 || M[0].size() == 0)
            return 0;
        
        int friendCircles = 0;
        
        // Matrix is always N x N as every row represents edge (friendship) with other N students
        N = M.size();
        
        // Every node is its own parent = every student is own's friend
        vector<int> parentVec (N, 0);
        
        for(int i = 0; i < N; i++)
        {
            parentVec[i] = i;
        }
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(M[i][j] == 1)
                {
                    // Check if both the students have same parent (belong to same friend circle)
                    int x = findParent(parentVec, i);
                    int y = findParent(parentVec, j);
                    
                    // If not and as they are friends, make one parent of other = add to friend circle
                    if(x != y)
                        parentVec[y] = x;
                }
            }
        }
        
        // Nodes with parent of their own belong to different friend circle
        for(int i = 0; i < N; i++)
        {
            if(parentVec[i] == i)
                friendCircles++;
        }
        
        return friendCircles;
    }
};