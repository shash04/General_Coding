// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// Example 1:
// Input: [[0,30],[5,10],[15,20]]
// Output: false

// Example 2:
// Input: [[7,10],[2,4]]
// Output: true

// https://leetcode.com/problems/meeting-rooms/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(!intervals.size())
            return true;
        
        sort(intervals.begin(), intervals.end(), compare);      // Sort intervals according to start time for every entry
        int n = intervals.size();
        
        for(int i=0; i<n; i++)
        {
            if(i+1<n && intervals[i][1] > intervals[i+1][0])    // Overlap found
                return false;
        }
        return true;
    }
    
    static bool compare(vector<int>& a, vector<int>& b)         // static function as called without object
    {
        return a[0] < b[0];
    }
};