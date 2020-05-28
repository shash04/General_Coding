// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
// calculate the number of 1's in their binary representation and return them as an array.

// Example 1:
// Input: 2
// Output: [0,1,1]

// Example 2:
// Input: 5
// Output: [0,1,1,2,1,2]

// Follow up:
// It is very easy to come up with a solution with run time O(n*sizeof(integer)).
// But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

// https://leetcode.com/problems/counting-bits/

// ***********************************************************************************
// update dp vec by getting the number of bits in num >> 1 and
// checking if the last bit was 1 or 0
// Time complexity = 0(N)
// ***********************************************************************************
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp (num + 1, 0);
        
        // Concept : update dp vec by getting the number of bits in num >> 1 and
        // checking if the last bit was 1 or 0
        for(int i=1; i <= num; i++)
        {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};

// ***********************************************************************************
// Use function to count set bits for every num
// Time complexity = 0(N * K) where K = set bits
// ***********************************************************************************

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> retVec (num+1, 0);
        
        for(int i=0; i <= num; i++)
        {
            retVec[i] = countSetBits(i);
        }
        
        return retVec;
    }
    
    int countSetBits(int n)
    {
        int count = 0;
        while(n)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
