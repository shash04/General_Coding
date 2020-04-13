// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Note: The length of the given binary array will not exceed 50,000.

// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // key = sum (index 0 to curr index) ; value = curr index
        unordered_map<int, int> m1;
        int sum = 0;
        int maxLen = 0;
        
        for(int i=0; i < nums.size(); i++)
        {
            // Treat 1 as 1 and 0 as -1
            if(nums[i] == 1)
                sum++;
            else
                sum--;
            
            // If current sum is zero, 
            if(sum == 0)
                maxLen = i + 1;
            
            // if sum not found before, add to map
            // if sum found before - sum between prev index and curr index is zero
            // take diff of curr index and prev index and compare with maxLen
            if(m1.find(sum) == m1.end())
                m1[sum] = i;
            else
                maxLen = max(maxLen, i - m1[sum]);
        }
        
        return maxLen;
    }
};