// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input:nums = [1,2,3,4,1,4], k = 5
// Output: 3

// Example 2:
// Input:nums = [-1,-1,1], k = 0
// Output: 1

// https://leetcode.com/problems/subarray-sum-equals-k/

// Logic: if sum[i] - sum[j] == 0, that means  sum of elements between i & j is 0.
// Similartly if sum[i] - sum[j] == k, that means sum of elements between i & j == k
// Create a hash map in the form (sum till index i, number of occurences of that sum)
// For every index increment sum. Check if hash_map[sum-k] exists.
//      If yes = count += no of occurences of (sum-k).
//      If No = add hash map entry
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        int sum = 0;
        int count = 0;
        
        hash_map[sum] = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(hash_map.find(sum - k) != hash_map.end())
                count += hash_map[sum - k];
            hash_map[sum]++;
        }
        return count;
    }
};