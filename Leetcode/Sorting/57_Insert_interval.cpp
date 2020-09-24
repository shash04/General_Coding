// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// https://leetcode.com/explore/interview/card/google/63/sorting-and-searching-4/445/

// ************************************************************************************************************
// Complexity - O(N)
// ************************************************************************************************************
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> result;
        
        if(intervals.size() == 0)
            return {newInterval};
        
        if(newInterval.size() == 0)
            return intervals;
        
        int start = newInterval[0];
        int end = newInterval[1];
        
        int idx = 0;
            
        // idx++ till start time of interval to be inserted is greater than end times
        while(idx < intervals.size() && start > intervals[idx][1])
            result.push_back(intervals[idx++]);
        
        if(idx == intervals.size())
        {
            result.push_back(newInterval);
            return result;
        }

        while(idx < intervals.size() && intervals[idx][0] <= end)
        {
            start   = min(start, intervals[idx][0]);
            end     = max(end, intervals[idx][1]);
            idx++;
        }

        // newE = max(newE, intervals[idx-1][1]);

        result.push_back({start, end});
        
        while(idx < intervals.size())
            result.push_back(intervals[idx++]);
        
        return result;
    }
};

// ************************************************************************************************************
// Concept - insert newInterval and sort and merge - complexity - Nlog(N)
// ************************************************************************************************************
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());                   // Sort the pairs for increasing start times
        int n = intervals.size();
        
        if(n == 0)
            return result;
        
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
