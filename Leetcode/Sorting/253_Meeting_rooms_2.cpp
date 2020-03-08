// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// Example 1:
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2

// Example 2:
// Input: [[7,10],[2,4]]
// Output: 1

// https://leetcode.com/problems/meeting-rooms-ii/

// **************************************************************************
// Ordered Map solution
// **************************************************************************

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(!intervals.size())
            return 0;
        
        map<int, int> m1;                   // map needs to be ordered. Can't use unordered_map
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


// **************************************************************************
// Min heap solution using priority queue - slightly faster
// **************************************************************************
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        if(intervals.size() < 2)
            return 1;
        
        int count = 1;
        
        // sort intervals according to start times
        sort(intervals.begin(), intervals.end());
        
        // min heap to keep track of lowest end time
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(intervals[0][1]);
        
        for(int i=1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < pq.top())              // if start time < current lowest end time = rooms++
                count++;
            else
                pq.pop();                               // start time >= lowest end time = remove lowest end time = re-use room
            
            pq.push(intervals[i][1]);                   // Add end time to min heap pq
        }
        
        return count;
    }
};
