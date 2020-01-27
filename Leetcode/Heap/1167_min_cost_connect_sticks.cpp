// You have some sticks with positive integer lengths.
// You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.
// You perform this action until there is one stick remaining.
// Return the minimum cost of connecting all the given sticks into one stick in this way.

// Example 1:
// Input: sticks = [2,4,3]
// Output: 14
// Explanation:
// [2,4,3] : Pick 2 and 3 : Cost = 2 + 3 = 5
// [5, 4] : Pick 5 and 4 : Cost = 5 + 4 = 9
// Total cost = 5 + 9 = 14

// Example 2:
// Input: sticks = [1,8,3,5]
// Output: 30

// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 0)
            return 0;
        
        // Min heap using priority queue. Sum should also be added in a sorted fashion,
        // so that we always pick lowest 2 elements
        priority_queue<int, vector<int>, greater<int>> pq;
        int totalCost = 0;
        
        for(auto s : sticks)
            pq.push(s);
        
        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a+b);
            totalCost += a+b;
        }
        
        return totalCost;
    }
};