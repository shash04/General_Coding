// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// Your algorithm should run in O(n) complexity.

// Example:
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int ret = 0;
        for(auto i : nums)
        {
            if(numSet.find(i) == numSet.end())
                continue;
            numSet.erase(i);
            int prev = i-1;
            int next = i+1;
            while(numSet.find(prev) != numSet.end())
                numSet.erase(prev--);
            while(numSet.find(next) != numSet.end())
                numSet.erase(next++);
            ret = max(ret, next - prev - 1);
        }
        return ret;
    }
};