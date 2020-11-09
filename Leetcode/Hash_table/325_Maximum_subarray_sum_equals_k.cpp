// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

// Note:
// The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

// Example 1:

// Input: nums = [1, -1, 5, -2, 3], k = 3
// Output: 4 
// Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
// Example 2:

// Input: nums = [-2, -1, 2, 1], k = 1
// Output: 2 
// Explanation: The subarray [-1, 2] sums to 1 and is the longest.
// Follow Up:
// Can you do it in O(n) time?

// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

/*
Let's say you've iterated to index 5 (randomly chosen) and your sum from index 0 to 5 so far is 7, and k is 3. sum - k in this case is 4.

What m1.find(sum-k) returns is the index where the sum of every element up to that index from index 0 is sum - k, or (7 - 3) == 4, in our example.
Let's say that that index returned by m1[sum-k] is 2 (randomly chose one that is before index 5).
So knowing that at index 2 the total sum is 4, and at index 5, the total sum is 7,
that means the elements between index 2 and index 5 incremented the total sum by 3, or k!
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // key = sum (index 0 to curr index) ; value = curr index
        unordered_map<int, int> m1;
        int sum = 0;
        int maxLen = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum == k)
                maxLen = i+1;
            
            // if sum not found before, add to map
            if(m1.find(sum) == m1.end())
                m1[sum] = i;
            
            // if sum-k found before - sum between prev index and curr index is k
            // take diff of curr index and prev index and compare with maxLen
            if(m1.find(sum-k) != m1.end())
                maxLen = max(maxLen, i - m1[sum-k]);
        }
        
        return maxLen;
    }
};