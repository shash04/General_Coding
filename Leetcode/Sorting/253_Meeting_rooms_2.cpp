// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// Example 1:
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2

// Example 2:
// Input: [[7,10],[2,4]]
// Output: 1

// https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(!intervals.size())
            return 0;
        
        map<int, int> m1;
        int roomsRequired = 0;
        int curr_rooms = 0;
        int n = intervals.size();
        
        for(int i=0; i<n; i++)
        {
            m1[intervals[i][0]]++;          // Increment the start time
            m1[intervals[i][1]]--;          // Decrement the end time
        }
        
        for(auto i : m1)                    // As start times are sorted, consecutive starts without end in between would mean rooms++
        {
            curr_rooms += i.second;
            roomsRequired = max(roomsRequired, curr_rooms);
        }
        return roomsRequired;
    }
};