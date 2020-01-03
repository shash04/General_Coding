// Given a non-empty array containing only positive integers, find if the array can be partitioned into
// two subsets such that the sum of elements in both subsets is equal.
// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.

// Example 1:
// Input: [1, 5, 11, 5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:
// Input: [1, 2, 3, 5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// https://leetcode.com/problems/partition-equal-subset-sum/

// Concpet: Knapsack 0/1 problem. We either select the num or don't select

// Solution 1 - optimized fast - 1D array approach
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for (int num : nums)
            sum += num;

        if (sum % 2)
            return false;
            
        sum /= 2;
        
        vector<bool> T(sum+1, false);
        T[0] = true;
              
        for( auto num : nums )
        {
            for(int i=sum; i>=num; i--)
            {
                T[i] = T[i] || T[i-num];
            }
        }
        
        return T[sum];
    }
};


// Solution 2 - slow - 2D array approach

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
    
        for (int num : nums)
            sum += num;

        // If the sum is odd, return false
        if (sum % 2)
            return false;
            
        sum /= 2;
        
        vector<vector<bool>> T(n+1, vector<bool> (sum+1, false));
        
        T[0][0] = true;
        
        for(int i=1; i<n+1; i++)
            T[i][0] = true;
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                T[i][j] = T[i-1][j];
                if(j >= nums[i-1])
                {
                    T[i][j] = T[i-1][j-nums[i-1]] || T[i][j];
                }
            }
        }
        
        return T[n][sum];
    }
};