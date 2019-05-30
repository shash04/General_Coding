// Given a collection of intervals, merge all overlapping intervals.

// Example 1:
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// Example 2:
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(!intervals.size())
            return result;
        
        sort(intervals.begin(), intervals.end());                   // Sort the pairs for increasing start times
        int n = intervals.size();
        
        for(int i=0; i<n; i++)
        {
            int curr_start  = intervals[i][0];
            int curr_end    = intervals[i][1];
            while(i+1<n && curr_end >= intervals[i+1][0])           // If next start time <= curr end time = Overlap found
            {
                curr_end = max(curr_end, intervals[i+1][1]);        // Maintain max value for end time
                i++;
            }
            result.push_back({curr_start, curr_end});               // No more overlap found. Add to result vector.
        }
        return result;
    }
};