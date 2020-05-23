// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
// The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.
// For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

// Example 1:
// Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 
// Note:
// 0 <= A.length < 1000
// 0 <= B.length < 1000
// 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

// https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> retVec;
        
        int aPtr = 0;
        int bPtr = 0;
        
        while(aPtr < A.size() && bPtr < B.size())
        {
            // Get max of start time and min of end time
            int currStart = max(A[aPtr][0], B[bPtr][0]);
            int currEnd = min(A[aPtr][1], B[bPtr][1]);
            
            // If it is a valid interval, add it to retVec
            if(currStart <= currEnd)
                retVec.push_back({currStart, currEnd});
            
            // Increment ptr for arr whose end time was used
            if(currEnd == A[aPtr][1])
                aPtr++;
            else
                bPtr++;
        }
        
        return retVec;
    }
};