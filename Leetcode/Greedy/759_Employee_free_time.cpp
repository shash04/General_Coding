// We are given a list schedule of employees, which represents the working time for each employee.

// Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

// Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

// (Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays.
// For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).
// Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.


// Example 1:
// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
// Output: [[3,4]]
// Explanation: There are a total of three employees, and all common
// free time intervals would be [-inf, 1], [3, 4], [10, inf].
// We discard any intervals that contain inf as they aren't finite.

// Example 2:
// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
// Output: [[5,6],[7,9]]
 

// Constraints:
// 1 <= schedule.length , schedule[i].length <= 50
// 0 <= schedule[i].start < schedule[i].end <= 10^8

// https://leetcode.com/problems/employee-free-time/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

/*
- start with an Interval vector
- iterate over all employee schedules and add to that Interval vector
- Sort (according to start time) and Merge the overlapping intervals in the common vector and return a new vector
- result = time gaps in Interval vector returned in earlier step
*/

class Solution {
    static bool mySort(Interval& a, Interval& b)
    {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        
        sort(intervals.begin(), intervals.end(), mySort);
        
        int idx = 0;
        
        while(idx < intervals.size())
        {
            int curStart = intervals[idx].start;
            int curEnd = intervals[idx].end;
            
            while(idx < intervals.size() && curEnd >= intervals[idx].start)
            {
                curEnd = max(curEnd, intervals[idx].end);
                idx++;
            }
            
            result.push_back(Interval(curStart, curEnd));
        }
        
        return result;
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> merged;
        
        vector<Interval> result;
        
        if(schedule.size() == 0 || schedule[0].size() == 0)
            return result;
        
        // Create one list of all intervals
        for(auto& intervalVec : schedule)
        {
            for(auto& interval : intervalVec)
                merged.push_back(interval);
        }
        
        // sort and merge the intervals
        vector<Interval> sortedMerged = merge(merged);
        
        for(int i = 1; i < sortedMerged.size(); i++)
        {
            int freeStart   = sortedMerged[i-1].end;
            int freeEnd     = sortedMerged[i].start;
            
            result.push_back(Interval(freeStart, freeEnd));
        }
        
        return result;
    }
};