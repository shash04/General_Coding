// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the
// intervals non-overlapping.

// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

// Example 1:
// Input: [ [1,2], [2,3], [3,4], [1,3] ]
// Output: 1
// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

// Example 2:
// Input: [ [1,2], [1,2], [1,2] ]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

// Example 3:
// Input: [ [1,2], [2,3] ]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// https://leetcode.com/problems/non-overlapping-intervals/

// Logic: Greedy Algorithm = Determine the maximum number of non-overlapping intervals
// Min number of overlapping intervals to remove = Total size - max num of non overlapping intervals
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(!intervals.size())
            return 0;

        sort(intervals.begin(), intervals.end(), compareEndTimes);  // Sort the pairs for increasing *END* times
        int n = intervals.size();
        int nonOverlapCount = 1;
        int curr_end = intervals[0][1];
        
        for(int i=1; i<n; i++)
        {
            if(curr_end <= intervals[i][0])                 // No overlap
            {
                nonOverlapCount++;                          // Increment non overlapping counter
                curr_end = intervals[i][1];                 // Update current end time only for compatible intervals
            }
        }
        
        return n - nonOverlapCount;
    }
    
    static bool compareEndTimes(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
};
