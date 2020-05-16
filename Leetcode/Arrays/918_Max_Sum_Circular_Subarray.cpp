// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

// Here, a circular array means the end of the array connects to the beginning of the array.
// (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

// Also, a subarray may only include each element of the fixed buffer A at most once.
// (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)


// Example 1:
// Input: [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3

// Example 2:
// Input: [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

// Example 3:
// Input: [3,-1,2,-1]
// Output: 4
// Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

// Example 4:
// Input: [3,-2,2,-3]
// Output: 3
// Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

// Example 5:
// Input: [-2,-3,-1]
// Output: -1
// Explanation: Subarray [-1] has maximum sum -1
 

// Note:
// -30000 <= A[i] <= 30000
// 1 <= A.length <= 30000

// https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        
        int maxOverall = INT_MIN;
        int minOverall = INT_MAX;

        int maxSoFar = 0;
        int minSoFar = 0;
        
        int totalSum = 0;
        
        // Kadane's algorithm
        // for every element, there are two choices - exclude or include from subarray
        // If excluded, new subarray starts from current element
        // Thus take max of curr element and maxSoFar + currElement for maxOverall
        for(int i=0; i < A.size(); i++)
        {
            totalSum += A[i];
            
            maxSoFar = max(A[i], maxSoFar + A[i]);
            maxOverall = max(maxOverall, maxSoFar);
            
            minSoFar = min(A[i], minSoFar + A[i]);
            minOverall = min(minOverall, minSoFar);
            
        }
        
        // If maxOverall is > 0, take max of maxOverall (max sum in normal array)
        // and total - minOverall (max Sum in circular array)
        if(maxOverall > 0)
            return max(maxOverall, totalSum - minOverall);
        
        // if maxOverall <= 0, All elements are negative (non-positive)
        return maxOverall;
    }
};